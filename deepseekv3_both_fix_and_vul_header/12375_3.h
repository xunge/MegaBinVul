#include <stdlib.h>
#include <stdbool.h>

extern bool check_mul_overflow(size_t a, size_t b, size_t *res);
extern void alloc_limit_assert(const char *func, size_t size);
extern void *xmalloc(...);