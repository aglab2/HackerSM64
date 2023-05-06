#define LZ4_HC_STATIC_LINKING_ONLY
#include "lz4hc.h"

#include <stdlib.h>
#include <stdio.h>

#define MAX_COMP_SIZE (8*1024*1024)

// #define FAVOR_DECOMPRESSION_SPEED
#define COMPRESSION_LEVEL LZ4HC_CLEVEL_MAX

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s [SRC_PATH] [DST_PATH]\n", argv[0]);
        return -1;
    }
    
    FILE *in = fopen(argv[1], "rb");
    if (in == NULL)
    {
        printf("Cannot open input file!\n");
        return -1;
    }
    fseek(in, 0, SEEK_END);
    int srcSize = ftell(in);
    fseek(in, 0, SEEK_SET);
    char* src = malloc(srcSize);
    size_t fread_result = fread(src, srcSize, 1, in);
    fclose(in);

    char* dst = malloc(MAX_COMP_SIZE);
    LZ4_streamHC_t* state = LZ4_createStreamHC();
#ifdef FAVOR_DECOMPRESSION_SPEED
    LZ4_favorDecompressionSpeed(state, 1);
#endif
    int compSize = LZ4_compress_HC_extStateHC(state, src, dst, srcSize, MAX_COMP_SIZE, COMPRESSION_LEVEL);
    if (0 == compSize)
    {
        printf("Compression failed!\n");
        return -1;
    }

    FILE* out = fopen(argv[2], "wb");
    if (out == NULL)
    {
        printf("Cannot create output file!\n");
        return -1;
    }

    uint32_t compSizeBE = __builtin_bswap32(compSize);
    uint32_t srcSizeBE = __builtin_bswap32(srcSize);

    fwrite(&compSizeBE, 1, sizeof(compSizeBE), out);
    fwrite(&srcSizeBE, 1, sizeof(srcSizeBE), out);
    fwrite(dst, compSize, 1, out);
    fclose(out);

    LZ4_freeStreamHC(state);
    free(src);
    free(dst);

    return 0;
}
