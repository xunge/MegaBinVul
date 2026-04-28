#include <stddef.h>

struct sk_buff;
struct net_device {
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned long base_addr;
    unsigned int irq;
    unsigned char dma;
    unsigned char if_port;
};

struct rtnl_link_ifmap {
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned long base_addr;
    unsigned int irq;
    unsigned char dma;
    unsigned char port;
};

#define IFLA_MAP 0
#define EMSGSIZE 1

static inline int nla_put(struct sk_buff *skb, int attrtype, int datalen, const void *data) {
    return 0;
}