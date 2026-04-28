#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct BI_CTX {
    int mod_offset;
} BI_CTX;

typedef struct bigint bigint;

#define BIGINT_M_OFFSET 0
#define SIG_TYPE_MD5 0
#define SIG_TYPE_SHA1 1
#define SIG_TYPE_SHA256 2
#define SIG_TYPE_SHA384 3
#define SIG_TYPE_SHA512 4

static const uint8_t sig_prefix_md5[] = { /* MD5 prefix data */ };
static const uint8_t sig_prefix_sha1[] = { /* SHA1 prefix data */ };
static const uint8_t sig_prefix_sha256[] = { /* SHA256 prefix data */ };
static const uint8_t sig_prefix_sha384[] = { /* SHA384 prefix data */ };
static const uint8_t sig_prefix_sha512[] = { /* SHA512 prefix data */ };

extern bigint *bi_import(BI_CTX *ctx, const uint8_t *data, int len);
extern bigint *bi_mod_power2(BI_CTX *ctx, bigint *bi, bigint *modulus, bigint *pub_exp);
extern void bi_export(BI_CTX *ctx, bigint *bi, uint8_t *data, int len);
extern void bi_clear_cache(BI_CTX *ctx);
extern const uint8_t *get_signature(const uint8_t *data, int *len);
extern int memcmp_P(const void *s1, const void *s2, size_t n);