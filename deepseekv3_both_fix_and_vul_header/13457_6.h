#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

struct xt_table_info {
    void *entries;
    void *private;
};

struct xt_table {
    struct xt_table_info *private;
};

struct xt_counters {
    uint64_t pcnt;
    uint64_t bcnt;
};

struct ip6t_entry {
    unsigned int next_offset;
    unsigned int target_offset;
    struct xt_counters counters;
};

struct xt_entry_match {
    union {
        unsigned int match_size;
    } u;
};

struct xt_entry_target;

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((int)(uintptr_t)(x))
#define EFAULT 14

static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    return 0;
}

static struct xt_counters *alloc_counters(const struct xt_table *table) {
    return malloc(sizeof(struct xt_counters));
}

static const struct xt_entry_target *ip6t_get_target_c(const struct ip6t_entry *e) {
    return (const struct xt_entry_target *)((char *)e + e->target_offset);
}

static int xt_match_to_user(const struct xt_entry_match *m, void *userptr) {
    return 0;
}

static int xt_target_to_user(const struct xt_entry_target *t, void *userptr) {
    return 0;
}

static void vfree(void *addr) {
    free(addr);
}

#define __user