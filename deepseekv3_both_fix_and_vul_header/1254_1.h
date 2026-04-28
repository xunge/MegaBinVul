#include <stdint.h>
#include <gmp.h>

struct rsa_private_key {
    size_t size;
    // 其他必要的成员变量
};

struct sha1_ctx {
    // SHA-1上下文结构体定义
    uint32_t state[5];
    uint64_t count;
    uint8_t buffer[64];
};

typedef void (*nettle_hash_init_func)(void *ctx);
typedef void (*nettle_hash_update_func)(void *ctx, size_t length, const uint8_t *data);
typedef void (*nettle_hash_digest_func)(void *ctx, size_t length, uint8_t *digest);

extern void rsa_compute_root(const struct rsa_private_key *key, mpz_t x, const mpz_t m);
extern int pkcs1_oaep_decrypt(size_t key_size, mpz_t m, size_t hash_size, void *hash_ctx, const void *hash, nettle_hash_init_func hash_init, nettle_hash_update_func hash_update, nettle_hash_digest_func hash_digest, size_t label_length, const uint8_t *label, size_t *length, uint8_t *message);

#define SHA1_DIGEST_SIZE 20

extern const void *nettle_sha1;
extern void sha1_init(struct sha1_ctx *ctx);
extern void sha1_update(struct sha1_ctx *ctx, size_t length, const uint8_t *data);
extern void sha1_digest(struct sha1_ctx *ctx, size_t length, uint8_t *digest);