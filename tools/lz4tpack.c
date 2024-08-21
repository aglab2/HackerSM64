// Written by aglab2

#define LZ4_HC_STATIC_LINKING_ONLY
#define LZ4_COMMONDEFS_ONLY
#include "lz4hc.h"
#include "lz4.c"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// MARK: Definitions from LZ4HC to LZ4T packer

#define MAX_COMP_SIZE (8*1024*1024)

// #define FAVOR_DECOMPRESSION_SPEED
#define COMPRESSION_LEVEL LZ4HC_CLEVEL_MAX

// #define DEBUG
#ifdef DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

#ifdef LZSO
int LZ4T_distanceMax = 4096;
#else
int LZ4T_distanceMax = 65535;
#endif

#ifdef LZ3
uint32_t LZ4T_hashMask = 0x00ffffffU;
int LZ4T_minMatch = 3;
#else
uint32_t LZ4T_hashMask = 0xffffffffU;
int LZ4T_minMatch = 4;
#endif

#define LZ4T_IS_SHORT_OFFSET (4096 == LZ4T_distanceMax)

static uint32_t* sCurrentNibblePendingOutputPtr = NULL;
static uint32_t sCurrentNibble = 0;
static uint32_t sCurrentNibbleShift = 8;
static uint32_t sNibblesPushed = 0;

static uint16_t* sDeferredNibblePtr = NULL;

#define TINY_LITERAL_LIMIT 21
#define TINY_MINMATCH (MINMATCH - 1)
// 0b0000 and 0b0111 are reserved
#define TINY_MATCH_LIMIT (6 + TINY_MINMATCH)
// 0b0000 and 0b1111 are reserved
#define TINY_MATCH_LIMIT_EX (14 + TINY_MINMATCH)

static void LZ4T_pushNibble(BYTE** _op, uint32_t newNibble)
{
    sNibblesPushed++;
    LOG("%d: Pushing nibble: %x\n", sNibblesPushed, newNibble);

    if (sDeferredNibblePtr)
    {
        LOG("Deferred nibble: %x\n", newNibble);
        uint16_t packedOffset = __builtin_bswap16(*sDeferredNibblePtr);
        packedOffset |= (newNibble << 12);
        *sDeferredNibblePtr = __builtin_bswap16(packedOffset);
        sDeferredNibblePtr = NULL;
        return;
    }

    if (0 == sCurrentNibbleShift)
    {
        LOG("Requesting fresh nibbles\n");
        uint32_t nibbleBE = __builtin_bswap32(sCurrentNibble);
        memcpy(sCurrentNibblePendingOutputPtr, &nibbleBE, 4);
        sCurrentNibblePendingOutputPtr = (uint32_t*)(*_op);
        memset(sCurrentNibblePendingOutputPtr, 0, 4);
        sCurrentNibble = 0;
        sCurrentNibbleShift = 8;
        (*_op) += 4;
    }

    sCurrentNibbleShift--;
    newNibble <<= sCurrentNibbleShift * 4;
    sCurrentNibble |= newNibble;
    LOG("New nibble batch: 0x%x\n", sCurrentNibble);
}

static void LZ4T_encodeBitLen(BYTE** _op, int len)
{
#define op      (*_op)
    if (0 == len)
    {
        *op++ = 0;
        return;
    }

    while (len) {
        if (len <= 127) {
            LOG("Pushing final len: %d\n", len);
            *op++ = len;
        } else {
            LOG("Pushing partial len: %d\n", len & 127);
            *op++ = 128 | (len & 127);
        }
        len >>= 7;
    }
}

