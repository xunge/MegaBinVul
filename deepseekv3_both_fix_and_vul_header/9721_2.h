#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define KMALLOC_MAX_SIZE (1UL << 25)
#define GFP_USER 0
#define EOPNOTSUPP 95
#define EFAULT 14  
#define ENOMEM 12
#define ETHTOOL_GRXCLSRLALL 0x0000001C

typedef unsigned int u32;

struct net_device {
    void *ethtool_ops;
};

struct ethtool_ops {
    int (*get_rxnfc)(struct net_device *, void *, void *);
};

struct ethtool_rxnfc {
    int cmd;
    unsigned int rule_cnt;
    u32 *rule_locs;
};

#define __user
#define noinline_for_stack

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline int copy_from_user(void *to, const void __user *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline int copy_to_user(void __user *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}