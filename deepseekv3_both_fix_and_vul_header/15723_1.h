#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

struct nft_ctx;
struct nft_set_ext;
struct nft_expr_ops {
    u32 size;
};
struct nft_expr {
    struct nft_expr_ops *ops;
};
struct nft_set_elem_expr {
    u32 size;
};

static inline struct nft_set_elem_expr *nft_set_ext_expr(const struct nft_set_ext *ext) {
    return (struct nft_set_elem_expr *)ext;
}

static inline struct nft_expr *nft_setelem_expr_at(struct nft_set_elem_expr *elem_expr, u32 size) {
    return (struct nft_expr *)((char *)elem_expr + sizeof(*elem_expr) + size);
}

static inline int nft_expr_clone(struct nft_expr *dest, struct nft_expr *src) {
    memcpy(dest, src, src->ops->size);
    return 0;
}

static inline void nft_expr_destroy(struct nft_ctx *ctx, struct nft_expr *expr) {
    free(expr);
}

#define kfree free
#define ENOMEM 12