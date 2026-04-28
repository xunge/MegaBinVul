#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint32_t u32;

#define NFT_MSG_DESTROYRULE 0
#define NFTA_RULE_TABLE 0
#define NFTA_RULE_CHAIN 0
#define NFTA_RULE_HANDLE 0
#define NFTA_RULE_ID 0
#define ENOENT 2
#define EOPNOTSUPP 95

struct sk_buff;
struct nlattr;
struct netlink_ext_ack;
struct net;
struct nlmsghdr;

struct nfgenmsg {
    u8 nfgen_family;
};

struct nfnl_info {
    struct net *net;
    struct nlmsghdr *nlh;
    struct nfgenmsg *nfmsg;
    struct netlink_ext_ack *extack;
};

struct NETLINK_CB {
    u32 portid;
};

struct list_head {
    struct list_head *next, *prev;
};

struct nft_chain {
    struct list_head list;
};

struct nft_table {
    struct list_head chains;
};

struct nft_rule;

struct nft_ctx {
    struct net *net;
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
    u8 family;
    struct nft_table *table;
    struct nft_chain *chain;
    const struct nlattr * const *nla;
};

#define IS_ERR(x) 0
#define PTR_ERR(x) 0
#define NL_SET_BAD_ATTR(extack, attr) 
#define nft_genmask_next(net) 0
#define nft_table_lookup(net, attr, family, genmask, portid) NULL
#define nft_chain_lookup(net, table, attr, genmask) NULL
#define nft_chain_is_bound(chain) 0
#define nft_ctx_init(ctx, net, skb, nlh, family, table, chain, nla) 
#define nft_rule_lookup(chain, attr) NULL
#define nft_rule_lookup_byid(net, chain, attr) NULL
#define nft_delrule(ctx, rule) 0
#define nft_delrule_by_chain(ctx) 0
#define nft_is_active_next(net, chain) 0
#define NFNL_MSG_TYPE(type) 0

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)))