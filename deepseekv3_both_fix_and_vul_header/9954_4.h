#include <limits.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

struct net {
    // dummy definition
};

struct compat_ip6t_replace {
    unsigned int size;
    unsigned int num_counters;
    unsigned int num_entries;
    unsigned int valid_hooks;
    unsigned int hook_entry[5];
    unsigned int underflow[5];
    char name[32];
    unsigned int counters;
};

struct xt_table_info {
    unsigned int size;
    void *entries[1];
};

struct ip6t_entry {
    // dummy definition
};

struct xt_counters {
    unsigned long pcnt;
    unsigned long bcnt;
};

#define INT_MAX __INT_MAX__
#define ENOMEM (-12)
#define EFAULT (-14)

#define __user

static inline int copy_from_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

static inline void *compat_ptr(unsigned int ptr) {
    return (void *)(unsigned long)ptr;
}

#define num_possible_cpus() 1
#define raw_smp_processor_id() 0

static int translate_compat_table(struct net *net, const char *name, unsigned int valid_hooks,
                                struct xt_table_info **newinfo, void **loc_cpu_entry,
                                unsigned int size, unsigned int number, unsigned int *hook_entries,
                                unsigned int *underflows) { return 0; }

static int __do_replace(struct net *net, const char *name, unsigned int valid_hooks,
                       struct xt_table_info *newinfo, unsigned int num_counters, void *counters) { return 0; }

static void cleanup_entry(struct ip6t_entry *entry, struct net *net) {}

static void xt_free_table_info(struct xt_table_info *info) { free(info); }

static struct xt_table_info *xt_alloc_table_info(unsigned int size) {
    return (struct xt_table_info *)malloc(sizeof(struct xt_table_info) + size);
}

#define duprintf(fmt, ...) do {} while (0)
#define xt_entry_foreach(iter, entry, size) \
    for ((iter) = (struct ip6t_entry *)(entry); \
         (char *)(iter) < (char *)(entry) + (size); \
         (iter) = (struct ip6t_entry *)((char *)(iter) + sizeof(struct ip6t_entry)))