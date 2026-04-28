#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t u8;

struct search_state {
    struct search_domain *head;
};

struct search_domain {
    struct search_domain *next;
    int len;
};

extern void *mm_malloc(size_t size);
#define EVUTIL_ASSERT(cond) ((void)0)