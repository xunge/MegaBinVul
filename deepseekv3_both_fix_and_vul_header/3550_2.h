#include <stddef.h>
#include <stdint.h>

#define NLMSG_HDRLEN ((size_t) 0)
#define NFNL_MSG_BATCH_BEGIN 0
#define CAP_NET_ADMIN 0
#define EPERM 1

struct sk_buff {
    void *sk;
    unsigned int len;
};

struct nlmsghdr {
    uint32_t nlmsg_len;
    uint16_t nlmsg_type;
};

struct nfgenmsg {
    uint16_t res_id;
};

struct net {
    void *user_ns;
};

static inline struct nlmsghdr *nlmsg_hdr(struct sk_buff *skb) { return NULL; }
static inline struct net *sock_net(void *sk) { return NULL; }
static inline int ns_capable(void *ns, int cap) { return 0; }
static inline void netlink_ack(struct sk_buff *skb, struct nlmsghdr *nlh, int err) {}
static inline size_t NLMSG_ALIGN(size_t len) { return len; }
static inline struct nfgenmsg *nlmsg_data(struct nlmsghdr *nlh) { return NULL; }
static inline void skb_pull(struct sk_buff *skb, unsigned int len) {}
static inline int nfnetlink_rcv_batch(struct sk_buff *skb, struct nlmsghdr *nlh, uint16_t res_id) { return 0; }
static inline int netlink_rcv_skb(struct sk_buff *skb, void *cb) { return 0; }

extern int nfnetlink_rcv_msg;