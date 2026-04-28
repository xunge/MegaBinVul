#include <stdint.h>
#include <string.h>

typedef uint32_t u32;
typedef uint32_t __u32;

struct sk_buff {
    unsigned char *data;
    unsigned char *tail;
    unsigned int len;
};

struct net_device {
    unsigned short type;
    int ifindex;
    int iflink;
    unsigned int tx_queue_len;
    unsigned int weight;
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned long base_addr;
    unsigned int irq;
    unsigned char dma;
    unsigned char if_port;
    unsigned char addr_len;
    unsigned char *dev_addr;
    unsigned char *broadcast;
    unsigned int mtu;
    struct {
        struct {
            char *id;
        } *ops;
    } *qdisc_sleeping;
    struct net_device *master;
    unsigned long *(*get_stats)(struct net_device *dev);
    char name[16];
};

struct ifinfomsg {
    unsigned char ifi_family;
    unsigned char __ifi_pad;
    unsigned short ifi_type;
    int ifi_index;
    unsigned ifi_flags;
    unsigned ifi_change;
};

struct nlmsghdr {
    uint32_t nlmsg_len;
    uint16_t nlmsg_type;
    uint16_t nlmsg_flags;
    uint32_t nlmsg_seq;
    uint32_t nlmsg_pid;
};

struct rtattr {
    unsigned short rta_len;
    unsigned short rta_type;
};

struct rtnl_link_ifmap {
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned long base_addr;
    unsigned int irq;
    unsigned char dma;
    unsigned char port;
};

struct rtnl_link_stats {
    __u32 rx_packets;
    __u32 tx_packets;
    __u32 rx_bytes;
    __u32 tx_bytes;
    __u32 rx_errors;
    __u32 tx_errors;
    __u32 rx_dropped;
    __u32 tx_dropped;
    __u32 multicast;
    __u32 collisions;
    __u32 rx_length_errors;
    __u32 rx_over_errors;
    __u32 rx_crc_errors;
    __u32 rx_frame_errors;
    __u32 rx_fifo_errors;
    __u32 rx_missed_errors;
    __u32 tx_aborted_errors;
    __u32 tx_carrier_errors;
    __u32 tx_fifo_errors;
    __u32 tx_heartbeat_errors;
    __u32 tx_window_errors;
    __u32 rx_compressed;
    __u32 tx_compressed;
};

#define AF_UNSPEC 0
#define IFLA_IFNAME 1
#define IFLA_TXQLEN 2
#define IFLA_WEIGHT 3
#define IFLA_MAP 4
#define IFLA_ADDRESS 5
#define IFLA_BROADCAST 6
#define IFLA_MTU 7
#define IFLA_LINK 8
#define IFLA_QDISC 9
#define IFLA_MASTER 10
#define IFLA_STATS 11

static inline struct nlmsghdr* NLMSG_NEW(struct sk_buff *skb, u32 pid, u32 seq, int type, size_t len, unsigned flags) {
    struct nlmsghdr *nlh = (struct nlmsghdr *)skb->tail;
    nlh->nlmsg_type = type;
    nlh->nlmsg_flags = flags;
    nlh->nlmsg_seq = seq;
    nlh->nlmsg_pid = pid;
    nlh->nlmsg_len = sizeof(struct nlmsghdr) + len;
    skb->tail += sizeof(struct nlmsghdr) + len;
    skb->len += sizeof(struct nlmsghdr) + len;
    return nlh;
}

#define NLMSG_DATA(nlh) ((void*)(((char*)nlh) + sizeof(struct nlmsghdr)))

static inline int RTA_PUT(struct sk_buff *skb, unsigned short attrtype, size_t attrlen, const void *data) {
    struct rtattr *rta = (struct rtattr *)skb->tail;
    rta->rta_type = attrtype;
    rta->rta_len = sizeof(struct rtattr) + attrlen;
    memcpy((void*)((char*)rta + sizeof(struct rtattr)), data, attrlen);
    skb->tail += sizeof(struct rtattr) + attrlen;
    skb->len += sizeof(struct rtattr) + attrlen;
    return 0;
}

static inline struct rtattr* __RTA_PUT(struct sk_buff *skb, unsigned short attrtype, size_t attrlen) {
    struct rtattr *rta = (struct rtattr *)skb->tail;
    rta->rta_type = attrtype;
    rta->rta_len = sizeof(struct rtattr) + attrlen;
    skb->tail += sizeof(struct rtattr) + attrlen;
    skb->len += sizeof(struct rtattr) + attrlen;
    return rta;
}

#define RTA_DATA(rta) ((void*)((char*)(rta) + sizeof(struct rtattr)))

static inline unsigned dev_get_flags(struct net_device *dev) {
    return 0;
}

static inline void skb_trim(struct sk_buff *skb, unsigned int len) {
    skb->len = len;
    skb->tail = skb->data + len;
}