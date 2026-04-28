#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#define NFTA_VERDICT_MAX 3
#define NFTA_VERDICT_CODE 1
#define NFTA_VERDICT_CHAIN 2
#define NFTA_VERDICT_CHAIN_ID 3

#define NFT_CONTINUE 0
#define NFT_BREAK 1
#define NFT_RETURN 2
#define NFT_JUMP 3
#define NFT_GOTO 4

#define NF_VERDICT_MASK 0x000000ff
#define NF_ACCEPT 1
#define NF_DROP 2
#define NF_QUEUE 3

#define NFT_DATA_DESC_SETELEM (1 << 0)
#define NFT_CHAIN_BINDING (1 << 0)

#define fallthrough __attribute__((fallthrough))

typedef uint32_t __be32;
typedef uint8_t u8;

struct nlattr {
    int dummy;
};

struct nft_ctx {
    void *net;
    void *table;
};

struct nft_data {
    struct {
        int code;
        struct nft_chain *chain;
    } verdict;
};

struct nft_data_desc {
    unsigned int flags;
    size_t len;
};

struct nft_chain {
    unsigned int flags;
    unsigned int use;
};

static inline __be32 ntohl(__be32 val) { return val; }
static inline __be32 nla_get_be32(const struct nlattr *nla) { return 0; }

static int nla_parse_nested_deprecated(struct nlattr *tb[], int maxtype,
                                      const struct nlattr *nla,
                                      const void *policy, void *extack) { return 0; }

static struct nft_chain *nft_chain_lookup(void *net, void *table,
                                        const struct nlattr *nla, u8 genmask) { return NULL; }

static struct nft_chain *nft_chain_lookup_byid(void *net, void *table,
                                             const struct nlattr *nla) { return NULL; }

static int nft_is_base_chain(struct nft_chain *chain) { return 0; }
static u8 nft_genmask_next(void *net) { return 0; }

#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)

static const void *nft_verdict_policy;