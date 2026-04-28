#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define TCA_MAX 32
#define TCA_CHAIN 0
#define RTM_GETCHAIN 0
#define RTM_NEWCHAIN 1
#define RTM_DELCHAIN 2
#define RTM_DELTFILTER 3
#define NLM_F_CREATE 0x400
#define NLM_F_EXCL 0x200
#define CAP_NET_ADMIN 12
#define TC_ACT_EXT_VAL_MASK 0xFFFF

typedef uint32_t u32;

struct sk_buff {
    void* sk;
};

struct nlmsghdr {
    int nlmsg_type;
    int nlmsg_flags;
    int nlmsg_seq;
};

struct netlink_ext_ack {
};

struct net {
    void* user_ns;
};

struct nlattr {
};

struct tcmsg {
    u32 tcm_parent;
    int tcm_ifindex;
    int tcm_block_index;
};

struct Qdisc {
};

struct tcf_chain {
    bool explicitly_created;
};

struct tcf_block {
    struct {
        int dummy;
    } lock;
};

struct mutex {
    int dummy;
};

#define IS_ERR(x) 0
#define PTR_ERR(x) 0
#define EPERM 1
#define EINVAL 2
#define EEXIST 3
#define ENOENT 4
#define ENOMEM 5
#define EOPNOTSUPP 6
#define EAGAIN 7

static inline struct net* sock_net(void* sk) { return NULL; }
static inline int netlink_ns_capable(struct sk_buff*, void*, int) { return 0; }
static inline int nlmsg_parse_deprecated(struct nlmsghdr*, int, struct nlattr**, int, void*, struct netlink_ext_ack*) { return 0; }
static inline struct tcmsg* nlmsg_data(struct nlmsghdr*) { return NULL; }
static inline u32 nla_get_u32(struct nlattr*) { return 0; }
static inline void NL_SET_ERR_MSG(struct netlink_ext_ack*, const char*) {}
static inline struct tcf_block* tcf_block_find(struct net*, struct Qdisc**, u32*, unsigned long*, int, int, struct netlink_ext_ack*) { return NULL; }
static inline struct tcf_chain* tcf_chain_lookup(struct tcf_block*, u32) { return NULL; }
static inline int tcf_chain_held_by_acts_only(struct tcf_chain*) { return 0; }
static inline void tcf_chain_hold(struct tcf_chain*) {}
static inline struct tcf_chain* tcf_chain_create(struct tcf_block*, u32) { return NULL; }
static inline int tc_chain_tmplt_add(struct tcf_chain*, struct net*, struct nlattr**, struct netlink_ext_ack*) { return 0; }
static inline int tc_chain_notify(struct tcf_chain*, struct sk_buff*, int, int, int, bool) { return 0; }
static inline void tfilter_notify_chain(struct net*, struct sk_buff*, struct tcf_block*, struct Qdisc*, u32, struct nlmsghdr*, struct tcf_chain*, int) {}
static inline void tcf_chain_flush(struct tcf_chain*, bool) {}
static inline void tcf_chain_put_explicitly_created(struct tcf_chain*) {}
static inline void tcf_chain_put(struct tcf_chain*) {}
static inline void tcf_block_release(struct Qdisc*, struct tcf_block*, bool) {}
static inline void mutex_lock(struct mutex*) {}
static inline void mutex_unlock(struct mutex*) {}

static const void* rtm_tca_policy;