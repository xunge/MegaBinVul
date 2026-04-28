#include <stddef.h>

struct nft_ctx;
struct nft_expr;
struct nft_objref_map {
    struct {
        int use;
    } *set;
};

static inline void *nft_expr_priv(const struct nft_expr *expr);