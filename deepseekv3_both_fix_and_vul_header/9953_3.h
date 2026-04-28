#include <stddef.h>
#include <stdint.h>
#include <limits.h>

#define ENOMEM (-12)
#define EFAULT (-14)
#define __user

struct net;

struct xt_counters {
    uint64_t pcnt;
    uint64_t bcnt;
};

struct ip6t_replace {
    char name[32];
    unsigned int valid_hooks;
    unsigned int num_entries;
    unsigned int size;
    unsigned int num_counters;
    void *counters;
};

struct ip6t_entry {
    unsigned int next_offset;
};

struct xt_table_info {
    unsigned int size;
    void *entries[1];
};

static inline int raw_smp_processor_id(void) { return 0; }

static void duprintf(const char *fmt, ...) {}
static int translate_table(struct net *net, struct xt_table_info *newinfo, void *loc_cpu_entry, struct ip6t_replace *tmp) { return 0; }
static int __do_replace(struct net *net, const char *name, unsigned int valid_hooks, struct xt_table_info *newinfo, unsigned int num_counters, void *counters) { return 0; }
static void cleanup_entry(struct ip6t_entry *iter, struct net *net) {}
static struct xt_table_info *xt_alloc_table_info(unsigned int size) { return NULL; }
static void xt_free_table_info(struct xt_table_info *info) {}
static int copy_from_user(void *dst, const void *src, unsigned long size) { return 0; }

#define xt_entry_foreach(iter, entry, size) \
    for ((iter) = (struct ip6t_entry *)(entry); \
         (void *)(iter) < (void *)(entry) + (size); \
         (iter) = (struct ip6t_entry *)((char *)(iter) + (iter)->next_offset))