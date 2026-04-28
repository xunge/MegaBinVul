#include <stdlib.h>
#include <stddef.h>

#define PREFIX_SIZE sizeof(size_t)
#define HAVE_MALLOC_SIZE 0

void *zmalloc(size_t size);
void zfree(void *ptr);
size_t zmalloc_size(void *ptr);
void zmalloc_oom_handler(size_t size);
void update_zmalloc_stat_free(size_t size);
void update_zmalloc_stat_alloc(size_t size);