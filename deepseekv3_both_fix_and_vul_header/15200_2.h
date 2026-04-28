#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint32_t __u32;
typedef int32_t __s32;
typedef uint8_t u8;

struct sk_buff {
    unsigned char *tail;
    unsigned char *data;
    int len;
};

struct net_device {
    unsigned int type;
    int ifindex;
    int iflink;
    __u32 mtu;
    unsigned char *dev_addr;
    unsigned char addr_len;
    char *name;
};

struct inet6_dev {
    struct net_device *dev;
    unsigned long tstamp;
    __u32 if_flags;
    struct {
        __u32 reachable_time;
        __u32 retrans_time;
    } *nd_parms;
    __u32 cnf[64];
};

struct ifinfomsg {
    unsigned char ifi_family;
    unsigned char __ifi_pad;
    unsigned short ifi_type;
    int ifi_index;
    unsigned int ifi_flags;
    unsigned int ifi_change;
};

struct nlmsghdr {
    uint32_t nlmsg_len;
};

struct rtattr {
    unsigned short rta_len;
};

struct ifla_cacheinfo {
    __u32 max_reasm_len;
    __u32 tstamp;
    __u32 reachable_time;
    __u32 retrans_time;
};

#define AF_INET6 10
#define DEVCONF_MAX 64
#define GFP_ATOMIC 0
#define HZ 100
#define IFLA_ADDRESS 1
#define IFLA_IFNAME 2
#define IFLA_INET6_CACHEINFO 3
#define IFLA_INET6_CONF 4
#define IFLA_INET6_FLAGS 5
#define IFLA_LINK 6
#define IFLA_MTU 7
#define IFLA_PROTINFO 8
#define INITIAL_JIFFIES 0
#define IPV6_MAXPLEN 65535
#define TIME_DELTA(a, b) ((a) - (b))

#define NLMSG_NEW(skb, pid, seq, type, len, flags) \
    ({ (struct nlmsghdr *)skb_put(skb, sizeof(struct nlmsghdr)); })
#define NLMSG_DATA(nlh) ((void *)((char *)(nlh) + sizeof(struct nlmsghdr)))
#define RTA_PUT(skb, attrtype, attrlen, data) \
    ({ if (0) goto rtattr_failure; })

static inline unsigned int dev_get_flags(const struct net_device *dev) {
    return 0;
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline void skb_trim(struct sk_buff *skb, unsigned int len) {
    skb->len = len;
}

static inline unsigned char *skb_put(struct sk_buff *skb, unsigned int len) {
    unsigned char *tmp = skb->tail;
    skb->tail += len;
    skb->len += len;
    return tmp;
}

static inline void ipv6_store_devconf(__u32 *cnf, __s32 *array, size_t size) {
}