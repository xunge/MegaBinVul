#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

typedef uint32_t u32;

struct nft_ctx;
struct nft_set_ext;
struct nft_expr;
struct nft_set_elem_expr;

static inline struct nft_set_elem_expr *nft_set_ext_expr(const struct nft_set_ext *ext);
static inline struct nft_expr *nft_setelem_expr_at(struct nft_set_elem_expr *elem_expr, size_t size);
static inline int nft_expr_clone(struct nft_expr *dest, struct nft_expr *src);
static inline void nft_expr_destroy(struct nft_ctx *ctx, struct nft_expr *expr);

struct nft_expr {
    struct {
        size_t size;
    } *ops;
};

struct nft_set_elem_expr {
    size_t size;
};