#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define CHK_OVERHEAD_SIZE 16
#define CHK_SENTINEL_VALUE 0xAA
#define CHK_SENTINEL_HEAD_SIZE 8

extern void* dlmalloc(size_t bytes);
extern size_t dlmalloc_usable_size(void* mem);