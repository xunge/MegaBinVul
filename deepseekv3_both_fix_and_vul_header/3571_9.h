#include <stddef.h>
#include <string.h>

struct nlattr;
struct sock;
struct netlink_callback;

struct sk_buff {
    void *sk;
    unsigned char cb[48];
};

struct nlmsghdr {
    unsigned int nlmsg_len;
    unsigned int nlmsg_flags;
    unsigned int nlmsg_seq;
};

struct genlmsghdr {
    int cmd;
};

struct netlink_skb_parms {
    unsigned int portid;
};

struct genl_info {
    unsigned int snd_seq;
    unsigned int snd_portid;
    struct nlmsghdr *nlhdr;
    struct genlmsghdr *genlhdr;
    void *userhdr;
    struct nlattr **attrs;
    void *dst_sk;
    void *user_ptr[2];
};

struct genl_ops {
    int cmd;
    unsigned int flags;
    int (*dumpit)(struct sk_buff *, struct netlink_callback *);
    int (*done)(struct netlink_callback *);
    int (*doit)(struct sk_buff *, struct genl_info *);
    const void *policy;
};

struct genl_family {
    int netnsok;
    int hdrsize;
    int maxattr;
    int parallel_ops;
    void *module;
    struct nlattr **attrbuf;
    int (*pre_doit)(const struct genl_ops *, struct sk_buff *, struct genl_info *);
    void (*post_doit)(const struct genl_ops *, struct sk_buff *, struct genl_info *);
};

struct net {
    void *genl_sock;
};

struct netlink_dump_control {
    void *module;
    void *data;
    int (*dump)(struct sk_buff *, struct netlink_callback *);
    int (*done)(struct netlink_callback *);
};

#define NETLINK_CB(skb) (*(struct netlink_skb_parms*)&(skb)->cb[0])

extern struct net init_net;

#define GENL_HDRLEN 0
#define GENL_ADMIN_PERM 0
#define NLM_F_DUMP 0
#define ENOENT 0
#define EOPNOTSUPP 0
#define EPERM 0
#define ENOMEM 0
#define EINVAL 0
#define CAP_NET_ADMIN 0
#define GFP_KERNEL 0

static inline int capable(int cap) { return 1; }
static inline void *kmalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline int net_eq(struct net *net1, struct net *net2) { return 1; }
static inline struct net *sock_net(void *sk) { return NULL; }
static inline void genl_unlock(void) {}
static inline void genl_lock(void) {}
static inline void genl_info_net_set(struct genl_info *info, struct net *net) {}
static inline const struct genl_ops *genl_get_cmd(int cmd, struct genl_family *family) { return NULL; }
static inline int __netlink_dump_start(struct sock *sk, struct sk_buff *skb, struct nlmsghdr *nlh, struct netlink_dump_control *c) { return 0; }
static inline int nlmsg_parse(struct nlmsghdr *nlh, int hdrlen, struct nlattr **tb, int maxtype, const void *policy) { return 0; }
static inline int genl_lock_dumpit(struct sk_buff *skb, struct netlink_callback *cb) { return 0; }
static inline int genl_lock_done(struct netlink_callback *cb) { return 0; }
static inline struct genlmsghdr *nlmsg_data(struct nlmsghdr *nlh) { return NULL; }
static inline size_t nlmsg_msg_size(size_t len) { return len; }