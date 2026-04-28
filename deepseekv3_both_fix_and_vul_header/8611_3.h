#include <stdint.h>
#include <stdlib.h>

#define NFNL_SUBSYS_COUNT 16
#define NFNL_MSG_BATCH_BEGIN 0
#define NFNL_MSG_BATCH_END 1
#define NLMSG_MIN_TYPE 0x10
#define NFNL_BATCH_FAILURE 0x01
#define NFNL_BATCH_DONE 0x02
#define NFNL_BATCH_REPLAY 0x04
#define NLM_F_REQUEST 1
#define NLM_F_ACK 2
#define EINVAL 22
#define ENOMEM 12
#define EOPNOTSUPP 95
#define EAGAIN 11
#define GFP_KERNEL 0
#define NLMSG_HDRLEN ((int)sizeof(struct nlmsghdr))

typedef uint32_t u32;
typedef uint16_t u_int16_t;
typedef uint8_t u_int8_t;

struct sk_buff {
    unsigned int len;
    void *data;
    void *sk;
};

struct nlmsghdr {
    uint32_t nlmsg_len;
    uint16_t nlmsg_type;
    uint16_t nlmsg_flags;
};

struct net {
    void *nfnl;
};

struct nfnetlink_subsystem {
    unsigned int cb_count;
    struct nfnl_callback *cb;
    int (*commit)(struct net *net, struct sk_buff *skb);
    void (*abort)(struct net *net, struct sk_buff *skb);
};

struct nfnl_callback {
    int (*call_batch)(struct net *net, void *sk, struct sk_buff *skb,
                     const struct nlmsghdr *nlh,
                     const struct nlattr * const cda[]);
    const void *policy;
    unsigned int attr_count;
};

struct nfgenmsg {
    unsigned char nfgen_family;
    unsigned char version;
    uint16_t res_id;
};

struct nlattr {
    uint16_t nla_len;
    uint16_t nla_type;
};

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD(name) struct list_head name = { &(name), &(name) }

static inline uint8_t NFNL_MSG_TYPE(uint16_t type) { return type & 0x00ff; }
static inline uint8_t NFNL_SUBSYS_ID(uint16_t type) { return (type & 0xff00) >> 8; }
static inline struct nlmsghdr *nlmsg_hdr(const struct sk_buff *skb) { return (struct nlmsghdr *)skb->data; }
static inline int nlmsg_len(const struct nlmsghdr *nlh) { return nlh->nlmsg_len - NLMSG_HDRLEN; }
static inline int nlmsg_total_size(int payload) { return ((sizeof(struct nlmsghdr) + payload + 3) & ~3); }
static inline int NLMSG_ALIGN(int len) { return (len + 3) & ~3; }

static void nfnl_lock(uint16_t subsys_id) {}
static void nfnl_unlock(uint16_t subsys_id) {}
static const struct nfnetlink_subsystem *nfnl_dereference_protected(uint16_t subsys_id) { return NULL; }
static const struct nfnl_callback *nfnetlink_find_client(int type, const struct nfnetlink_subsystem *ss) { return NULL; }
static int nfnl_err_add(struct list_head *list, struct nlmsghdr *nlh, int err) { return 0; }
static void nfnl_err_reset(struct list_head *list) {}
static void nfnl_err_deliver(struct list_head *list, struct sk_buff *skb) {}
static struct sk_buff *netlink_skb_clone(struct sk_buff *skb, int gfp) { return NULL; }
static void netlink_ack(struct sk_buff *skb, struct nlmsghdr *nlh, int err) {}
static int nla_parse(struct nlattr **tb, int maxtype, const struct nlattr *head, int len, const void *policy) { return 0; }
static struct net *sock_net(void *sk) { return NULL; }
static void kfree_skb(struct sk_buff *skb) {}
static void skb_pull(struct sk_buff *skb, unsigned int len) {}
static int request_module(const char *name, ...) { return 0; }