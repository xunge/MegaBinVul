#include <stdint.h>
#include <netinet/in.h>
#include <sys/socket.h>

typedef uint32_t u32;

#define IF_PREFIX_ONLINK 0x01
#define IF_PREFIX_AUTOCONF 0x02
#define PREFIX_ADDRESS 1
#define PREFIX_CACHEINFO 2

struct sk_buff {
    unsigned char *tail;
    unsigned char *data;
    int len;
};

struct net_device {
    int ifindex;
};

struct inet6_dev {
    struct net_device *dev;
};

struct prefix_info {
    uint8_t prefix_len;
    uint8_t type;
    uint8_t onlink;
    uint8_t autoconf;
    struct in6_addr prefix;
    uint32_t prefered;
    uint32_t valid;
};

struct nlmsghdr {
    uint32_t nlmsg_len;
};

struct prefixmsg {
    uint8_t prefix_family;
    uint8_t prefix_pad1;
    uint16_t prefix_pad2;
    int32_t prefix_ifindex;
    uint8_t prefix_len;
    uint8_t prefix_type;
    uint16_t prefix_pad3;
    uint32_t prefix_flags;
};

struct prefix_cacheinfo {
    uint32_t preferred_time;
    uint32_t valid_time;
};

#define NLMSG_NEW(skb, pid, seq, type, len, flags) \
    ({ (void)(skb); (void)(pid); (void)(seq); (void)(type); (void)(len); (void)(flags); (struct nlmsghdr *)0; })

#define NLMSG_DATA(nlh) \
    ({ (void)(nlh); (struct prefixmsg *)0; })

#define RTA_PUT(skb, attrtype, attrlen, data) \
    ({ (void)(skb); (void)(attrtype); (void)(attrlen); (void)(data); 0; })

static inline void skb_trim(struct sk_buff *skb, unsigned int len) {
    (void)skb; (void)len;
}