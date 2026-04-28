#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    void *group;
    void *pwe;
    void *order;
    void *prime;
    int group_num;
} pwd_session_t;

#define SHA256_DIGEST_LENGTH 32
#define NID_X9_62_prime256v1 0
#define NID_secp384r1 0
#define NID_secp521r1 0
#define NID_X9_62_prime192v1 0
#define NID_secp224r1 0

#define talloc_zero_array(ctx, type, num) calloc(num, sizeof(type))
#define talloc_free(ptr) free(ptr)
#define DEBUG(fmt, ...)

typedef struct {} BIGNUM;
typedef struct {} EC_GROUP;
typedef struct {} EC_POINT;
typedef struct {} HMAC_CTX;

BIGNUM *BN_new(void) { return NULL; }
void BN_clear_free(BIGNUM *bn) {}
int BN_num_bits(BIGNUM *bn) { return 0; }
int BN_num_bytes(BIGNUM *bn) { return 0; }
int BN_is_odd(BIGNUM *bn) { return 0; }
int BN_ucmp(BIGNUM *a, BIGNUM *b) { return 0; }
void BN_rshift(BIGNUM *r, BIGNUM *a, int n) {}
void BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret) {}
int BN_cmp(BIGNUM *a, BIGNUM *b) { return 0; }
BIGNUM *BN_value_one(void) { return NULL; }

EC_GROUP *EC_GROUP_new_by_curve_name(int nid) { return NULL; }
EC_POINT *EC_POINT_new(EC_GROUP *group) { return NULL; }
int EC_GROUP_get_curve_GFp(EC_GROUP *group, BIGNUM *p, BIGNUM *a, BIGNUM *b, void *ctx) { return 0; }
int EC_GROUP_get_order(EC_GROUP *group, BIGNUM *order, void *ctx) { return 0; }
int EC_GROUP_get_cofactor(EC_GROUP *group, BIGNUM *cofactor, void *ctx) { return 0; }
int EC_POINT_set_compressed_coordinates_GFp(EC_GROUP *group, EC_POINT *p, BIGNUM *x, int y_bit, void *ctx) { return 0; }
int EC_POINT_is_on_curve(EC_GROUP *group, EC_POINT *point, void *ctx) { return 0; }
int EC_POINT_mul(EC_GROUP *group, EC_POINT *r, BIGNUM *n, EC_POINT *q, BIGNUM *m, void *ctx) { return 0; }
int EC_POINT_is_at_infinity(EC_GROUP *group, EC_POINT *p) { return 0; }

HMAC_CTX *HMAC_CTX_new(void) { return NULL; }
void HMAC_CTX_free(HMAC_CTX *ctx) {}
void H_Init(HMAC_CTX *ctx) {}
void H_Update(HMAC_CTX *ctx, const unsigned char *data, size_t len) {}
void H_Final(HMAC_CTX *ctx, unsigned char *md) {}

int eap_pwd_kdf(const uint8_t *key, int key_len, const char *label, int label_len, uint8_t *result, int result_bitlen) { return 0; }