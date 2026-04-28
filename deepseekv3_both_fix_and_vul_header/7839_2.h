#include <stdlib.h>
#include <errno.h>

struct nft_ctx;
struct nlattr;
struct module;

struct nft_expr;
struct nft_expr_info {
    struct {
        struct {
            unsigned int flags;
            struct module *owner;
            void (*release_ops)(void *);
        } *type;
        size_t size;
    } *ops;
};

#define GFP_KERNEL_ACCOUNT 0
#define NFT_EXPR_STATEFUL (1 << 0)
#define ERR_PTR(e) ((void *)(long)(e))

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline void module_put(struct module *mod) {
}

static inline int nf_tables_expr_parse(const struct nft_ctx *ctx, const struct nlattr *nla, struct nft_expr_info *expr_info) {
    return -1;
}

static inline int nf_tables_newexpr(const struct nft_ctx *ctx, const struct nft_expr_info *expr_info, struct nft_expr *expr) {
    return -1;
}