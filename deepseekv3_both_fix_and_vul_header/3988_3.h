#include <stdint.h>
#include <stddef.h>

struct sk_buff {
    void *sk;
    int len;
};

struct nlmsghdr {
    uint32_t nlmsg_seq;
};

struct netlink_callback {
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
    unsigned long args[8];
};

struct net;

struct nlattr;

struct xfrm_address_filter {
    uint8_t dummy[32];
};

struct xfrm_state_walk {
    uint8_t dummy[64];  // Ensure this is smaller than cb->args
};

struct xfrm_dump_info {
    struct sk_buff *in_skb;
    struct sk_buff *out_skb;
    uint32_t nlmsg_seq;
    uint16_t nlmsg_flags;
};

typedef uint8_t u8;

#define XFRMA_MAX 64
#define XFRMA_ADDRESS_FILTER 1
#define XFRMA_PROTO 2
#define NLM_F_MULTI 0x2
#define GFP_KERNEL 0
#define ENOMEM 12

#define BUILD_BUG_ON(condition) ((void)0)

static inline struct net *sock_net(void *sk) { return (struct net *)0; }
static inline void *kmemdup(const void *src, size_t len, int gfp) { return (void *)0; }
static inline u8 nla_get_u8(struct nlattr *attr) { return 0; }
static inline void *nla_data(struct nlattr *attr) { return (void *)0; }
static inline int nlmsg_parse(struct nlmsghdr *nlh, int offset, struct nlattr **attrs, 
                           int maxtype, void *policy) { return 0; }
static inline void xfrm_state_walk_init(struct xfrm_state_walk *walk, 
                                     u8 proto, struct xfrm_address_filter *filter) {}
static inline int xfrm_state_walk(struct net *net, struct xfrm_state_walk *walk,
                                int (*callback)(void), struct xfrm_dump_info *info) { return 0; }
static inline int dump_one_state(void) { return 0; }

extern void *xfrma_policy;