#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct xt_counters {
    unsigned long pcnt;
    unsigned long bcnt;
};

struct xt_table_info {
    void *entries;
    void *private;
};

struct xt_table {
    struct xt_table_info *private;
};

struct ipt_entry {
    unsigned int next_offset;
    unsigned int target_offset;
    struct xt_counters counters;
};

struct xt_entry_match {
    union {
        unsigned int match_size;
        unsigned int u_match_size;
    } u;
};

struct xt_entry_target {
    unsigned int target_size;
};

#define __user
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define EFAULT 14

static void *alloc_counters(const struct xt_table *table) {
    return malloc(sizeof(struct xt_counters));
}

static int xt_match_to_user(const struct xt_entry_match *m, void *userptr) {
    return memcpy(userptr, m, m->u.match_size) ? 0 : -EFAULT;
}

static int xt_target_to_user(const struct xt_entry_target *t, void *userptr) {
    return memcpy(userptr, t, t->target_size) ? 0 : -EFAULT;
}

static struct xt_entry_target *ipt_get_target_c(const struct ipt_entry *e) {
    return (struct xt_entry_target *)((char *)e + e->target_offset);
}

static int copy_to_user(void *dst, const void *src, size_t size) {
    return memcpy(dst, src, size) ? 0 : -EFAULT;
}

static void vfree(void *ptr) {
    free(ptr);
}