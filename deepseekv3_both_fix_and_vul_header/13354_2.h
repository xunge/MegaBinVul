#include <stddef.h>

struct nft_ctx;
struct nft_expr {
    unsigned char data[0];
};
struct nft_dynset {
    struct {
        int use;
    } *set;
};

static inline void *nft_expr_priv(const struct nft_expr *expr) {
    return (void *)expr + sizeof(*expr);
}