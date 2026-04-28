#include <stddef.h>
#include <errno.h>

struct xt_counters {
    // dummy definition
};

struct xt_table {
    void *private;
    // other members omitted
};

struct xt_table_info {
    void *entries;
    // other members omitted
};

struct arpt_entry {
    unsigned int next_offset;
    // other members omitted
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define __user

#define xt_entry_foreach(iter, entries, size) \
    for ((iter) = (struct arpt_entry *)(entries); \
         (char*)(iter) < (char*)(entries) + (size); \
         (iter) = (void*)(iter) + (iter)->next_offset)

static void *alloc_counters(struct xt_table *table) { return NULL; }
static void vfree(void *ptr) {}
static int compat_copy_entry_to_user(struct arpt_entry *e, void __user **pos,
                                    unsigned int *size, struct xt_counters *counters, unsigned int i) { return 0; }