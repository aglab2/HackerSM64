#define inbuf       $s0
#define outbuf      $s2
#define nlit        $s3
#define cc          $s4
#define cc_count    $s5
#define match_off   $s6
#define match_len   $s7
#define v0_st       $s8

#define dma_ctx     $s1
#define dma_ptr     $v0

# Read one bit from CC, and jump to target if it matches
# the specified value
.macro cc_check value, target
    bltzal cc_count, .Lreadcc
     addiu cc_count, -1
    .if \value != 0
        bltz cc, \target
    .else
        bgez cc, \target
    .endif
    sll cc, 1
.endm

# Peek one bit from CC, and run next opcode if it matches
# the specified value. The bit is not removed from CC.
.macro cc_peek value
    bltzal cc_count, .Lreadcc
     addiu cc_count, -1
    .if \value != 0
        bltzl cc, 1f
    .else
        bgezl cc, 1f
    .endif
1:
.endm

    .section .text.decompress_aplib_full_fast
	.p2align 5
    .globl decompress_aplib_full_fast 
    .func decompress_aplib_full_fast
    .set at
    .set noreorder

decompress_aplib_full_fast:
    addiu $sp, $sp, -0x40
    sw $ra, 0x14($sp)
    sw $s0, 0x18($sp)
    sw $s1, 0x1c($sp)
    sw $s2, 0x20($sp)
    sw $s3, 0x24($sp)
    sw $s4, 0x28($sp)
    sw $s5, 0x2C($sp)
    sw $s6, 0x30($sp)
    sw $s7, 0x34($sp)
    sw $s8, 0x38($sp)
    
    move $s0, $a0
    move $s2, $a2
    move dma_ctx, $a3

    bal .Lwaitdma
     li dma_ptr, 0
    b .Lcmd_literal
     li cc_count, -1

    # Main copy-match loop. This is the basic LZ constrcut, where
    # we copy match_len bytes from match_off bytes before the current
    # outbuf pointer. Notice that match_off can be less than match_len
    # in which case it is mandatory to copy byte by byte for correct
    # behavior (memmove() vs memcpy()).
    # We implement 3 different loops for optimization purposes:
    #  - 1-byte copy loop: copy 1 byte at a time
    #  - 8-byte copy loop: copy 8 bytes at a time
    #  - memset loop: read one 1 byte (match_off=1), memset 8 bytes at a time
    # To make the second and third loop more generally useful, we
    # allow the code to write past the end of the output buffer (up to 8 bytes).
.Lmatch:
    blt match_off, match_len, .Lmatch1_loop_check
     sub v0_st, outbuf, match_off
.Lmatch8_loop:                                  # 8-byte copy loop
    ldl $t0, 0(v0_st)                             # load 8 bytes
    ldr $t0, 7(v0_st)
    addiu v0_st, 8
    sdl $t0, 0(outbuf)                          # store 8 bytes
    sdr $t0, 7(outbuf)
    addiu match_len, -8
    bgtz match_len, .Lmatch8_loop               # check we went past match_len
     addiu outbuf, 8
    b .Lloop_lit2                               # jump to main loop
     addu outbuf, match_len                     # adjust pointer remove extra bytes

.Lmatch1_memset:                                # prepare memset loop (value in t0)
    dsll $t1, $t0, 8                            # duplicate the LSB into all bytes
    or $t0, $t1
    dsll $t1, $t0, 16
    or $t0, $t1
    dsll $t1, $t0, 32
    or $t0, $t1
.Lmatch1_memset_loop:                           # memset loop
    sdl $t0, 0(outbuf)                          # store 8 bytes
    sdr $t0, 7(outbuf)                           
    addiu match_len, -8                         # adjust match_len
    bgtz match_len, .Lmatch1_memset_loop        # check we went past match_len
     addiu outbuf, 8
    b .Lloop_lit2                               # jump to main loop
     addu outbuf, match_len                     # adjust pointer remove extra bytes

.Lmatch1_loop_check:                            # 1-byte copy loop
    beq match_off, 1, .Lmatch1_memset
.Lmatch1_loop:                                  # 1-byte copy loop
    lbu $t0, 0(v0_st)                             # load 1 byte
    addiu v0_st, 1
    sb $t0, 0(outbuf)                           # store 1 byte
    addiu match_len, -1
    bgtz match_len, .Lmatch1_loop               # check we went past match_len
     addiu outbuf, 1


    # Aplib main loop. This is the main loop of the decompressor.
    # We pattern-match the bits in CC to determine the command.
.Lloop_lit2:
    li nlit, 2
.Lloop:                                         # main loop
    #tne ra, ra, 0x10
    sub $t0, inbuf, dma_ptr                     # check if we need to wait for dma
    bgezal $t0, .Lwaitdma                       # if inbuf >= dma_ptr, wait for dma
     nop
    cc_check 0, .Lcmd_literal                   # 0xx => literal
    cc_check 0, .Lcmd_offset8                   # 10x => offset 8
    cc_check 0, .Lcmd_offset7                   # 110 => offset 7
