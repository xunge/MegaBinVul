#include <linux/netfilter_arp/arp_tables.h>
#include <linux/netfilter/x_tables.h>
#include <linux/string.h>

struct xt_table_info {
    unsigned int size;
    unsigned int hook_entry[NF_ARP_NUMHOOKS];
};

static inline void *arpt_get_target_c(const struct arpt_entry *e)
{
    return (void *)e + e->target_offset;
}

static inline int unconditional(const struct arpt_arp *arp)
{
    return 1;
}

#define pr_notice(fmt, ...)
#define duprintf(fmt, ...)