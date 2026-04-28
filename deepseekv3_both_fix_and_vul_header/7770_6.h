#include <stdlib.h>
#include <string.h>

#define NID_id_GostR3410_2001 1
#define NID_id_GostR3410_2001DH 2
#define NID_id_Gost28147_89_CryptoPro_A_ParamSet 3
#define NID_id_tc26_gost_28147_param_Z 4
#define NID_id_GostR3411_2012_512 5
#define NID_id_GostR3411_2012_256 6
#define NID_undef 0
#define EVP_PKEY_CTRL_PEER_KEY 1

#define GOST_F_PKEY_GOST_ECCP_ENCRYPT 1
#define GOST_R_RNG_ERROR 1
#define GOST_R_NO_PRIVATE_PART_OF_NON_EPHEMERAL_KEYPAIR 2
#define GOST_R_ERROR_COMPUTING_SHARED_KEY 3
#define GOST_R_CANNOT_PACK_EPHEMERAL_KEY 4
#define GOST_R_CTRL_CALL_FAILED 5
#define GOST_R_INVALID_BUFFER_SIZE 6
#define ERR_R_ASN1_LIB 7

typedef struct EVP_PKEY_CTX EVP_PKEY_CTX;
typedef struct EVP_PKEY EVP_PKEY;
typedef struct EC_KEY EC_KEY;
typedef struct ASN1_OBJECT ASN1_OBJECT;
typedef struct ASN1_OCTET_STRING ASN1_OCTET_STRING;
typedef struct X509_PUBKEY X509_PUBKEY;

struct gost_pmeth_data {
    unsigned char *shared_ukm;
    size_t shared_ukm_size;
};

struct gost_cipher_info {
    int nid;
    const unsigned char *sblock;
};

struct gost_ctx {
    unsigned char key[32];
    unsigned char sbox[1024];
};

typedef struct GOST_KEY_TRANSPORT GOST_KEY_TRANSPORT;
typedef struct GOST_key_info GOST_key_info;
typedef struct GOST_key_agreement_info GOST_key_agreement_info;

struct GOST_key_info {
    ASN1_OCTET_STRING *encrypted_key;
    ASN1_OCTET_STRING *imit;
};

struct GOST_key_agreement_info {
    ASN1_OBJECT *cipher;
    X509_PUBKEY *ephem_key;
    ASN1_OCTET_STRING *eph_iv;
};

struct GOST_KEY_TRANSPORT {
    GOST_key_agreement_info *key_agreement_info;
    GOST_key_info *key_info;
};

int EVP_PKEY_base_id(EVP_PKEY *pkey);
int EVP_PKEY_get_default_digest_nid(EVP_PKEY *pkey, int *pnid);
int EVP_PKEY_CTX_ctrl(EVP_PKEY_CTX *ctx, int keytype, int optype, int cmd, int p1, void *p2);
EVP_PKEY *EVP_PKEY_CTX_get0_pkey(EVP_PKEY_CTX *ctx);
EVP_PKEY *EVP_PKEY_CTX_get0_peerkey(EVP_PKEY_CTX *ctx);
struct gost_pmeth_data *EVP_PKEY_CTX_get_data(EVP_PKEY_CTX *ctx);
EVP_PKEY *EVP_PKEY_new();
int EVP_PKEY_assign(EVP_PKEY *pkey, int type, void *key);
int EVP_PKEY_copy_parameters(EVP_PKEY *to, EVP_PKEY *from);
void *EVP_PKEY_get0(EVP_PKEY *pkey);
void EVP_PKEY_free(EVP_PKEY *pkey);

EC_KEY *EC_KEY_new();
void *EC_KEY_get0_public_key(EC_KEY *key);

ASN1_OBJECT *OBJ_nid2obj(int nid);
void ASN1_OBJECT_free(ASN1_OBJECT *a);
int ASN1_OCTET_STRING_set(ASN1_OCTET_STRING *str, const void *data, int len);

int X509_PUBKEY_set(X509_PUBKEY **x, EVP_PKEY *pkey);

int RAND_bytes(unsigned char *buf, int num);

void GOSTerr(int f, int r);
void OPENSSL_cleanse(void *ptr, size_t len);

GOST_KEY_TRANSPORT *GOST_KEY_TRANSPORT_new();
void GOST_KEY_TRANSPORT_free(GOST_KEY_TRANSPORT *a);
int i2d_GOST_KEY_TRANSPORT(GOST_KEY_TRANSPORT *a, unsigned char **pp);

const struct gost_cipher_info *get_encryption_params(ASN1_OBJECT *obj);
int gost_get0_priv_key(EVP_PKEY *pkey);
int gost_ec_keygen(EC_KEY *ec);
int VKO_compute_key(unsigned char *shared_key, void *pub_key, void *priv_key, unsigned char *ukm, int ukm_len, int dgst_nid);
void gost_init(struct gost_ctx *ctx, const unsigned char *sblock);
void keyWrapCryptoPro(struct gost_ctx *ctx, unsigned char *shared_key, unsigned char *ukm, const unsigned char *in, unsigned char *out);

/* 添加 typedef 解决 gost_ctx 类型问题 */
typedef struct gost_ctx gost_ctx;