.Lcmd_offset4:                                  # 111 => offset 4
    li nlit, 3
    li v0_st, 0

    cc_peek 1                                   # if next CC bit is 1
     ori v0_st, 0x8                               #  set bit 0x8 in v0
    sll cc, 1                                   # shift CC
    cc_peek 1                                   # if next CC bit is 1
     ori v0_st, 0x4                               #  set bit 0x4 in v0
    sll cc, 1                                   # shift CC
    cc_peek 1                                   # if next CC bit is 1
     ori v0_st, 0x2                               #  set bit 0x2 in v0
    sll cc, 1                                   # shift CC
    cc_peek 1                                   # if next CC bit is 1
     ori v0_st, 0x1                               #  set bit 0x1 in v0
    sll cc, 1                                   # shift CC

    beqz v0_st, .Loutz                            # if v0 == 0, store zero into outbuf
     li $t0, 0
    sub v0_st, outbuf, v0_st                        # else v0 is the match offset
    lbu $t0, 0(v0_st)                             # load byte from match offset
.Loutz:
    sb $t0, 0(outbuf)                           # store byte
    b .Lloop                                    # back to main loop
     addiu outbuf, 1

.Lcmd_literal:                                  # literal command
    lbu $t0, 0(inbuf)                           # load byte from inbuf
    addiu inbuf, 1
    sb $t0, 0(outbuf)                            # store byte
    addiu outbuf, 1
    b .Lloop                                    # back to main loop
     li nlit, 3

.Lcmd_offset7:                                  # offset 7 command
    lbu $t0, 0(inbuf)                           # load byte from inbuf
    addiu inbuf, 1
    beqz $t0, .Ldone                            # if byte == 0, we're done
     srl match_off, $t0, 1                      # match_offset is bits 1..7
    andi $t0, 1                                 # match_len is 2 + bit 0
    sub v0_st, outbuf, match_off                  # compute match pointer
    lbu $t1, 0(v0_st)                             # load byte from match pointer
    addiu outbuf, 2
    sb $t1, -2(outbuf)                          # store byte
    lbu $t1, 1(v0_st)                             # load byte from match pointer + 1
    beqz $t0, .Lloop_lit2                       # if match_len == 2, back to main loop
     sb $t1, -1(outbuf)                         # store byte
    lbu $t1, 2(v0_st)                             # load byte from match pointer + 2
    addiu outbuf, 1
    b .Lloop_lit2                               # back to main loop
     sb $t1, -1(outbuf)                         # store byte

.Lcmd_offset8:                                  # offset 8 command
    #tne ra, ra, 0x10
    bal .Lreadgamma                             # read gamma-encoded value
     nop
    sub v0_st, nlit                               # if value-nlit < 0, it's a repmatch
    bltz v0_st, .Lrepmatch                        # so jump to repmatch code
     nop
    sll match_off, v0_st, 8                       # else, it is the MSB of match_off
    lbu $t0, 0(inbuf)                           # load byte from inbuf (LSB of match off)
    addiu inbuf, 1
    bal .Lreadgamma                             # read gamma-encoded value (match_len)
     or match_off, $t0                          # compute match_off
    bltl match_off, 128, 1f                     
     addiu v0_st, 2
1:  bgel match_off, 32000, 1f
     addiu v0_st, 1
1:  bgel match_off, 1280, 1f
     addiu v0_st, 1
1:
.Ljump_match:                                   
    b .Lmatch                                    # jump to match code
     move match_len, v0_st
.Lrepmatch:                                      # repmatch: just read mach_len
    bal .Lreadgamma                              # read gamma-encoded value
     addiu $ra, -(1f - .Ljump_match)             # when done, return to jump_match
1:

.Ldone:
    lw $ra, 0x14($sp)
    lw $s0, 0x18($sp)
    lw $s1, 0x1c($sp)
    lw $s2, 0x20($sp)
    lw $s3, 0x24($sp)
    lw $s4, 0x28($sp)
    lw $s5, 0x2C($sp)
    lw $s6, 0x30($sp)
    lw $s7, 0x34($sp)
    lw $s8, 0x38($sp)
    jr $ra
    addiu $sp, $sp, 0x40

.Lreadgamma:                                     # read gamma-encoded value
    addiu $sp, $sp, -0x18
    sw $ra, 0x14($sp)
    li v0_st, 1                                     # Start from 1
.Lreadgamma_loop:
    sll v0_st, 1                                   # Shift to make space for new bit
    cc_check 0, .Lreadgamma_check                # Read one bit from CC
    ori v0_st, 1                                   # If 1, set the LSB
.Lreadgamma_check:
    cc_check 1, .Lreadgamma_loop                 # if next CC bit is 0, we are done
    lw $ra, 0x14($sp)
    jr $ra
    addiu $sp, $sp, 0x18

.Lreadcc:                                        # read new CC byte 
    lwl cc, 0(inbuf)                             # load current byte into MSB
    addiu inbuf, 1                               # (other read bytes will be ignored)
    jr $ra
     li cc_count, 6                              # reset CC counter

.Lwaitdma:
    addiu $sp, $sp, -0x18
    sw $ra, 0x14($sp)

    jal dma_async_ctx_read
    move $a0, dma_ctx

    lw $ra, 0x14($sp)
    jr $ra
    addiu $sp, $sp, 0x18

.endfunc
