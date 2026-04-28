#include <stdlib.h>
#include <string.h>

struct gost_pmeth_data {
    int cipher_nid;
    unsigned char shared_ukm[32];
    size_t shared_ukm_size;
};

typedef struct PSKeyTransport_gost {
    void *ukm;
    void *psexp;
    void *ephem_key;
} PSKeyTransport_gost;

#define GOST_F_PKEY_GOST2018_ENCRYPT 0
#define GOST_R_INVALID_CIPHER 1
#define GOST_R_ERROR_COMPUTING_SHARED_KEY 2
#define GOST_R_ERROR_COMPUTING_EXPORT_KEYS 3
#define GOST_R_CANNOT_PACK_EPHEMERAL_KEY 4
#define GOST_R_INVALID_BUFFER_SIZE 5
#define NID_magma_ctr 1
#define NID_magma_mac 2
#define NID_grasshopper_ctr 3
#define NID_grasshopper_mac 4
#define NID_undef 0

typedef void EVP_PKEY_CTX;
typedef void EVP_PKEY;
typedef void EC_KEY;
typedef void EC_POINT;
typedef void ASN1_OCTET_STRING;
typedef void X509_PUBKEY;

#define ERR_R_MALLOC_FAILURE 1
#define ERR_R_INTERNAL_ERROR 2
#define ERR_R_ASN1_LIB 3

void GOSTerr(int a, int b);
void *EVP_PKEY_CTX_get0_pkey(void *ctx);
void *EVP_PKEY_CTX_get_data(void *ctx);
int EVP_PKEY_base_id(void *pkey);
void *EVP_PKEY_CTX_get0_peerkey(void *ctx);
void *EVP_PKEY_new();
int EVP_PKEY_assign(void *pkey, int type, void *key);
int EVP_PKEY_copy_parameters(void *to, void *from);
void *EVP_PKEY_get0(void *pkey);
int gost_ec_keygen(void *ec_key);
int RAND_bytes(unsigned char *buf, int num);
void *EC_KEY_get0_public_key(void *ec_key);
int gost_keg(const unsigned char *ukm, int pkey_nid, void *pub_key, void *priv_key, unsigned char *expkeys);
int gost_kexp15(const unsigned char *key, size_t key_len, int cipher_nid, const unsigned char *mac_key, int mac_nid, const unsigned char *exp_key, const unsigned char *iv, int iv_len, unsigned char *out, int *out_len);
void *PSKeyTransport_gost_new();
void *ASN1_OCTET_STRING_new();
int ASN1_OCTET_STRING_set(void *str, const void *data, int len);
int X509_PUBKEY_set(void **x, void *pkey);
int i2d_PSKeyTransport_gost(void *a, unsigned char **out);
void OPENSSL_cleanse(void *ptr, size_t len);
void EVP_PKEY_free(void *pkey);
void PSKeyTransport_gost_free(void *pst);
void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);
void *EC_KEY_new();