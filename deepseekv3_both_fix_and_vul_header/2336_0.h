#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define ASSERT(cond) ((void)0)

#define PGT_count_mask 0x00000000FFFFFFFFUL
#define PGT_locked 0x8000000000000000UL

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

unsigned long cmpxchg(volatile unsigned long *ptr, unsigned long old, unsigned long new);