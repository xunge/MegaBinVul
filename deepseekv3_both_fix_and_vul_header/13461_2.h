#include <stddef.h>
#include <errno.h>

struct xt_counters {
    // dummy definition
};

struct xt_table {
    struct xt_table_info *private;
    // other members...
};

struct xt_table_info {
    void *entries;
    // other members...
};

struct ip6t_entry {
    unsigned int next_offset;
    // other members...
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define __user

void *alloc_counters(struct xt_table *table);
int compat_copy_entry_to_user(struct ip6t_entry *iter, void __user **pos,
                            unsigned int *size, struct xt_counters *counters, 
                            unsigned int i);
void vfree(void *addr);

#define xt_entry_foreach(iter, entries, size) \
    for ((iter) = (struct ip6t_entry *)(entries); \
         (char*)(iter) < (char*)(entries) + (size); \
         (iter) = (struct ip6t_entry *)((char*)(iter) + (iter)->next_offset))