#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;
#define __user

#define noinline_for_stack
#define KMALLOC_MAX_SIZE (1UL << 16)
#define GFP_USER 0
#define EOPNOTSUPP 95
#define EFAULT 14
#define ENOMEM 12

#define ETHTOOL_GRXFH 1
#define ETHTOOL_GRXCLSRLALL 2

struct net_device {
    const struct ethtool_ops *ethtool_ops;
};

struct ethtool_ops {
    int (*get_rxnfc)(struct net_device *, void *, void *);
};

struct ethtool_rxnfc {
    u32 cmd;
    u32 flow_type;
    u32 data;
    u32 rule_cnt;
    u32 *rule_locs;
};

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);

int copy_from_user(void *to, const void *from, size_t n);
int copy_to_user(void *to, const void *from, size_t n);