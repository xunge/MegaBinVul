#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <linux/netfilter.h>
#include <linux/netfilter/nf_tables.h>

typedef uint8_t u8;

struct nft_ctx {
    void *net;
    void *table;
};

struct nft_chain {
    unsigned int flags;
    unsigned int use;
};

struct nft_data {
    struct {
        uint32_t code;
        struct nft_chain *chain;
    } verdict;
};

struct nft_data_desc {
    unsigned int len;
    unsigned int flags;
};

struct nlattr;

#define NFTA_VERDICT_MAX (__NFTA_VERDICT_MAX - 1)
#define NFT_DATA_DESC_SETELEM (1 << 0)
#define NFT_CHAIN_BINDING (1 << 0)

#define nft_genmask_next(net) (0)
#define nft_use_inc(use) (1)
#define nft_is_base_chain(chain) (0)
#define nft_chain_is_bound(chain) (0)
#define nft_chain_lookup(net, table, attr, genmask) NULL
#define nft_chain_lookup_byid(net, table, attr, genmask) NULL
#define nft_verdict_policy NULL

#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define EINVAL 22
#define EOPNOTSUPP 95
#define EMFILE 24

#define fallthrough

static inline int nla_parse_nested_deprecated(void *tb, int max, const struct nlattr *nla, const void *policy, void *extack) {
    return 0;
}

static inline uint32_t nla_get_be32(const struct nlattr *nla) {
    return 0;
}