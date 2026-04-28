#include <stddef.h>
#include <string.h>

#define NF_INET_NUMHOOKS 8
#define AF_INET6 10
#define EINVAL 22
#define ENOMEM 12

struct net;
struct xt_table_info {
    unsigned int size;
    unsigned int number;
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int underflow[NF_INET_NUMHOOKS];
    void *entries;
};
struct compat_ip6t_replace {
    unsigned int size;
    unsigned int num_entries;
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int underflow[NF_INET_NUMHOOKS];
};
struct compat_ip6t_entry {
    unsigned int next_offset;
};
struct ip6t_replace {
    unsigned int size;
    unsigned int num_entries;
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int underflow[NF_INET_NUMHOOKS];
    unsigned int num_counters;
    void *counters;
};

static void xt_compat_lock(int family);
static void xt_compat_unlock(int family);
static int xt_compat_init_offsets(int family, unsigned int num_entries);
static void xt_compat_flush_offsets(int family);
static int check_compat_entry_size_and_hooks(struct compat_ip6t_entry *e, struct xt_table_info *newinfo, unsigned int *size, void *base, void *limit);
static void compat_copy_entry_from_user(struct compat_ip6t_entry *e, void **dstptr, unsigned int *size, struct xt_table_info *newinfo, void *base);
static void compat_release_entry(struct compat_ip6t_entry *e);
static struct xt_table_info *xt_alloc_table_info(unsigned int size);
static void xt_free_table_info(struct xt_table_info *info);
static int translate_table(struct net *net, struct xt_table_info *newinfo, void *entry1, struct ip6t_replace *repl);

#define xt_entry_foreach(pos, e, size) \
    for ((pos) = (e); (pos) < (struct compat_ip6t_entry *)((char *)(e) + (size)); (pos) = (struct compat_ip6t_entry *)((char *)(pos) + (pos)->next_offset))