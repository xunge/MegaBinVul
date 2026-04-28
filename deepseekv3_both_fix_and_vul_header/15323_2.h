#include <linux/netlink.h>
#include <linux/net.h>

struct cn_dev {
    unsigned int id;
    struct sock *nls;
    void *cbdev;
};

extern struct net init_net;
struct cn_dev cdev;
int cn_already_initialized;

#define __devexit