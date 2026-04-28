#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define ENOMEM 12
#define ERR_PTR(err) ((void *)((long)(err)))

struct xt_table_info {
    unsigned int number;
    void *private;
};

struct xt_counters {
    unsigned long long pcnt;
    unsigned long long bcnt;
};

struct xt_table {
    struct xt_table_info *private;
};

static void *vzalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr) memset(ptr, 0, size);
    return ptr;
}

static void get_counters(const struct xt_table_info *private, struct xt_counters *counters);