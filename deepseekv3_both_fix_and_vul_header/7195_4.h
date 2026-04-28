#include <stdlib.h>

struct net_device;
struct net;
struct ctl_table;

struct sysctl_header {
    struct ctl_table *ctl_table_arg;
};

struct mpls_dev {
    struct sysctl_header *sysctl;
};

struct net* dev_net(struct net_device *dev);
void unregister_net_sysctl_table(struct sysctl_header *header);
void kfree(void *ptr);
void mpls_netconf_notify_devconf(struct net *net, int cmd, int index, struct mpls_dev *mdev);

#define RTM_DELNETCONF 0