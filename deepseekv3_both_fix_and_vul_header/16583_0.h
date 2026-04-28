#include <stdlib.h>
#include <string.h>

#define PREFIX_SIZE sizeof(size_t)
#define HAVE_MALLOC_SIZE 0

extern void zmalloc_oom_handler(size_t size);
extern void update_zmalloc_stat_alloc(size_t size);
extern size_t zmalloc_size(void *ptr);