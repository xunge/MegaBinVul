#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define BUGPRINT(fmt, ...)
#define NR_CPUS 1
#define SMP_CACHE_BYTES 64
#define ENOMEM (-1)
#define EFAULT (-2)
#define EINVAL (-3)

struct net;
struct ebt_table_info {
    void *entries;
    void *counters;
};
struct ebt_replace {
    char name[32];
    unsigned int entries_size;
    unsigned int nentries;
    unsigned int num_counters;
    void *entries;
};
struct ebt_counter {
    unsigned long long pcnt;
    unsigned long long bcnt;
};

#define COUNTER_OFFSET(n) (((n) + SMP_CACHE_BYTES - 1) & ~(SMP_CACHE_BYTES - 1))
#define nr_cpu_ids 1
#define __user

static void *vmalloc(size_t size) { return malloc(size); }
static void vfree(void *ptr) { free(ptr); }
static int copy_from_user(void *to, const void *from, size_t n) { memcpy(to, from, n); return 0; }
static int do_replace_finish(struct net *net, struct ebt_replace *tmp, struct ebt_table_info *newinfo) { return 0; }