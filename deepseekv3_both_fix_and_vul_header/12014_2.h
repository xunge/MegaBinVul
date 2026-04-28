#include <stdint.h>
#include <stddef.h>

struct sk_buff {
    int dummy;
};

struct nfnl_info {
    struct netlink_ext_ack *extack;
    struct net *net;
    struct {
        uint8_t nfgen_family;
    } *nfmsg;
    struct {
        int nlmsg_type;
        int nlmsg_flags;
    } *nlh;
};

struct nlattr {
    int dummy;
};

struct netlink_ext_ack {
    int dummy;
};

struct net {
    int dummy;
};

struct nft_table {
    uint8_t family;
    int dummy;
};

struct nft_chain {
    uint32_t flags;
    uint32_t use;
    struct {
        struct nft_rule *next;
    } rules;
};

struct nft_rule {
    struct nft_rule *next;
    int dummy;
};

struct nft_ctx {
    int dummy;
};

struct nft_base_chain {
    struct {
        int hooknum;
    } ops;
    int dummy;
};

#define NFTA_CHAIN_TABLE 0
#define NFTA_CHAIN_HANDLE 0
#define NFTA_CHAIN_NAME 0
#define NFTA_CHAIN_HOOK 0
#define NFT_MSG_DESTROYCHAIN 0
#define NFT_CHAIN_HW_OFFLOAD (1 << 0)
#define NLM_F_NONREC (1 << 0)
#define ENOENT 2
#define EOPNOTSUPP 95
#define EBUSY 16

#define IS_ERR(x) 0
#define PTR_ERR(x) 0
#define NL_SET_BAD_ATTR(x, y)
#define nft_genmask_next(x) 0
#define nft_table_lookup(w, x, y, z, a) NULL
#define nft_chain_lookup_byhandle(x, y, z) NULL
#define nft_chain_lookup(x, y, z, a) NULL
#define nft_ctx_init(x, y, z, a, b, c, d, e)
#define nft_is_base_chain(x) 0
#define nft_base_chain(x) NULL
#define nft_base_chain_netdev(x, y) 0
#define nft_delchain_hook(x, y, z) 0
#define nft_is_active_next(x, y) 0
#define nft_delrule(x, y) 0
#define nft_delchain(x) 0
#define NFNL_MSG_TYPE(x) 0
#define NETLINK_CB(x) {0}

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;

static inline uint64_t be64_to_cpu(uint64_t x) { return x; }
static inline uint64_t nla_get_be64(const struct nlattr *attr) { return 0; }

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))(head)->next; pos != (typeof(pos))(head); pos = pos->next)