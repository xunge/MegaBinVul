#include <stddef.h>
#include <string.h>

typedef struct EVP_PKEY_CTX EVP_PKEY_CTX;
typedef struct EVP_PKEY EVP_PKEY;
typedef struct X509_PUBKEY X509_PUBKEY;
typedef struct EC_KEY EC_KEY;
typedef struct EC_POINT EC_POINT;

struct gost_ctx {
    unsigned char data[256];
};

struct gost_cipher_info {
    const unsigned char *sblock;
};

struct gost_key_agreement_info {
    int cipher;
    X509_PUBKEY *ephem_key;
    struct {
        size_t length;
        unsigned char *data;
    } *eph_iv;
};

struct gost_key_info {
    struct {
        size_t length;
        unsigned char *data;
    } *encrypted_key;
    struct {
        size_t length;
        unsigned char *data;
    } *imit;
};

struct GOST_KEY_TRANSPORT {
    struct gost_key_agreement_info *key_agreement_info;
    struct gost_key_info *key_info;
};

#define NID_undef 0
#define NID_id_GostR3411_2012_512 0
#define NID_id_GostR3411_2012_256 0
#define EVP_PKEY_CTRL_PEER_KEY 1

#define GOST_F_PKEY_GOST_ECCP_DECRYPT 0
#define GOST_R_ERROR_PARSING_KEY_TRANSPORT_INFO 0
#define GOST_R_INCOMPATIBLE_PEER_KEY 0
#define GOST_R_CTRL_CALL_FAILED 0
#define GOST_R_NO_PEER_KEY 0
#define GOST_R_ERROR_COMPUTING_SHARED_KEY 0

#define OPENSSL_assert(x)
#define OPENSSL_cleanse(p, l) memset((p), 0, (l))

void GOSTerr(int f, int r);
struct GOST_KEY_TRANSPORT *d2i_GOST_KEY_TRANSPORT(struct GOST_KEY_TRANSPORT **a, const unsigned char **pp, long length);
void GOST_KEY_TRANSPORT_free(struct GOST_KEY_TRANSPORT *a);
EVP_PKEY *X509_PUBKEY_get(X509_PUBKEY *key);
const struct gost_cipher_info *get_encryption_params(int cipher);
void gost_init(struct gost_ctx *ctx, const unsigned char *sblock);
int VKO_compute_key(unsigned char *shared_key, const EC_POINT *pub_key, const EC_KEY *priv_key, const unsigned char *ukm, size_t ukm_len, int digest_nid);
int keyUnwrapCryptoPro(struct gost_ctx *ctx, const unsigned char *sharedKey, const unsigned char *wrappedKey, unsigned char *key);
EVP_PKEY *EVP_PKEY_CTX_get0_pkey(EVP_PKEY_CTX *ctx);
int EVP_PKEY_derive_set_peer(EVP_PKEY_CTX *ctx, EVP_PKEY *peer);
int EVP_PKEY_CTX_ctrl(EVP_PKEY_CTX *ctx, int keytype, int optype, int cmd, int p1, void *p2);
EVP_PKEY *EVP_PKEY_CTX_get0_peerkey(EVP_PKEY_CTX *ctx);
int EVP_PKEY_get_default_digest_nid(EVP_PKEY *pkey, int *pnid);
void *EVP_PKEY_get0(const EVP_PKEY *pkey);
void EVP_PKEY_free(EVP_PKEY *pkey);
EC_POINT *EC_KEY_get0_public_key(const EC_KEY *key);

typedef struct GOST_KEY_TRANSPORT GOST_KEY_TRANSPORT;
typedef struct gost_ctx gost_ctx;