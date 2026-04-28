#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <errno.h>

#define TCA_MAX 16
#define TC_ACT_EXT_VAL_MASK 0xFFFFFFF
#define QDISC_CLASS_OPS_DOIT_UNLOCKED 1
#define IFNAMSIZ 16
#define CAP_NET_ADMIN 12
#define NLM_F_CREATE 0x400
#define NLM_F_EXCL 0x200
#define RTM_NEWTFILTER 44
#define TCA_KIND 1
#define TCA_CHAIN 12
#define TCA_ACT_FLAGS_REPLACE (1 << 0)
#define TCA_ACT_FLAGS_NO_RTNL (1 << 1)
#define TCQ_F_CAN_BYPASS (1 << 0)

struct mutex {
    int dummy;
};

struct sk_buff {
    void *sk;
};
struct nlmsghdr {
    uint32_t nlmsg_flags;
};
struct netlink_ext_ack;
struct net {
    void *user_ns;
};
struct nlattr {
    int dummy;
};
struct tcmsg {
    uint32_t tcm_info;
    uint32_t tcm_parent;
    int tcm_ifindex;
    uint32_t tcm_handle;
    uint32_t tcm_block_index;
};
struct Qdisc {
    struct {
        struct {
            int flags;
        } *cl_ops;
    } *ops;
    int flags;
};
struct tcf_chain_info {
    int dummy;
};
struct tcf_chain {
    struct mutex filter_chain_lock;
    bool flushing;
    void *tmplt_ops;
};
struct tcf_block {
    uint32_t classid;
};
struct tcf_proto {
    struct {
        char *kind;
        void *(*get)(struct tcf_proto *, uint32_t);
        int (*change)(void *, struct sk_buff *, struct tcf_proto *, unsigned long, uint32_t, struct nlattr **, void **, uint32_t, struct netlink_ext_ack *);
    } *ops;
};

typedef uint32_t u32;

static struct nlattr *rtm_tca_policy[TCA_MAX + 1];

static inline u32 TC_H_MAJ(u32 val) { return val >> 16; }
static inline u32 TC_H_MIN(u32 val) { return val & 0xFFFF; }
static inline u32 TC_H_MAKE(u32 maj, u32 min) { return (maj << 16) | min; }

static inline void NL_SET_ERR_MSG(struct netlink_ext_ack *extack, const char *msg) {}

static inline struct net *sock_net(void *sk) { return NULL; }
static inline int netlink_ns_capable(struct sk_buff *skb, void *ns, int cap) { return 1; }
static inline int nlmsg_parse_deprecated(struct nlmsghdr *n, int size, struct nlattr **tca, int max, void *policy, struct netlink_ext_ack *extack) { return 0; }
static inline struct tcmsg *nlmsg_data(struct nlmsghdr *n) { return NULL; }
static inline int __tcf_qdisc_find(struct net *net, struct Qdisc **q, u32 *parent, int ifindex, bool unlocked, struct netlink_ext_ack *extack) { return 0; }
static inline int tcf_proto_check_kind(struct nlattr *kind, char *name) { return 0; }
static inline int tcf_proto_is_unlocked(char *name) { return 1; }
static inline void rtnl_lock(void) {}
static inline int __tcf_qdisc_cl_find(struct Qdisc *q, u32 parent, unsigned long *cl, int ifindex, struct netlink_ext_ack *extack) { return 0; }
static inline struct tcf_block *__tcf_block_find(struct net *net, struct Qdisc *q, unsigned long cl, int ifindex, u32 block_index, struct netlink_ext_ack *extack) { return NULL; }
static inline int IS_ERR(void *ptr) { return 0; }
static inline int PTR_ERR(void *ptr) { return 0; }
static inline u32 nla_get_u32(struct nlattr *nla) { return 0; }
static inline struct tcf_chain *tcf_chain_get(struct tcf_block *block, u32 chain_index, bool create) { return NULL; }
static inline void mutex_lock(struct mutex *lock) {}
static inline struct tcf_proto *tcf_chain_tp_find(struct tcf_chain *chain, struct tcf_chain_info *chain_info, u32 protocol, u32 prio, bool prio_allocate) { return NULL; }
static inline u32 tcf_auto_prio(struct tcf_proto *tp) { return 0; }
static inline struct tcf_proto *tcf_chain_tp_prev(struct tcf_chain *chain, struct tcf_chain_info *chain_info) { return NULL; }
static inline void mutex_unlock(struct mutex *lock) {}
static inline struct tcf_proto *tcf_proto_create(char *name, u32 protocol, u32 prio, struct tcf_chain *chain, bool rtnl_held, struct netlink_ext_ack *extack) { return NULL; }
static inline struct tcf_proto *tcf_chain_tp_insert_unique(struct tcf_chain *chain, struct tcf_proto *tp_new, u32 protocol, u32 prio, bool rtnl_held) { return NULL; }
static inline int nla_strcmp(struct nlattr *nla, char *str) { return 0; }
static inline void tfilter_put(struct tcf_proto *tp, void *fh) {}
static inline void tfilter_notify(struct net *net, struct sk_buff *skb, struct nlmsghdr *n, struct tcf_proto *tp, struct tcf_block *block, struct Qdisc *q, u32 parent, void *fh, int type, bool unicast, bool rtnl_held) {}
static inline void tcf_chain_tp_delete_empty(struct tcf_chain *chain, struct tcf_proto *tp, bool rtnl_held, struct netlink_ext_ack *extack) {}
static inline void tcf_proto_put(struct tcf_proto *tp, bool rtnl_held, struct netlink_ext_ack *extack) {}
static inline void tcf_chain_put(struct tcf_chain *chain) {}
static inline void tcf_block_release(struct Qdisc *q, struct tcf_block *block, bool rtnl_held) {}
static inline void rtnl_unlock(void) {}