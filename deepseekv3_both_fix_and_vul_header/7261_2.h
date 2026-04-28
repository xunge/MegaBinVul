#include <stddef.h>
#include <stdlib.h>

#define ERR_PTR(err) ((void *)(long)(err))
#define GFP_KERNEL 0
#define EOPNOTSUPP 95
#define ENOMEM 12

struct net;
struct nft_rule;

struct nft_expr_ops {
    int (*offload_action)(struct nft_expr *expr);
    int (*offload)(struct nft_offload_ctx *ctx, struct nft_flow_rule *flow, struct nft_expr *expr);
    unsigned int offload_flags;
};

struct nft_expr {
    struct nft_expr_ops *ops;
};

struct nft_flow_rule {
    int proto;
};

struct nft_offload_ctx {
    struct net *net;
    struct {
        int type;
        int l3num;
    } dep;
};

enum {
    NFT_OFFLOAD_DEP_UNSPEC,
    NFT_OFFLOAD_F_ACTION
};

static inline struct nft_expr *nft_expr_first(const struct nft_rule *rule) { return NULL; }
static inline struct nft_expr *nft_expr_next(const struct nft_expr *expr) { return NULL; }
static inline int nft_expr_more(const struct nft_rule *rule, const struct nft_expr *expr) { return 0; }
static inline struct nft_flow_rule *nft_flow_rule_alloc(int num_actions) { return NULL; }
static inline void nft_flow_rule_destroy(struct nft_flow_rule *flow) {}
static inline void nft_flow_rule_transfer_vlan(struct nft_offload_ctx *ctx, struct nft_flow_rule *flow) {}
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void kfree(const void *objp) {}