#include <stdint.h>
#include <stddef.h>

typedef uint16_t u16;

typedef struct sk_buff {
    struct sock *sk;
} sk_buff;

typedef struct nlmsghdr {
    int nlmsg_type;
    int nlmsg_flags;
} nlmsghdr;

typedef struct net {
    void *user_ns;
    struct sock *rtnl;
} net;

typedef struct sock sock;
typedef struct netlink_callback netlink_callback;

typedef int (*rtnl_doit_func)(struct sk_buff *, struct nlmsghdr *);
typedef int (*rtnl_dumpit_func)(struct sk_buff *, struct netlink_callback *);
typedef uint16_t (*rtnl_calcit_func)(struct sk_buff *, struct nlmsghdr *);

struct rtgenmsg {
    unsigned char rtgen_family;
};

struct netlink_dump_control {
    rtnl_dumpit_func dump;
    uint16_t min_dump_alloc;
};

#define RTM_MAX 1024
#define RTM_BASE 0
#define NLM_F_DUMP (1 << 0)
#define CAP_NET_ADMIN 12
#define EOPNOTSUPP 95
#define EPERM 1

static inline size_t nlmsg_len(const struct nlmsghdr *nlh) { return 0; }
static inline void *nlmsg_data(const struct nlmsghdr *nlh) { return NULL; }
static inline int ns_capable(void *ns, int cap) { return 0; }
static inline void __rtnl_unlock(void) {}
static inline void rtnl_lock(void) {}
static inline rtnl_doit_func rtnl_get_doit(int family, int type) { return NULL; }
static inline rtnl_dumpit_func rtnl_get_dumpit(int family, int type) { return NULL; }
static inline rtnl_calcit_func rtnl_get_calcit(int family, int type) { return NULL; }
static inline int netlink_dump_start(struct sock *sk, struct sk_buff *skb, struct nlmsghdr *nlh, struct netlink_dump_control *c) { return 0; }
static inline struct net *sock_net(struct sock *sk) { return NULL; }