int LZ4HC_encodeSequence (
    const BYTE** _ip,
    BYTE** _op,
    const BYTE** _anchor,
    int matchLength,
    int offset,
    limitedOutput_directive,
    BYTE*)
{
#define ip      (*_ip)
#define op      (*_op)
#define anchor  (*_anchor)

    /* Encode Literal length */
    size_t length = (size_t)(ip - anchor);
    LOG("Encoding literals: %d\n", length);
    int tinyMatchLimit = TINY_MATCH_LIMIT;
    if (length > TINY_LITERAL_LIMIT) {
        // means that encoding is extended
        LZ4T_pushNibble(&op, 8);
        LZ4T_encodeBitLen(&op, length - TINY_LITERAL_LIMIT - 1);
        LOG("Copying literals wildly: %p %p %u\n", op, anchor, length);
        LZ4_wildCopy8(op, anchor, op + length);
        op += length;
        tinyMatchLimit = TINY_MATCH_LIMIT_EX;
    } else {
        size_t len = length;
        const void* src = anchor;
        // put raw nibbles
        while (len) {
            LOG("Copying literals sizely: %p %p %u\n", op, anchor, length);
            uint32_t cut = len > 7 ? 7 : len;
            LZ4T_pushNibble(&op, 8 | cut);
            *(uint64_t*) op = *(uint64_t*)src;
            op += cut;
            src += cut;
            len -= cut;
        }

        if ((length % 7) == 0)
            tinyMatchLimit = TINY_MATCH_LIMIT;
        else
            tinyMatchLimit = TINY_MATCH_LIMIT_EX;
    }

    /* Encode Offset */
    LOG("Encoding match with tiny limit %d at offset %d for length %d\n", tinyMatchLimit, offset, matchLength);
    if (matchLength > tinyMatchLimit) {
        // 7 or 15 means that matchLength is extended
        LZ4T_pushNibble(&op, tinyMatchLimit - TINY_MINMATCH + 1);
    } else {
        LZ4T_pushNibble(&op, matchLength - TINY_MINMATCH);
    }
    assert(offset <= LZ4_DISTANCE_MAX );
    assert(offset > 0);
    LZ4_write16(op, __builtin_bswap16((U16)(offset - 1)));
    if (LZ4T_IS_SHORT_OFFSET)
    {
        sDeferredNibblePtr = (uint16_t*)op;
    }
    op += 2;
    LOG("Pushing offset: %d\n", offset);

    /* Encode MatchLength */
    assert(matchLength >= MINMATCH);
    if (matchLength > tinyMatchLimit) {
        LZ4T_encodeBitLen(&op, matchLength - tinyMatchLimit - 1);
    }

    /* Prepare next loop */
    ip += matchLength;
    anchor = ip;

    return 0;

#undef ip
#undef op
#undef anchor
}

int LZ4T_lastLiterals (
    const BYTE** _ip,
    BYTE** _op,
    const BYTE** _anchor,
    limitedOutput_directive limit,
    BYTE* oend,
    size_t length)
{
#define ip      (*_ip)
#define op      (*_op)
#define anchor  (*_anchor)

    if (length)
    {
        LOG("Encoding last literals: %d\n", length);
        if (length > TINY_LITERAL_LIMIT) {
            // means that encoding is extended
            LZ4T_pushNibble(&op, 8);
            LZ4T_encodeBitLen(&op, length - TINY_LITERAL_LIMIT - 1);
            LZ4_wildCopy8(op, anchor, op + length);
            op += length;
        } else {
            size_t len = length;
            const void* src = anchor;
            // put raw nibbles
            while (len) {
                uint32_t cut = len > 7 ? 7 : len;
                LZ4T_pushNibble(&op, 8 | cut);
                *(uint64_t*) op = *(uint64_t*)src;
                op += cut;
                src += cut;
                len -= cut;
            }
        }
    }

    // push ending marker
    uint32_t nibbleBE = __builtin_bswap32(sCurrentNibble);
    memcpy(sCurrentNibblePendingOutputPtr, &nibbleBE, 4);
    sCurrentNibblePendingOutputPtr = (uint32_t*)(*_op);
    memset(sCurrentNibblePendingOutputPtr, 0, 4);
    (*_op) += 4;
    sCurrentNibblePendingOutputPtr = NULL;

    ip = anchor + length;
    return 0;

#undef ip
#undef op
#undef anchor
}

