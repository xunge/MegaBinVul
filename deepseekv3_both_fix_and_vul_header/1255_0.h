#include <stdint.h>
#include <gmp.h>

struct rsa_private_key {
    size_t size;
};

struct sha256_ctx {
};

#define SHA256_DIGEST_SIZE 32
#define SHA1_DIGEST_SIZE 20

extern const struct nettle_hash nettle_sha256;
typedef void nettle_hash_init_func(void *ctx);
typedef void nettle_hash_update_func(void *ctx, size_t length, const uint8_t *data);
typedef void nettle_hash_digest_func(void *ctx, size_t length, uint8_t *digest);

void sha256_init(struct sha256_ctx *ctx);
void sha256_update(struct sha256_ctx *ctx, size_t length, const uint8_t *data);
void sha256_digest(struct sha256_ctx *ctx, size_t length, uint8_t *digest);

size_t nettle_mpz_sizeinbase_256_u(const mpz_t x);
void rsa_compute_root(const struct rsa_private_key *key, mpz_t x, const mpz_t m);
int pkcs1_oaep_decrypt(size_t key_size, mpz_t m, size_t hash_size,
                      struct sha256_ctx *hash_ctx, const struct nettle_hash *hash,
                      nettle_hash_init_func *hash_init, nettle_hash_update_func *hash_update, nettle_hash_digest_func *hash_digest,
                      size_t label_length, const uint8_t *label, size_t *length, uint8_t *message);