#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <linux/netfilter/nf_tables.h>

typedef uint32_t u32;

struct nft_ctx;
struct nlattr;

struct nft_expr {
    void *ops;
};

struct nft_expr_type {
    const char *name;
};

struct nft_expr_ops {
    const struct nft_expr_type *type;
    int (*init)(const struct nft_ctx *ctx, const struct nft_expr *expr, const struct nlattr * const tb[]);
};

struct nft_expr_info {
    struct nft_expr_ops *ops;
    struct nlattr **tb;
};

struct nft_inner {
    u32 flags;
    u32 hdrsize;
    u32 type;
    struct nft_expr expr;
    int expr_type;
};

#define NFTA_INNER_FLAGS 1
#define NFTA_INNER_HDRSIZE 2
#define NFTA_INNER_TYPE 3
#define NFTA_INNER_EXPR 4
#define NFTA_INNER_NUM 5

#define NFT_INNER_MASK 0x0f
#define NFT_INNER_HDRSIZE 0x01
#define U8_MAX 255
#define NFT_INNER_EXPR_PAYLOAD 0
#define NFT_INNER_EXPR_META 1

#define EINVAL 22
#define EOPNOTSUPP 95

static inline struct nft_inner *nft_expr_priv(const struct nft_expr *expr)
{
    return (struct nft_inner *)expr;
}

static inline uint32_t nla_get_be32(const struct nlattr *attr)
{
    return *(const uint32_t *)attr;
}

static int nft_expr_inner_parse(const struct nft_ctx *ctx, const struct nlattr *attr, struct nft_expr_info *info);