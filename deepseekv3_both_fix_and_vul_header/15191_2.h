#include <sys/socket.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>

struct sk_buff {
    unsigned char *tail;
    unsigned char *data;
    int len;
};

struct net_device {
    int type;
    int ifindex;
    unsigned int flags;
};

static inline void skb_trim(struct sk_buff *skb, int len) {}