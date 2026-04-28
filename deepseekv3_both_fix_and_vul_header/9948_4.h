#include <limits.h>
#include <stddef.h>

struct net;
struct compat_arpt_replace {
    unsigned int size;
    unsigned int num_counters;
    unsigned int num_entries;
    unsigned int valid_hooks;
    unsigned int hook_entry[0];
    unsigned int underflow[0];
    char name[32];
    void *counters;
};
struct xt_table_info {
    void *entries[1];
    unsigned int size;
};
struct arpt_entry {
    /* dummy structure to allow sizeof and pointer arithmetic */
    char dummy[1];
};
struct xt_counters {
    /* dummy structure to allow sizeof */
    char dummy[1];
};

#define ENOMEM 12
#define EFAULT 14
#define INT_MAX __INT_MAX__

#define duprintf(fmt, ...) do {} while (0)
#define compat_ptr(p) ((void *)(unsigned long)(p))
#define raw_smp_processor_id() 0
#define num_possible_cpus() 1

static inline int copy_from_user(void *dst, const void *src, size_t size) { return 0; }

static inline void *xt_alloc_table_info(unsigned int size) { return NULL; }
static inline void xt_free_table_info(struct xt_table_info *info) {}
static inline int translate_compat_table(const char *name, unsigned int valid_hooks,
                                       struct xt_table_info **newinfo, void **loc_cpu_entry,
                                       unsigned int size, unsigned int num_entries,
                                       unsigned int *hook_entry, unsigned int *underflow) { return 0; }
static inline int __do_replace(struct net *net, const char *name, unsigned int valid_hooks,
                             struct xt_table_info *newinfo, unsigned int num_counters,
                             void *counters) { return 0; }
static inline void cleanup_entry(struct arpt_entry *e) {}
#define xt_entry_foreach(iter, entry, size) for ((iter) = (struct arpt_entry *)(entry); \
    (char *)(iter) < (char *)(entry) + (size); \
    (iter) = (struct arpt_entry *)((char *)(iter) + sizeof(struct arpt_entry)))

#define __user