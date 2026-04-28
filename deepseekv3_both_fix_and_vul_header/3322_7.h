#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EVP_MAX_KEY_LENGTH 64
#define EVP_MAX_IV_LENGTH 16
#define EVP_MAX_BLOCK_LENGTH 32
#define EVP_GCM_TLS_FIXED_IV_LEN 4
#define SSL3_RT_MAX_ENCRYPTED_LENGTH 16834
#define SSL3_RANDOM_SIZE 32
#define TLS_MD_CLIENT_WRITE_KEY_CONST "client write key"
#define TLS_MD_SERVER_WRITE_KEY_CONST "server write key"
#define TLS_MD_IV_BLOCK_CONST "IV block"
#define TLS_MD_CLIENT_WRITE_KEY_CONST_SIZE 16
#define TLS_MD_SERVER_WRITE_KEY_CONST_SIZE 16
#define TLS_MD_IV_BLOCK_CONST_SIZE 8
#define DTLS1_VERSION 0xFEFF
#define TLS1_STREAM_MAC 0x04

#define SSL_F_TLS1_CHANGE_CIPHER_STATE 100
#define SSL_R_COMPRESSION_LIBRARY_ERROR 101
#define ERR_R_INTERNAL_ERROR 103
#define ERR_R_MALLOC_FAILURE 104

#define SSL3_CC_READ 0x01
#define SSL3_CC_WRITE 0x02
#define SSL3_CHANGE_CIPHER_CLIENT_WRITE 0x10
#define SSL3_CHANGE_CIPHER_SERVER_READ 0x20

#define SSL_MAC_FLAG_READ_MAC_STREAM 0x01
#define SSL_MAC_FLAG_WRITE_MAC_STREAM 0x02

#define EVP_CIPH_GCM_MODE 0x01
#define EVP_CIPH_FLAG_AEAD_CIPHER 0x02
#define EVP_CTRL_GCM_SET_IV_FIXED 0x03
#define EVP_CTRL_AEAD_SET_MAC_KEY 0x04

typedef struct evp_cipher_ctx_st {
    int dummy;
} EVP_CIPHER_CTX;

typedef struct evp_md_ctx_st {
    int dummy;
} EVP_MD_CTX;

typedef struct evp_pkey_st {
    int dummy;
} EVP_PKEY;

typedef struct ssl_session_st {
    int key_arg_length;
} SSL_SESSION;

typedef struct comp_ctx_st {
    int dummy;
} COMP_CTX;

typedef struct ssl_comp_st {
    void *method;
} SSL_COMP;

typedef struct evp_cipher_st {
    int nid;
    int block_size;
    int key_len;
    int iv_len;
    unsigned long flags;
    long algorithm_mkey;
    long algorithm_auth;
    long algorithm2;
} EVP_CIPHER;

typedef struct evp_md_st {
    int dummy;
} EVP_MD;

struct ssl3_state_st {
    struct {
        const EVP_CIPHER *new_cipher;
        const EVP_CIPHER *new_sym_enc;
        const EVP_MD *new_hash;
        int new_mac_pkey_type;
        int new_mac_secret_size;
        unsigned char *key_block;
        int key_block_length;
        const SSL_COMP *new_compression;
    } tmp;
    struct {
        unsigned char *comp;
    } rrec;
    unsigned char client_random[SSL3_RANDOM_SIZE];
    unsigned char server_random[SSL3_RANDOM_SIZE];
    unsigned char read_mac_secret[EVP_MAX_KEY_LENGTH];
    unsigned char write_mac_secret[EVP_MAX_KEY_LENGTH];
    int read_mac_secret_size;
    int write_mac_secret_size;
    unsigned char read_sequence[8];
    unsigned char write_sequence[8];
};

struct ssl_st {
    int version;
    int mac_flags;
    struct ssl3_state_st *s3;
    SSL_SESSION *session;
    EVP_CIPHER_CTX *enc_read_ctx;
    EVP_CIPHER_CTX *enc_write_ctx;
    EVP_MD_CTX *read_hash;
    EVP_MD_CTX *write_hash;
    COMP_CTX *expand;
    COMP_CTX *compress;
};

typedef struct ssl_st SSL;

void *OPENSSL_malloc(size_t size);
void OPENSSL_cleanse(void *ptr, size_t len);
void SSLerr(int f, int r);
int SSL_C_IS_EXPORT(const EVP_CIPHER *c);
int SSL_IS_DTLS(const SSL *s);
int ssl_get_algorithm2(const SSL *s);
int tls1_PRF(int alg2, const unsigned char *label, int label_len,
             const unsigned char *client_random, int client_random_len,
             const unsigned char *server_random, int server_random_len,
             const unsigned char *extra, int extra_len,
             const unsigned char *out, int out_len,
             const unsigned char *key, int key_len,
             unsigned char *tmp1, unsigned char *tmp2, int keylen);
EVP_MD_CTX *ssl_replace_hash(EVP_MD_CTX **hash, EVP_MD_CTX *new_hash);
void EVP_CIPHER_CTX_init(EVP_CIPHER_CTX *ctx);
void EVP_CIPHER_CTX_cleanup(EVP_CIPHER_CTX *ctx);
int EVP_CipherInit_ex(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher,
                     void *impl, const unsigned char *key, const unsigned char *iv, int enc);
int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX *ctx, int type, int arg, void *ptr);
EVP_PKEY *EVP_PKEY_new_mac_key(int type, void *e, const unsigned char *key, int keylen);
void EVP_PKEY_free(EVP_PKEY *pkey);
int EVP_DigestSignInit(EVP_MD_CTX *ctx, void *pctx, const EVP_MD *type, void *e, EVP_PKEY *pkey);
EVP_MD_CTX *EVP_MD_CTX_create(void);
void COMP_CTX_free(COMP_CTX *ctx);
COMP_CTX *COMP_CTX_new(void *meth);
int EVP_CIPHER_key_length(const EVP_CIPHER *c);
int EVP_CIPHER_iv_length(const EVP_CIPHER *c);
int EVP_CIPHER_mode(const EVP_CIPHER *c);
unsigned long EVP_CIPHER_flags(const EVP_CIPHER *c);
int SSL_C_EXPORT_KEYLENGTH(const EVP_CIPHER *c);