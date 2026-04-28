#include <stddef.h>
#include <stdlib.h>

#define __user
#define GFP_USER 0
#define EOPNOTSUPP 95
#define EFAULT 14
#define ENOMEM 12

struct ethtool_regs {
    unsigned int len;
    unsigned char data[0];
};

struct ethtool_ops {
    int (*get_regs)(struct net_device *, struct ethtool_regs *, void *);
    int (*get_regs_len)(struct net_device *);
};

struct net_device {
    const struct ethtool_ops *ethtool_ops;
};

static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }