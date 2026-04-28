#include <stdint.h>
#include <string.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef struct request REQUEST;
typedef struct pwd_session_t {
    void *group;
    void *pwe;
    void *order;
    void *prime;
    void *bnctx;
    uint16_t group_num;
} pwd_session_t;

typedef struct BIGNUM BIGNUM;
typedef struct HMAC_CTX HMAC_CTX;
typedef struct EVP_MD_CTX EVP_MD_CTX;
typedef struct EVP_PKEY EVP_PKEY;

#define SHA256_DIGEST_LENGTH 32
#define NID_X9_62_prime256v1 0
#define NID_secp384r1 0
#define NID_secp521r1 0
#define NID_X9_62_prime192v1 0
#define NID_secp224r1 0
#define EVP_PKEY_HMAC 0

extern uint8_t allzero[SHA256_DIGEST_LENGTH];
extern BIGNUM *consttime_BN(void);
extern int legendre(BIGNUM *a, BIGNUM *p, void *ctx);
extern void do_equation(const void *group, BIGNUM *y_sqrd, const BIGNUM *x, void *ctx);
extern int is_quadratic_residue(const BIGNUM *y_sqrd, const BIGNUM *p, const BIGNUM *qr, const BIGNUM *qnr, void *ctx);
extern void eap_pwd_kdf(uint8_t *key, int keylen, char const *label, int labellen, uint8_t *result, int resultbitlen);
extern int const_time_memcmp(const void *a, const void *b, size_t len);
extern unsigned int const_time_fill_msb(unsigned int a);
extern int const_time_select(int mask, int a, int b);
extern int const_time_eq(int a, int b);
extern void const_time_select_bin(int mask, const void *a, const void *b, size_t len, void *dst);
extern void pwd_hmac_final(HMAC_CTX *ctx, uint8_t *digest);

extern HMAC_CTX *HMAC_CTX_new(void);
extern void HMAC_CTX_free(HMAC_CTX *ctx);
extern int HMAC_Init_ex(HMAC_CTX *ctx, const void *key, int keylen, const void *md, void *impl);
extern int HMAC_Update(HMAC_CTX *ctx, const unsigned char *data, size_t len);

extern EVP_MD_CTX *EVP_MD_CTX_new(void);
extern void EVP_MD_CTX_free(EVP_MD_CTX *ctx);
extern int EVP_DigestSignInit(EVP_MD_CTX *ctx, void *pctx, const void *type, void *e, EVP_PKEY *pkey);
extern int EVP_DigestSignUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt);
extern int EVP_DigestSignFinal(EVP_MD_CTX *ctx, unsigned char *sig, size_t *siglen);
extern void EVP_MD_CTX_reset(EVP_MD_CTX *ctx);
extern EVP_PKEY *EVP_PKEY_new_mac_key(int type, void *e, const unsigned char *key, int keylen);
extern void EVP_PKEY_free(EVP_PKEY *pkey);

extern void *EC_GROUP_new_by_curve_name(int nid);
extern void *EC_POINT_new(const void *group);
extern int EC_GROUP_get_curve(const void *group, void *p, void *a, void *b, void *ctx);
extern int EC_GROUP_get_order(const void *group, void *order, void *ctx);
extern int EC_POINT_set_compressed_coordinates(const void *group, void *point, const BIGNUM *x, int y_bit, void *ctx);
extern int EC_POINT_set_affine_coordinates(const void *group, void *point, const BIGNUM *x, const BIGNUM *y, void *ctx);

extern int BN_num_bits(const BIGNUM *a);
extern int BN_num_bytes(const BIGNUM *a);
extern int BN_rand_range(BIGNUM *rnd, const BIGNUM *range);
extern int BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
extern int BN_bn2bin(const BIGNUM *a, unsigned char *to);
extern int BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret);
extern int BN_is_odd(const BIGNUM *a);
extern void BN_clear_free(BIGNUM *a);
extern const BIGNUM *BN_value_one(void);
extern int BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
extern int BN_rshift(BIGNUM *r, const BIGNUM *a, int n);
extern int BN_mod_exp_mont_consttime(BIGNUM *rr, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, void *ctx, void *in_mont);
extern void *EVP_sha256(void);

extern void *talloc_zero_array(const void *ctx, size_t size, size_t count);
extern void talloc_free(void *ptr);

extern void DEBUG(const char *fmt, ...);

#define MEM(ptr) do { if ((ptr) == NULL) { DEBUG("memory allocation failed"); goto fail; } } while(0)

#define talloc_zero_array(ctx, type, count) talloc_zero_array(ctx, sizeof(type), count)