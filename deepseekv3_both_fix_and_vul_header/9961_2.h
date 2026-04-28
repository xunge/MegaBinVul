#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define noinline_for_stack
#define __user
#define ETHTOOL_GRXFHINDIR 0x00000000
#define EOPNOTSUPP 95
#define EFAULT 14
#define ENOMEM 12
#define KMALLOC_MAX_SIZE (1UL << 25)
#define GFP_USER 0

typedef uint32_t u32;

struct ethtool_rxfh_indir {
    unsigned int cmd;
    unsigned int size;
    unsigned int *ring_index;
};

struct net_device;

struct ethtool_ops {
    int (*get_rxfh_indir)(struct net_device *, struct ethtool_rxfh_indir *);
};

struct net_device {
    struct ethtool_ops *ethtool_ops;
};

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline unsigned long copy_from_user(void *to, const void __user *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

static inline unsigned long copy_to_user(void __user *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}