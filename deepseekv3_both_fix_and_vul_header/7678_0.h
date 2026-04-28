#include <stdlib.h>

typedef struct regex_t {
    unsigned char *p;
    unsigned int alloc;
    unsigned int used;
    struct regex_t *chain;
} regex_t;

extern void *xrealloc(void *ptr, size_t size);