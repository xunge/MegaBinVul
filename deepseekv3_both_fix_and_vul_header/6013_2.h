#include <stddef.h>
#include <string.h>

#define AF_INET 2
#define NF_INET_NUMHOOKS 8
#define EINVAL 22
#define ENOMEM 12

struct net;
struct xt_table_info {
    unsigned int number;
    unsigned int size;
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int underflow[NF_INET_NUMHOOKS];
    void *entries;
};

struct compat_ipt_replace {
    unsigned int num_entries;
    unsigned int size;
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int underflow[NF_INET_NUMHOOKS];
};

struct ipt_replace {
    unsigned int num_entries;
    unsigned int size;
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int underflow[NF_INET_NUMHOOKS];
    unsigned int num_counters;
    void *counters;
};

struct compat_ipt_entry {
    unsigned int next_offset;
};

void xt_compat_lock(int af);
void xt_compat_unlock(int af);
int xt_compat_init_offsets(int af, unsigned int num_entries);
void xt_compat_flush_offsets(int af);
int check_compat_entry_size_and_hooks(struct compat_ipt_entry *iter0, 
                                    struct xt_table_info *info,
                                    unsigned int *size,
                                    void *entry0,
                                    void *entry_end);
struct xt_table_info *xt_alloc_table_info(unsigned int size);
void xt_free_table_info(struct xt_table_info *info);
void compat_copy_entry_from_user(struct compat_ipt_entry *iter0,
                               void **pos,
                               unsigned int *size,
                               struct xt_table_info *newinfo,
                               void *entry1);
void compat_release_entry(struct compat_ipt_entry *iter0);
int translate_table(struct net *net,
                   struct xt_table_info *newinfo,
                   void *entry1,
                   struct ipt_replace *repl);

#define xt_entry_foreach(iter, entry, size) \
    for ((iter) = (entry); (char*)(iter) < (char*)(entry) + (size); \
         (iter) = (void*)(iter) + (iter)->next_offset)