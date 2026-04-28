#include <stdlib.h>
#include <stddef.h>

extern void alloc_limit_assert(const char *func, size_t size);
extern void *xcalloc(size_t num, size_t size);