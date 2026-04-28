#include <limits.h>
#include <string.h>

struct net;
struct xt_counters {
    unsigned long pcnt;
    unsigned long bcnt;
};
struct xt_table_info {
    void *entries[1];
    unsigned int size;
};
struct arpt_replace {
    char name[32];
    unsigned int valid_hooks;
    unsigned int num_counters;
    void *counters;
    unsigned int size;
};
struct arpt_entry {
    unsigned int next_offset;
};

#define INT_MAX __INT_MAX__
#define ENOMEM (-12)
#define EFAULT (-14)
#define raw_smp_processor_id() 0
#define __user

static inline int copy_from_user(void *dst, const void *src, unsigned long size) {
    memcpy(dst, src, size);
    return 0;
}

static void duprintf(const char *fmt, ...) {}
static int translate_table(struct xt_table_info *newinfo, void *loc_cpu_entry, struct arpt_replace *tmp) { return 0; }
static int __do_replace(struct net *net, const char *name, unsigned int valid_hooks, struct xt_table_info *newinfo, unsigned int num_counters, void *counters) { return 0; }
static void cleanup_entry(struct arpt_entry *iter) {}
static struct xt_table_info *xt_alloc_table_info(unsigned int size) { return 0; }
static void xt_free_table_info(struct xt_table_info *info) {}

#define xt_entry_foreach(iter, entry, size) for(iter = entry; (char*)iter < (char*)entry + size; iter = (void*)iter + iter->next_offset)