static int LZ4T_bitCodePrice(int len)
{
    if (0 == len)
        return 2;
    
    int price = 0;
    while (len)
    {
        // each ex size byte is 2 nibbles
        price += 2;
        len >>= 7;
    }

    return price;
}

// Counts are in nibbles so 1 byte is 2 nibbles
int LZ4HC_literalsPrice(int const litlen)
{
    int price = litlen * 2;
    assert(litlen >= 0);
    if (litlen > TINY_LITERAL_LIMIT) {
        int len = litlen - TINY_LITERAL_LIMIT - 1;
        // encode 1 nibble for ex size
        price += 1 + LZ4T_bitCodePrice(len);
    } else {
        int len = litlen;
        while (len) {
            // single nibble for short sizes
            int cut = len > 7 ? 7 : len;
            price += 1;
            len -= cut;
        }
    }
    return price;
}

int LZ4HC_sequencePrice(int litlen, int mlen)
{
    int price = 4 ; // 16-bit offset is 4 nibbles
    assert(litlen >= 0);
    assert(mlen >= MINMATCH);

    price += LZ4HC_literalsPrice(litlen);
    // nibble for encoding match is saved because it is rolled from offset in the stream
    if (!LZ4T_IS_SHORT_OFFSET)
    {
        price += 1;
    }
    int tinyMatchLimit = TINY_MATCH_LIMIT_EX;
    if (litlen <= TINY_LITERAL_LIMIT) {
        if ((litlen % 7) == 0)
            tinyMatchLimit = TINY_MATCH_LIMIT;
    }

    if (mlen > tinyMatchLimit) {
        // ex size encoding
        int len = mlen - tinyMatchLimit - 1;
        price += LZ4T_bitCodePrice(len);
    }
    return price;
}

static int LZ4T_unpack_size(const char** _in, int* _giganticCounts)
{
#define in (*_in)
#define giganticCounts (*_giganticCounts)
    int amount = 0;
    int shift = 0;
    int iteration = -1;
    while (1)
    {
        iteration++;
        int8_t next = *(int8_t*) (in++);
        LOG("Next: %d\n", next);
        if (next < 0)
        {
            amount |= (next & 0x7f) << shift;
            shift += 7;
            LOG("New amount: %d\n", amount);
        }
        else
        {
            amount |= (next << shift);
            LOG("Amount is %d\n", amount);
            break;
        }
    }

    giganticCounts += iteration;

    return amount;
#undef giganticCounts
#undef in
}

// MARK: LZ4T Verifier

