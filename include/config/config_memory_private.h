#include "config_memory.h"

#ifndef USE_EXT_RAM
// In 4MB mode, it is not possible to have each fb be it is own bank so use only 2 banks
#if MEMORY_FRAGMENTATION_LEVEL > 10
#warning "Memory fragmentation level is too high for 4MB mode. Setting to 10 (2 banks with pivot point)"
#undef MEMORY_FRAGMENTATION_LEVEL
#define MEMORY_FRAGMENTATION_LEVEL 10
#endif
#endif

// Either size of zbuffer or size of framebuffer
#define RENDER_BUFFER_BUFFER_SIZE 0x25800

#if 10 == MEMORY_FRAGMENTATION_LEVEL
#ifndef USE_EXT_RAM
#define RENDER_BUFFER_MEMORY_PIVOT 0x80300000
#else
#define RENDER_BUFFER_MEMORY_PIVOT 0x80700000
#endif
#define ZBUFFER_LOCATION RENDER_BUFFER_MEMORY_PIVOT - RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER0_LOCATION RENDER_BUFFER_MEMORY_PIVOT
#define FRAMEBUFFER1_LOCATION RENDER_BUFFER_MEMORY_PIVOT + RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER2_LOCATION RENDER_BUFFER_MEMORY_PIVOT + 2 * RENDER_BUFFER_BUFFER_SIZE
#endif

// Anything above 1 is using the ext ram so do not bother checking for 'USE_EXT_RAM'
#if 11 == MEMORY_FRAGMENTATION_LEVEL
#define ZBUFFER_LOCATION 0x80600000
#define FRAMEBUFFER0_LOCATION 0x80700000
#define FRAMEBUFFER1_LOCATION 0x80700000 + RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER2_LOCATION 0x80700000 + 2 * RENDER_BUFFER_BUFFER_SIZE
#endif

#if 15 == MEMORY_FRAGMENTATION_LEVEL
#define ZBUFFER_LOCATION 0x80500000 - RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER0_LOCATION 0x80500000
#define FRAMEBUFFER1_LOCATION 0x80500000 + RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER2_LOCATION 0x80500000 + 2 * RENDER_BUFFER_BUFFER_SIZE
#endif

#if 20 == MEMORY_FRAGMENTATION_LEVEL
#define ZBUFFER_LOCATION 0x80500000 - RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER0_LOCATION 0x80500000
#define FRAMEBUFFER1_LOCATION 0x80700000 - RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER2_LOCATION 0x80700000
#endif

#if 21 == MEMORY_FRAGMENTATION_LEVEL
#define ZBUFFER_LOCATION 0x80400000
#define FRAMEBUFFER0_LOCATION 0x80500000
#define FRAMEBUFFER1_LOCATION 0x80600000
#define FRAMEBUFFER2_LOCATION 0x80700000
#endif

#define ZBUFFER_START ZBUFFER_LOCATION
#define FRAMEBUFFER0_START FRAMEBUFFER0_LOCATION
#define FRAMEBUFFER1_START FRAMEBUFFER1_LOCATION
#define FRAMEBUFFER2_START FRAMEBUFFER2_LOCATION

#define ZBUFFER_END ZBUFFER_LOCATION + RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER0_END FRAMEBUFFER0_LOCATION + RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER1_END FRAMEBUFFER1_LOCATION + RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER2_END FRAMEBUFFER2_LOCATION + RENDER_BUFFER_BUFFER_SIZE
