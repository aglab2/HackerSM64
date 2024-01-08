#pragma once

/*******************
 * MEMORY SETTINGS *
 *******************/

/**
 * Enables use of 8MB RAM.
 * goddard segment is put in either last 8MB or 4MB depending on this option.
 * It is highly recommended to keep this option enabled as it greatly increases the amount of space available for custom content.
 */
#define USE_EXT_RAM

/**
 * Defines amount of allowed main pool memory fragmentation due to zbuffer/framebuffer relocations. The more fragmented the level, the better alignment of framebuffers but worse contig memory allocation.
 * Larger values refer to a more fragmented memory layout but potentially better performance.
 * If you want to try it out, I suggest using options MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS, MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS_SPLIT and MEMORY_FRAGMENTATION_ZBUFFER_AND_EACH_FRAMEBUFFER.
 */
// no fragmentation allowed. This allows for roughly 5.5MB max contig alloc
#define MEMORY_FRAGMENTATION_NO_FRAGMENTATION 0

// 'MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS_*' puts zbuffer and 3 framebuffers in 2 separate memory banks with various memory layouts:
// All framebuffers & zbuffer are moved to separate 1MB banks using 2 separate bank in the end of the RAM around the 'pivot' point. This allows for roughly 5MB max contig alloc
#define MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS 10
// All framebuffers & zbuffer are moved to separate 1MB banks using 2 separate bank in the end of the RAM at the start of the bank. This allows for roughly 4MB max contig alloc
#define MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS_ALIGNED 11
// All framebuffers & zbuffer are moved to separate 1MB banks using 2 separate bank around the 'pivot' point at 0x80500000. Main pool first region starts at 0x80600000. This allows for roughly 2MB+3MB max contig alloc and gives nicer memory use.
#define MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS_SPLIT 15

// 'MEMORY_FRAGMENTATION_ZBUFFER_AND_EACH_FRAMEBUFFER*' puts zbuffer and each framebuffer in 4 separate memory banks.
// Each framebuffer and zbuffer are moved to separate 1MB banks around 2 pivot points 0x80700000 and 0x80500000. This allows for roughly 3MB max contig alloc
#define MEMORY_FRAGMENTATION_ZBUFFER_AND_EACH_FRAMEBUFFER 20
// Each framebuffer and zbuffer are moved to separate 1MB banks and put at the start of the bank. This allows for roughly 2MB max contig alloc
#define MEMORY_FRAGMENTATION_ZBUFFER_AND_EACH_FRAMEBUFFER_ALIGNED 21

#define MEMORY_FRAGMENTATION_LEVEL MEMORY_FRAGMENTATION_NO_FRAGMENTATION

// For nerds here are the results of measurements

/**
 * Raw numbers of available memory in regions based on the fragmentation level
 * 0  - 0x8025DF00-0x59B960
 * 10 - 0x801C7F40-0x5128C0 0x80770800-0x89060
 * 11 - 0x801C7F80-0x438080 0x80770800-0x89060  0x80625800-0xDA800
 * 15 - 0x80600000-0x1F9860 0x801C7F80-0x312880 0x80570800-0x8F800
 * 20 - 0x801C7F80-0x312880 0x80525800-0x1B5000 0x80725800-0xD4060
 * 21 - 0x801C7F80-0x238080 0x80425800-0xDA800  0x80525800-0xDA800 0x80625800-0xDA800 0x80725800-0xD4060
 */

/**
 * Performance test results for heavily RDP bounded level - JRB entrance with removed music
 * 0  - 23.78 FPS / RDP 125% / RSP 91%
 * 10 - 24.23 FPS / RDP 123% / RSP 89%
 * 11 - 24.08 FPS / RDP 123% / RSP 89%
 * 15 - 24.08 FPS / RDP 123% / RSP 88%
 * 20 - 25.02 FPS / RDP 119% / RSP 86%
 * 21 - 25.03 FPS / RDP 119% / RSP 86%
 */

// Notice that there is no real benefits from enabling mode 2x over 1x but 11 over 10 or 21 over 20 does not bring any benefits other than increased segmentation
// 10 only trims ~0.8MB contig memory while bringing good performance boost