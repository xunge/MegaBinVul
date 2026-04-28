#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPENSSL_NO_RSA
#define OPENSSL_NO_DH
#define OPENSSL_NO_ECDH
#define OPENSSL_NO_PSK
#define OPENSSL_NO_SRP

#define SSL_AD_HANDSHAKE_FAILURE 40
#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_INTERNAL_ERROR 80

#define SSL_F_SSL3_SEND_SERVER_KEY_EXCHANGE 1200

#define SSL_R_ERROR_GENERATING_TMP_RSA_KEY 300
#define SSL_R_MISSING_TMP_RSA_KEY 301
#define SSL_R_MISSING_TMP_DH_KEY 302
#define SSL_R_MISSING_TMP_ECDH_KEY 303
#define SSL_R_UNKNOWN_KEY_EXCHANGE_TYPE 304
#define SSL_R_UNKNOWN_PKEY_TYPE 305
#define SSL_R_ECGROUP_TOO_LARGE_FOR_CIPHER 306
#define SSL_R_UNSUPPORTED_ELLIPTIC_CURVE 307
#define SSL_R_MISSING_SRP_PARAM 308

#define SSL_kRSA 0x0001
#define SSL_kEDH 0x0002
#define SSL_kEECDH 0x0004
#define SSL_kPSK 0x0008
#define SSL_kSRP 0x0010

#define SSL_aNULL 0x0040
#define SSL_aSRP 0x0100

#define NAMED_CURVE_TYPE 3
#define POINT_CONVERSION_UNCOMPRESSED 4

#define NID_undef 0
#define NID_md5_sha1 114

#define SSL_OP_SINGLE_DH_USE 0x00100000L
#define SSL_OP_SINGLE_ECDH_USE 0x00200000L

#define SSL3_AL_FATAL 2
#define SSL3_ST_SW_KEY_EXCH_A 0x230
#define SSL3_ST_SW_KEY_EXCH_B 0x231
#define SSL3_MT_SERVER_KEY_EXCHANGE 12
#define SSL3_RANDOM_SIZE 32
#define MD5_DIGEST_LENGTH 16
#define SHA_DIGEST_LENGTH 20

typedef struct ssl_st SSL;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct cert_st CERT;
typedef struct buf_mem_st BUF_MEM;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct evp_md_ctx_st EVP_MD_CTX;
typedef struct evp_md_st EVP_MD;
typedef struct rsa_st RSA;
typedef struct dh_st DH;
typedef struct ec_key_st EC_KEY;
typedef struct ec_group_st EC_GROUP;
typedef struct ec_point_st EC_POINT;
typedef struct bn_ctx_st BN_CTX;
typedef struct bignum_st BIGNUM;

struct evp_cipher_st {
    unsigned long algorithm_mkey;
    unsigned long algorithm_auth;
};

struct ssl3_state_st {
    unsigned char client_random[SSL3_RANDOM_SIZE];
    unsigned char server_random[SSL3_RANDOM_SIZE];
    struct {
        DH *dh;
        EC_KEY *ecdh;
        RSA *rsa;
        int use_rsa_tmp;
        struct evp_cipher_st *new_cipher;
    } tmp;
};

struct ssl_st {
    SSL_CTX *ctx;
    SSL3_STATE *s3;
    CERT *cert;
    BUF_MEM *init_buf;
    int state;
    int options;
};

struct ssl_ctx_st {
    const EVP_MD *md5;
    const EVP_MD *sha1;
    char *psk_identity_hint;
};

struct cert_st {
    RSA *rsa_tmp;
    RSA *(*rsa_tmp_cb)(SSL *ssl, int is_export, int keylength);
    DH *dh_tmp;
    DH *(*dh_tmp_cb)(SSL *ssl, int is_export, int keylength);
    EC_KEY *ecdh_tmp;
    EC_KEY *(*ecdh_tmp_cb)(SSL *ssl, int is_export, int keylength);
    int ecdh_tmp_auto;
};

struct evp_md_ctx_st {
    int dummy;
};

struct evp_pkey_st {
    int type;
    struct {
        RSA *rsa;
    } pkey;
};

#define SSLerr(f,r) 
#define ERR_R_INTERNAL_ERROR 1
#define ERR_R_DH_LIB 2
#define ERR_R_ECDH_LIB 3
#define ERR_R_MALLOC_FAILURE 4
#define ERR_LIB_BUF 5
#define ERR_LIB_EVP 6
#define ERR_LIB_RSA 7

#define EVP_MD_CTX_init(ctx) memset((ctx), 0, sizeof(*(ctx)))
#define EVP_MD_CTX_cleanup(ctx) 
#define EVP_MD_CTX_set_flags(ctx,flgs) 
#define EVP_PKEY_size(pkey) 128
#define EVP_PKEY_RSA 6

#define BN_num_bytes(a) 128
#define BN_bn2bin(a,b) 1
#define BN_dup(a) NULL
#define BN_CTX_new() NULL
#define BN_CTX_free(ctx) 

#define DHparams_dup(dh) NULL
#define DH_generate_key(dh) 1

#define EC_KEY_new_by_curve_name(nid) NULL
#define EC_KEY_dup(ec) NULL
#define EC_KEY_generate_key(ec) 1
#define EC_KEY_get0_public_key(ec) NULL
#define EC_KEY_get0_private_key(ec) NULL
#define EC_KEY_get0_group(ec) NULL
#define EC_GROUP_get_curve_name(group) 0
#define EC_GROUP_get_degree(group) 0
#define EC_POINT_point2oct(grp,pt,form,buf,len,ctx) 0

#define RSA_sign(type,m,mlen,sig,slen,rsa) 1
#define RSA_up_ref(rsa) 

#define BUF_MEM_grow_clean(buf,len) 1

#define OPENSSL_malloc(size) malloc(size)
#define OPENSSL_free(addr) free(addr)

#define SSL_C_IS_EXPORT(c) 0
#define SSL_C_EXPORT_PKEYLENGTH(c) 0
#define SSL_USE_SIGALGS(s) 0
#define SSL_HM_HEADER_LENGTH(s) 4

#define tls1_shared_curve(s,n) 0
#define tls1_ec_nid2curve_id(nid) 0
#define tls12_get_sigandhash(p,pkey,md) 0
#define ssl_get_sign_pkey(s,c,md) NULL
#define ssl_handshake_start(s) NULL
#define ssl_set_handshake_header(s,mt,len) 
#define ssl_do_write(s) 1
#define ssl3_send_alert(s,level,desc) 
#define s2n(s,l) 

#define SSL_ST_ERR 0x1000

int EVP_SignInit_ex(EVP_MD_CTX *ctx, const EVP_MD *type, void *engine) { return 1; }
int EVP_SignUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt) { return 1; }
int EVP_SignFinal(EVP_MD_CTX *ctx, unsigned char *sig, unsigned int *s, EVP_PKEY *pkey) { return 1; }