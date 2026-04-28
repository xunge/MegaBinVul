#include <linux/netdevice.h>
#include <linux/if_bonding.h>
#include <linux/errno.h>

struct xfrm_state;
struct xfrmdev_ops;

struct xfrm_state {
    struct {
        struct net_device *dev;
        struct net_device *real_dev;
    } xso;
};

struct net_device {
    struct xfrmdev_ops *xfrmdev_ops;
};

struct xfrmdev_ops {
    int (*xdo_dev_state_add)(struct xfrm_state *xs);
};

struct bonding {
    struct slave *curr_active_slave;
    struct xfrm_state *xs;
};

struct slave {
    struct net_device *dev;
};