static char* LZ4T_unpack(const char* in)
{
    const uint32_t* src = (const uint32_t*)in;
    uint32_t magicHeader = __builtin_bswap32(*src++);
    uint32_t srcSize = __builtin_bswap32(*src++);
    uint16_t shortOffsetMask = in[8];
    shortOffsetMask <<= 12;
    int minMatch = in[9];
    int32_t nibbles = 0;
    int nibblesHandled = 0;
    int largeLiteralsCounts = 0;
    int giganticLiteralsCounts = 0;
    int largeMatchesCounts = 0;
    int giganticMatchesCounts = 0;
    int literalsCounts = 0;
    int matchesCounts = 0;
    int exMatchesCounts = 0;
    int exMatchesAfterLimLiterals = 0;

    char* dst = malloc(srcSize + 16);
    in = in + 12;
    char* out = dst;
    while (1)
    {
        if (0 == nibbles)
        {
            nibbles = __builtin_bswap32(*(uint32_t*) in);
            in += 4;
            LOG("Loaded new pack of nibbles: %x\n", nibbles);
            if (!nibbles)
            {
                break;
            }
        }

        int tinyMatchLimit = TINY_MATCH_LIMIT;
        nibblesHandled++;

        // literals
        if (nibbles < 0)
        {
            LOG("%d: Handle literal nibble 0x%x\n", nibblesHandled, ((uint32_t) nibbles) >> 28);
            // literal
            literalsCounts++;
            int amount = 7 & (nibbles >> 28);
            LOG("Amount: %d\n", amount);
            if (amount == 0)
            {
                largeLiteralsCounts++;
                LOG("Amount is 0, unpacking extras\n");
                amount = LZ4T_unpack_size(&in, &giganticLiteralsCounts) + TINY_LITERAL_LIMIT + 1;
                LOG("Copying amount %d via memcpy: %p %p\n", amount, out, in);
                memcpy(out, in, amount);
                out += amount;
                in += amount;
            }
            else
            {
                *(uint64_t*)out = *(uint64_t*)in;
                LOG("Copying amount %d wildly: %p %p\n", amount, out, in);
                out += amount;
                in += amount;
                if (7 == amount)
                {
                    nibbles <<= 4;
                    continue;
                }
                else
                {
                    exMatchesAfterLimLiterals++;
                }
            }

            nibbles <<= 4;
            if (0 == nibbles)
            {
                nibbles = __builtin_bswap32(*(uint32_t*) in);
                in += 4;
                LOG("Loaded new pack of nibbles: %x\n", nibbles);
                if (!nibbles)
                {
                    break;
                }
            }
            nibblesHandled++;
            exMatchesCounts++;
            tinyMatchLimit = TINY_MATCH_LIMIT_EX;
        }

        // matches
        {
            LOG("%d: Handle match nibble 0x%x | 0x%x\n", nibblesHandled, ((uint32_t) nibbles) >> 28, tinyMatchLimit);
            matchesCounts++;
            uint16_t offset = __builtin_bswap16(*(uint16_t*)in);
            in += 2;
            
            uint32_t nibble = 0;
            if (shortOffsetMask)
            {
                nibble = ((uint32_t) (offset & 0xf000)) << 16;
                offset &= 0xfff;
            }
            offset++;

            LOG("Offset: %d, Nibble: 0x%x\n", offset, nibble);
            int amount = minMatch + (((uint32_t) nibbles) >> 28);
            LOG("Amount: %d\n", amount);
            if (amount == tinyMatchLimit + 1)
            {
                LOG("Amount is %d, unpacking extras\n", tinyMatchLimit);
                largeMatchesCounts++;
                amount = LZ4T_unpack_size(&in, &giganticMatchesCounts) + tinyMatchLimit + 1;
            }

            LOG("Copying amount %d: %p %p\n", amount, out, out - offset);
            for (int i = 0; i < amount; i++)
            {
                out[i] = out[i - offset];
            }
            out += amount;

            if (shortOffsetMask)
            {
                LOG("Push in nibble: 0x%x\n", nibble);
                nibbles &= ~0xf0000000;
                nibbles |= nibble;
            }
            else
            {
                nibbles <<= 4;
            }
        }
    }

    printf("Literals: %d (%d large, %d gigantic)\n", literalsCounts, largeLiteralsCounts, giganticLiteralsCounts);
    printf("Matches: %d (%d large, %d gigantic)\n", matchesCounts, largeMatchesCounts, giganticMatchesCounts);
    printf("Ex matches: %d (%d after !7)\n", exMatchesCounts, exMatchesAfterLimLiterals);

    return dst;
}

// MARK: Tools to work with files and output blocks

static void saveBufferToFile(const char* buffer, size_t size, const char* filename)
{
    FILE* out = fopen(filename, "wb");
    if (out == NULL)
    {
        printf("Cannot create output file '%s'!\n", filename);
        abort();
    }

    fwrite(buffer, size, 1, out);

    fclose(out);
}

static void* readFile(const char* filename, int* psize)
{
    FILE* in = fopen(filename, "rb");
    if (in == NULL)
    {
        printf("Cannot open input file '%s'\n", filename);
        abort();
    }

    fseek(in, 0, SEEK_END);
    int size = ftell(in);
    fseek(in, 0, SEEK_SET);
    char* buffer = malloc(size);
    size_t fread_result = fread(buffer, size, 1, in);
    fclose(in);
    if (1 != fread_result)
    {
        printf("Failed to read input file '%s': %d != %d\n", filename, fread_result, size);
        abort();
    }

    *psize = size;
    return buffer;
}

