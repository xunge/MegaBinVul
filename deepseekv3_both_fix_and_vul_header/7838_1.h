#include <stddef.h>

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define ERR_PTR(x) ((void *)((long)(x)))
#define PTR_ERR(x) ((long)(x))

#define EOPNOTSUPP 95

struct nft_ctx;
struct nft_set;
struct nlattr;
struct nft_expr;

struct nft_expr_ops {
    struct {
        unsigned int flags;
    } *type;
};

struct nft_set_ops {
    void (*gc_init)(struct nft_set *);
};

struct nft_set {
    unsigned int flags;
    const struct nft_set_ops *ops;
};

struct nft_expr {
    const struct nft_expr_ops *ops;
};

#define NFT_EXPR_STATEFUL 0x1
#define NFT_EXPR_GC 0x2
#define NFT_SET_TIMEOUT 0x1

struct nft_expr *nft_expr_init(const struct nft_ctx *ctx, const struct nlattr *attr);
void nft_expr_destroy(const struct nft_ctx *ctx, struct nft_expr *expr);