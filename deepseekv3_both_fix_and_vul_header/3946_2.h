#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct net_device {
    int type;
    void *mctp_ptr;
};

struct mctp_dev {
    struct net_device *dev;
    void *addrs;
};

struct mctp_dev *mctp_dev_get_rtnl(struct net_device *dev);
bool mctp_known(struct net_device *dev);
void mctp_route_remove_dev(struct mctp_dev *mdev);
void mctp_neigh_remove_dev(struct mctp_dev *mdev);
void mctp_dev_put(struct mctp_dev *mdev);
void netdev_warn(struct net_device *dev, const char *fmt, ...);
#define RCU_INIT_POINTER(p, v) ((p) = (v))
#define __func__ __FUNCTION__

static inline void kfree(void *p) { free(p); }