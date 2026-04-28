#include <stdint.h>
#include <net/if.h>
#include <linux/netlink.h>

typedef uint8_t u8;
typedef uint32_t u32;

#define MAX_ADDR_LEN 32
#define DCB_ATTR_PERM_HWADDR 1
#define EOPNOTSUPP 95

struct net_device {
    struct dcb_ops *dcbnl_ops;
};

struct dcb_ops {
    void (*getpermhwaddr)(struct net_device *, u8 *);
};

struct nlmsghdr;
struct nlattr;
struct sk_buff;

int nla_put(struct sk_buff *skb, int attrtype, int attrlen, const void *data);