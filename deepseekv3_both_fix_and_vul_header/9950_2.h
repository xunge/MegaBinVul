#include <string.h>
#include <limits.h>
#include <stdint.h>

#define __user
#define raw_smp_processor_id() 0
#define EFAULT 1
#define ENOMEM 2

struct net;
struct ipt_entry;
struct xt_counters {
    uint64_t pcnt;
    uint64_t bcnt;
};

struct ipt_replace {
    char name[32];
    unsigned int valid_hooks;
    unsigned int num_entries;
    unsigned int size;
    unsigned int num_counters;
    void *counters;
};

struct xt_table_info {
    unsigned int size;
    void *entries[1];
};

static inline int copy_from_user(void *dst, const void *src, unsigned long size) {
    memcpy(dst, src, size);
    return 0;
}

#define xt_entry_foreach(iter, entry, size) \
    for ((iter) = (entry); (char*)(iter) < (char*)(entry) + (size); )

static void duprintf(const char *fmt, ...) {}
static int translate_table(struct net *net, struct xt_table_info *newinfo, void *loc_cpu_entry, const struct ipt_replace *tmp) { return 0; }
static int __do_replace(struct net *net, const char *name, unsigned int valid_hooks, struct xt_table_info *newinfo, unsigned int num_counters, void *counters) { return 0; }
static void cleanup_entry(struct ipt_entry *e, struct net *net) {}
static void xt_free_table_info(struct xt_table_info *info) {}
static struct xt_table_info *xt_alloc_table_info(unsigned int size) { return 0; }