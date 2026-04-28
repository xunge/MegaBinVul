#include <stddef.h>

struct dec_tables_t {
    int counter_head;
    int counter_tail;
};

extern struct dec_tables_t dec_tables;
extern void prefetch_table(const void *, size_t);