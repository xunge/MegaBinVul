#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

struct sk_buff;
struct nlattr;
struct netlink_ext_ack;
struct net;
struct nft_chain;
struct nft_table;
struct nft_rule;

typedef uint8_t u8;

struct nlmsghdr {
    uint32_t nlmsg_type;
};

struct nfnl_info {
    struct netlink_ext_ack *extack;
    struct net *net;
    struct {
        u8 nfgen_family;
    } *nfmsg;
    struct nlmsghdr *nlh;
};

struct nft_ctx {
    struct net *net;
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
    u8 family;
    struct nft_table *table;
    struct nft_chain *chain;
    const struct nlattr * const *nla;
};

struct NETLINK_CB {
    uint32_t portid;
};

struct list_head {
    struct list_head *next, *prev;
};

struct nft_table {
    struct list_head chains;
};

struct nft_chain {
    struct list_head list;
};

#define NFTA_RULE_TABLE 0
#define NFTA_RULE_CHAIN 1
#define NFTA_RULE_HANDLE 2
#define NFTA_RULE_ID 3
#define NFT_MSG_DESTROYRULE 0
#define ENOENT 2
#define EOPNOTSUPP 95

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000)
#define PTR_ERR(x) ((long)(x))
#define NL_SET_BAD_ATTR(extack, attr) 

#define NETLINK_CB(skb) ((struct NETLINK_CB){0})
#define NFNL_MSG_TYPE(type) (type)

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((head)->next); pos != (typeof(pos))(head); \
         pos = (typeof(pos))(pos->member.next))

static inline u8 nft_genmask_next(struct net *net) { return 0; }
static inline struct nft_table *nft_table_lookup(struct net *net, const struct nlattr *attr, u8 family, u8 genmask, uint32_t portid) { return NULL; }
static inline struct nft_chain *nft_chain_lookup(struct net *net, struct nft_table *table, const struct nlattr *attr, u8 genmask) { return NULL; }
static inline int nft_chain_is_bound(struct nft_chain *chain) { return 0; }
static inline void nft_ctx_init(struct nft_ctx *ctx, struct net *net, struct sk_buff *skb, struct nlmsghdr *nlh, u8 family, struct nft_table *table, struct nft_chain *chain, const struct nlattr * const *nla) {}
static inline struct nft_rule *nft_rule_lookup(struct nft_chain *chain, const struct nlattr *attr) { return NULL; }
static inline struct nft_rule *nft_rule_lookup_byid(struct net *net, struct nft_chain *chain, const struct nlattr *attr) { return NULL; }
static inline int nft_delrule(struct nft_ctx *ctx, struct nft_rule *rule) { return 0; }
static inline int nft_delrule_by_chain(struct nft_ctx *ctx) { return 0; }
static inline int nft_is_active_next(struct net *net, struct nft_chain *chain) { return 1; }