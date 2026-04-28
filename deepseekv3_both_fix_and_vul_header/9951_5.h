#include <limits.h>
#include <stddef.h>
#include <string.h>

struct net {
    // dummy net structure
};

struct compat_ipt_replace {
    unsigned int size;
    unsigned int num_counters;
    unsigned int num_entries;
    unsigned int valid_hooks;
    unsigned int hook_entry[5];
    unsigned int underflow[5];
    char name[32];
    void *counters;
};

struct xt_counters {
    unsigned long pcnt;
    unsigned long bcnt;
};

struct xt_table_info {
    unsigned int size;
    void *entries[1];
};

struct ipt_entry {
    // dummy ipt_entry structure
};

#define INT_MAX __INT_MAX__
#define ENOMEM (-12)
#define EFAULT (-14)

#define num_possible_cpus() 1
#define raw_smp_processor_id() 0

#define duprintf(fmt, ...)
#define compat_ptr(p) ((void*)(p))
#define __user

static inline int copy_from_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static int translate_compat_table(struct net *net, const char *name, unsigned int valid_hooks,
                                struct xt_table_info **newinfo, void **loc_cpu_entry,
                                unsigned int size, unsigned int num_entries,
                                unsigned int *hook_entry, unsigned int *underflow) {
    return 0;
}

static int __do_replace(struct net *net, const char *name, unsigned int valid_hooks,
                       struct xt_table_info *newinfo, unsigned int num_counters,
                       void *counters) {
    return 0;
}

#define xt_entry_foreach(iter, entry, size) \
    for ((iter) = (struct ipt_entry*)(entry); \
         (char*)(iter) < (char*)(entry) + (size); \
         (iter) = (struct ipt_entry*)((char*)(iter) + 1))

static void cleanup_entry(struct ipt_entry *iter, struct net *net) {
}

static struct xt_table_info *xt_alloc_table_info(unsigned int size) {
    return NULL;
}

static void xt_free_table_info(struct xt_table_info *info) {
}