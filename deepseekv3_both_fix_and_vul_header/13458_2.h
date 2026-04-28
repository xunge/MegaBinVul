#include <stdlib.h>
#include <stddef.h>

struct xt_counters {
    // 定义必要的成员变量
    unsigned long pcnt;
    unsigned long bcnt;
};

struct xt_table_info {
    unsigned int number;
    void *private;
};

struct xt_table {
    struct xt_table_info *private;
};

#define ENOMEM 12
#define ERR_PTR(err) ((void *)((long)(err)))

static void *vzalloc(size_t size) {
    return calloc(1, size);
}

static void get_counters(const struct xt_table_info *private, struct xt_counters *counters) {
    // 简单实现
    for (unsigned int i = 0; i < private->number; i++) {
        counters[i].pcnt = 0;
        counters[i].bcnt = 0;
    }
}