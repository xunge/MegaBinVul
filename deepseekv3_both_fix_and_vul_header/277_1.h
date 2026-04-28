#include <stddef.h>

struct enc_tables_t {
    int counter_head;
    int counter_tail;
};

extern struct enc_tables_t enc_tables;
extern int encT[256];  // 假设数组大小为256，可根据实际情况调整

void prefetch_table(const void *addr, size_t len);