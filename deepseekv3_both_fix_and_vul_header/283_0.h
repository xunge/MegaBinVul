#include <stddef.h>

struct {
    int counter_head;
    int counter_tail;
} gcm_table;

extern void prefetch_table(const void *, size_t);
extern const void *gcmR;