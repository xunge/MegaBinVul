#include <stddef.h>
#include <string.h>

#define NF_ARP_NUMHOOKS 8
#define NFPROTO_ARP 3
#define EINVAL 22
#define ENOMEM 12

struct net;
struct xt_table_info {
    unsigned int size;
    unsigned int number;
    unsigned int hook_entry[NF_ARP_NUMHOOKS];
    unsigned int underflow[NF_ARP_NUMHOOKS];
    void *entries;
};

struct compat_arpt_entry {
    unsigned int next_offset;
    // Add other necessary fields
};

struct compat_arpt_replace {
    unsigned int num_entries;
    unsigned int size;
    unsigned int hook_entry[NF_ARP_NUMHOOKS];
    unsigned int underflow[NF_ARP_NUMHOOKS];
};

struct arpt_replace {
    unsigned int num_entries;
    unsigned int size;
    unsigned int hook_entry[NF_ARP_NUMHOOKS];
    unsigned int underflow[NF_ARP_NUMHOOKS];
    unsigned int num_counters;
    void *counters;
};

#define xt_entry_foreach(pos, e, size) \
    for ((pos) = (struct compat_arpt_entry *)(e); \
         (char *)(pos) < (char *)(e) + (size); \
         (pos) = (struct compat_arpt_entry *)((char *)(pos) + (pos)->next_offset))

extern int xt_compat_init_offsets(unsigned int af, unsigned int number);
extern void xt_compat_flush_offsets(unsigned int af);
extern void xt_compat_lock(unsigned int af);
extern void xt_compat_unlock(unsigned int af);
extern struct xt_table_info *xt_alloc_table_info(unsigned int size);
extern void xt_free_table_info(struct xt_table_info *info);
extern int check_compat_entry_size_and_hooks(struct compat_arpt_entry *e,
                                          struct xt_table_info *newinfo,
                                          unsigned int *size,
                                          void *base,
                                          void *limit);
extern void compat_copy_entry_from_user(struct compat_arpt_entry *e, void **dstptr,
                                     unsigned int *size,
                                     struct xt_table_info *newinfo,
                                     void *base);
extern void compat_release_entry(struct compat_arpt_entry *e);
extern int translate_table(struct net *net, struct xt_table_info *newinfo,
                         void *entry0, const struct arpt_replace *repl);