static void* compress(const char* src, int srcSize, int* pcompSize, uint32_t* pfirstNibble)
{
    uint32_t firstNibble = 0;
    char* dst = malloc(MAX_COMP_SIZE);
    LZ4_streamHC_t* state = LZ4_createStreamHC();
#ifdef FAVOR_DECOMPRESSION_SPEED
    LZ4_favorDecompressionSpeed(state, 1);
#endif
    LZ4_setCompressionLevel(state, COMPRESSION_LEVEL);  
    sCurrentNibblePendingOutputPtr = &firstNibble;
    LOG("src=%p dst=%p srcSize=%u", src, dst, srcSize);
    int compSize = LZ4_compress_HC_continue(state, (char*)src, dst, srcSize, MAX_COMP_SIZE);
    LZ4_freeStreamHC(state);
    if (sCurrentNibblePendingOutputPtr)
    {
        printf("Error: Nibble output pointer is not NULL after compression\n");
        abort();
    }
    if (0 == compSize)
    {
        printf("Compression failed!\n");
        abort();
    }

#if 0
    char* buf = malloc(8 * 1024 * 1024);
    patch_lz4_block(dst, compSize, buf, 8 * 1024 * 1024);
    free(buf);
#endif

    *pcompSize = compSize;
    *pfirstNibble = firstNibble;
    return dst;
}

static void saveCompressedBufferToFile(const char* dst, int compSize, int srcSize, uint8_t shortOffsetMode, uint8_t minMatch, uint32_t firstNibble, const char* filename)
{
    FILE* out = fopen(filename, "wb");
    if (out == NULL)
    {
        printf("Cannot create output file '%s'!\n", filename);
        abort();
    }

    uint32_t srcSizeBE = __builtin_bswap32(srcSize);
    uint32_t magicHeader = 'LZ4T';
    uint16_t stub = 0;

    fwrite(&magicHeader     , 1, sizeof(magicHeader)    , out);
    fwrite(&srcSizeBE       , 1, sizeof(srcSizeBE)      , out);
    fwrite(&shortOffsetMode , 1, sizeof(shortOffsetMode), out);
    fwrite(&minMatch        , 1, sizeof(minMatch)       , out);
    fwrite(&stub            , 1, sizeof(stub)           , out);
    fwrite(&firstNibble     , 1, sizeof(firstNibble)    , out);

    fwrite(dst, compSize, 1, out);

    fclose(out);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s [SRC_PATH] [DST_PATH]\n", argv[0]);
        return -1;
    }

    // Compression
    int srcSize;
    char* src = (char*) readFile(argv[1], &srcSize);

    int dstSize;
    uint32_t firstNibble;
    char* dst = compress(src, srcSize, &dstSize, &firstNibble);

    FILE* out = fopen(argv[2], "wb");
    if (out == NULL)
    {
        printf("Cannot create output file!\n");
        return -1;
    }

    saveCompressedBufferToFile(dst, dstSize, srcSize, LZ4T_IS_SHORT_OFFSET ? 0xf : 0, MINMATCH - 1, firstNibble, argv[2]);
    free(dst);

    // Verifier
    {
        int compTestSize;
        char* compTest = (char*) readFile(argv[2], &compTestSize);
        char* dec = LZ4T_unpack(compTest);

        if (0 != memcmp(dec, src, compTestSize))
        {
            printf("Compression failed!\n");
            int i;
            for (i = 0; i < compTestSize; i++)
            {
                if (dec[i] != src[i])
                {
                    printf("Mismatch at %d: %x != %x\n", i, dec[i], src[i]);
                    saveBufferToFile(dec, compTestSize, "dec.bin");
                    break;
                }
            }
            return -1;
        }

        free(dec);
        free(compTest);
    }

    free(src);
    return 0;
}
