#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct xt_table {
    struct xt_table_info *private;
};

struct xt_table_info {
    void *entries;
};

struct xt_counters {
    unsigned long pcnt;
    unsigned long bcnt;
};

struct arpt_entry {
    unsigned int next_offset;
    unsigned int target_offset;
    struct xt_counters counters;
};

struct xt_entry_target {
    unsigned int target_size;
    char name[32];
    unsigned char data[0];
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define __user
#define vfree free
#define EFAULT 14

void *alloc_counters(const struct xt_table *table);
int copy_to_user(void *dst, const void *src, size_t size);
struct xt_entry_target *arpt_get_target_c(const struct arpt_entry *e);
int xt_target_to_user(const struct xt_entry_target *t, void *userptr);