#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t keylen;
    size_t ivlen;
    unsigned int tlsversion;
} PROV_CIPHER_CTX;

typedef struct {
    PROV_CIPHER_CTX base;
    size_t tls_aad_pad_sz;
} PROV_RC4_HMAC_MD5_CTX;

typedef struct {
    int data_type;
    void *data;
    size_t data_size;
} OSSL_PARAM;

#define ERR_LIB_PROV 0
#define PROV_R_FAILED_TO_GET_PARAMETER 0
#define PROV_R_INVALID_KEY_LENGTH 0
#define PROV_R_INVALID_IV_LENGTH 0
#define PROV_R_INVALID_DATA 0

#define OSSL_PARAM_OCTET_STRING 1

#define OSSL_CIPHER_PARAM_KEYLEN "keylen"
#define OSSL_CIPHER_PARAM_IVLEN "ivlen"
#define OSSL_CIPHER_PARAM_AEAD_TLS1_AAD "tls1aad"
#define OSSL_CIPHER_PARAM_AEAD_MAC_KEY "mackey"
#define OSSL_CIPHER_PARAM_TLS_VERSION "tlsversion"

typedef struct {
    size_t (*tls_init)(PROV_CIPHER_CTX *ctx, void *data, size_t data_size);
    void (*init_mackey)(PROV_CIPHER_CTX *ctx, void *data, size_t data_size);
} RC4_HMAC_MD5_HW;

static RC4_HMAC_MD5_HW *GET_HW(PROV_RC4_HMAC_MD5_CTX *ctx) { return NULL; }

static void ERR_raise(int lib, int reason) {}
static const OSSL_PARAM *OSSL_PARAM_locate_const(const OSSL_PARAM *params, const char *name) { return NULL; }
static int OSSL_PARAM_get_size_t(const OSSL_PARAM *p, size_t *val) { return 0; }
static int OSSL_PARAM_get_uint(const OSSL_PARAM *p, unsigned int *val) { return 0; }