#include <stdint.h>
#include <string.h>

typedef uint16_t u16;
typedef uint32_t u32;

struct sk_buff {
    unsigned int len;
    void* data;
};

struct nlmsghdr {
    u32 nlmsg_len;
};

struct genl_info {
    struct nlmsghdr *nlhdr;
    struct tipc_genlmsghdr *userhdr;
};

struct tipc_genlmsghdr {
    u16 cmd;
    u32 dest;
};

struct netlink_skb_parms {
    u32 portid;
};

#define GENL_HDRLEN 0
#define TIPC_GENL_HDRLEN 0
#define TIPC_CMD_NOT_NET_ADMIN 0
#define CAP_NET_ADMIN 0

static inline void* skb_push(struct sk_buff *skb, unsigned int len) {
    skb->data -= len;
    skb->len += len;
    return skb->data;
}

static inline struct nlmsghdr* nlmsg_hdr(struct sk_buff *skb) {
    return (struct nlmsghdr*)skb->data;
}

static inline size_t nlmsg_total_size(size_t len) {
    return len;
}

static inline void* nlmsg_data(struct nlmsghdr *nlh) {
    return (void*)(nlh + 1);
}

static inline size_t nlmsg_attrlen(struct nlmsghdr *nlh, size_t hdrlen) {
    return 0;
}

static inline int capable(int cap) {
    return 1;
}

static inline int genlmsg_unicast(void *net, struct sk_buff *skb, u32 portid) {
    return 0;
}

static inline struct netlink_skb_parms NETLINK_CB(struct sk_buff *skb) {
    return (struct netlink_skb_parms){0};
}

extern struct sk_buff *tipc_cfg_do_cmd(u32 dest, u16 cmd, void *data, int len, int hdr_space);
extern struct genl_info init_net;