#include <stddef.h>
#include <stdint.h>

#define TCA_MAX 16
#define TCA_KIND 1
#define CAP_NET_ADMIN 0
#define EPERM 1
#define ENOENT 2
#define ENODEV 19
#define EINVAL 22
#define EOPNOTSUPP 95
#define ENOBUFS 105
#define EAGAIN 11
#define EEXIST 17

enum {
    RTM_GETTFILTER,
    RTM_NEWTFILTER,
    RTM_DELTFILTER
};

#define NLM_F_CREATE 0
#define NLM_F_EXCL 0

#define TC_H_MIN(x) 0
#define TC_H_MAJ(x) 0
#define TC_H_MAKE(x, y) 0
#define TC_H_MAJOR_MASK 0
#define IFNAMSIZ 16
#define GFP_KERNEL 0

typedef int spinlock_t;
typedef unsigned long u32;

struct net;
struct sk_buff {
    void *sk;
};
struct nlmsghdr {
    int nlmsg_type;
    int nlmsg_flags;
};
struct nlattr;
struct tcmsg {
    u32 tcm_info;
    u32 tcm_parent;
    int tcm_ifindex;
    u32 tcm_handle;
};
struct net_device {
    struct Qdisc *qdisc;
};
struct Qdisc {
    u32 handle;
    struct Qdisc_ops *ops;
};
struct Qdisc_ops {
    const struct Qdisc_class_ops *cl_ops;
};
struct Qdisc_class_ops {
    unsigned long (*get)(struct Qdisc *, u32);
    void (*put)(struct Qdisc *, unsigned long);
    struct tcf_proto **(*tcf_chain)(struct Qdisc *, unsigned long);
};
struct tcf_proto {
    struct tcf_proto *next;
    u32 prio;
    u32 protocol;
    const struct tcf_proto_ops *ops;
    struct Qdisc *q;
    void (*classify)(void);
    u32 classid;
};
struct tcf_proto_ops {
    const char *kind;
    int (*init)(struct tcf_proto *);
    int (*delete)(struct tcf_proto *, unsigned long);
    unsigned long (*get)(struct tcf_proto *, u32);
    int (*change)(struct net *, struct sk_buff *, struct tcf_proto *, unsigned long, u32, struct nlattr **, unsigned long *);
    void (*classify)(void);
    struct module *owner;
};
struct module;

static inline struct net *sock_net(void *sk) { return NULL; }
static inline int nlmsg_parse(struct nlmsghdr *n, int len, struct nlattr *attrs[], int max, void *policy) { return 0; }
static inline struct tcmsg *nlmsg_data(const struct nlmsghdr *nlh) { return NULL; }
static inline struct net_device *__dev_get_by_index(struct net *net, int ifindex) { return NULL; }
static inline struct Qdisc *qdisc_lookup(struct net_device *dev, u32 handle) { return NULL; }
static inline spinlock_t *qdisc_root_sleeping_lock(struct Qdisc *q) { return NULL; }
static inline void spin_lock_bh(spinlock_t *lock) {}
static inline void spin_unlock_bh(spinlock_t *lock) {}
static inline void module_put(struct module *module) {}
static inline int nla_strcmp(const struct nlattr *nla, const char *str) { return 0; }
static inline int nla_strlcpy(char *dst, const struct nlattr *nla, int size) { return 0; }
static inline void request_module(const char *fmt, ...) {}
static inline void rtnl_unlock() {}
static inline void rtnl_lock() {}
static inline void kfree(const void *objp) {}
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline const struct tcf_proto_ops *tcf_proto_lookup_ops(struct nlattr *kind) { return NULL; }
static inline int tcf_auto_prio(struct tcf_proto *tp) { return 0; }
static inline int tfilter_notify(struct net *net, struct sk_buff *skb, struct nlmsghdr *n, struct tcf_proto *tp, unsigned long fh, int event) { return 0; }
static inline void tcf_destroy(struct tcf_proto *tp) {}
static inline int capable(int cap) { return 1; }