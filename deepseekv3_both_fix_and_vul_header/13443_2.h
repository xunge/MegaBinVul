#include <stddef.h>
#include <stdlib.h>

#define ERR_PTR(err) ((void *)((long)(err)))
#define ENOMEM 12

struct xt_counters {
    unsigned long pcnt;
    unsigned long bcnt;
};

struct xt_table {
    struct xt_table_info *private;
};

struct xt_table_info {
    unsigned int number;
};

void *vzalloc(size_t size);
void get_counters(const struct xt_table_info *private, struct xt_counters *counters);