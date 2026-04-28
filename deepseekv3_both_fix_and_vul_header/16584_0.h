#include <stdlib.h>
#include <stddef.h>

#define PREFIX_SIZE 0
#define MALLOCX_TCACHE_NONE 0

void *mallocx(size_t size, int flags);
void zmalloc_oom_handler(size_t size);
size_t zmalloc_size(void *ptr);
void update_zmalloc_stat_alloc(size_t size);