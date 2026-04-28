#include <stddef.h>

#define DEFAULT_PRB_RETIRE_TOV 0
#define SPEED_1000 1000
#define SPEED_UNKNOWN -1

struct packet_sock {
    int ifindex;
    struct {
        int dummy;
    } sk;
};

struct net_device;
struct ethtool_link_ksettings {
    struct {
        int speed;
    } base;
};

void rtnl_lock(void);
void rtnl_unlock(void);
struct net_device *__dev_get_by_index(void *net, int ifindex);
int __ethtool_get_link_ksettings(struct net_device *dev, struct ethtool_link_ksettings *ecmd);
void *sock_net(struct sk_buff *skb);