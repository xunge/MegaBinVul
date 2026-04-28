#include <string.h>
#include <stdio.h>

struct net_device {
    char *name;
};

struct ifreq {
    void *ifr_data;
};

struct s_skfp_ioctl {
    unsigned int cmd;
    unsigned int len;
    void *data;
};

typedef struct {
    int MacStat;
} skfddi_priv;

struct s_smc {
    skfddi_priv os;
};

#define SKFP_GET_STATS 0
#define SKFP_CLR_STATS 1
#define EFAULT 14
#define EPERM 1
#define EOPNOTSUPP 95
#define CAP_NET_ADMIN 12

static inline void *netdev_priv(struct net_device *dev) { return (void*)&dev[1]; }
static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int capable(int cap) { return 1; }
static inline void *skfp_ctl_get_stats(struct net_device *dev) { return NULL; }
static inline int printk(const char *fmt, ...) { return 0; }