#include <stddef.h>

typedef int gnutls_digest_algorithm_t;

struct nettle_hash_ctx {
    void (*update)(struct nettle_hash_ctx *ctx, size_t length, const void *data);
    void (*digest)(struct nettle_hash_ctx *ctx, size_t length, void *digest);
    size_t length;
};

int _ctx_init(gnutls_digest_algorithm_t algo, struct nettle_hash_ctx *ctx);
int gnutls_assert_val(int ret);