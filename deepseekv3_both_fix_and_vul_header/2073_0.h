#include <stddef.h>
#include <stdint.h>

#define MALLOC_ALIGNMENT 16
#define MEMALIGN_GUARD ((void*)0xdeadbeef)

void* leak_malloc(size_t bytes);