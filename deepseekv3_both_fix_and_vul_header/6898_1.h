#include <linux/netlink.h>

struct netlink_callback {
    unsigned long args[2];
};

struct xfrm_policy_walk;
void xfrm_policy_walk_done(struct xfrm_policy_walk *walk);