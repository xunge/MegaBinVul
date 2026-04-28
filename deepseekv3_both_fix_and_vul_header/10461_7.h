#include <stdlib.h>
#include <stdio.h>

#define NID_undef 0
#define SSL_F_TLS1_SETUP_KEY_BLOCK 0
#define SSL_R_CIPHER_OR_HASH_UNAVAILABLE 0
#define SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS 0
#define TLS1_VERSION 0
#define SSL_eNULL 0
#define SSL_RC4 0
#define SSL3_RANDOM_SIZE 32
#define ERR_R_MALLOC_FAILURE 0

typedef struct EVP_CIPHER EVP_CIPHER;
typedef struct EVP_MD EVP_MD;
typedef struct SSL_COMP SSL_COMP;
typedef struct SSL_SESSION SSL_SESSION;

struct ssl3_state_st {
    struct {
        const EVP_CIPHER *new_sym_enc;
        const EVP_MD *new_hash;
        int new_mac_pkey_type;
        int new_mac_secret_size;
        int key_block_length;
        unsigned char *key_block;
        unsigned char client_random[SSL3_RANDOM_SIZE];
        unsigned char server_random[SSL3_RANDOM_SIZE];
    } tmp;
    int need_empty_fragments;
};

struct cipher_st {
    int algorithm_enc;
};

struct SSL_SESSION {
    struct cipher_st *cipher;
    unsigned char *master_key;
    int master_key_length;
};

struct SSL_METHOD {
    int version;
};

struct SSL {
    struct ssl3_state_st *s3;
    SSL_SESSION *session;
    int tlsext_use_etm;
    unsigned long options;
    struct SSL_METHOD *method;
};

void SSLerr(int function, int reason);
void ssl3_cleanup_key_block(struct SSL *s);
int ssl_cipher_get_evp(struct SSL_SESSION *s, const EVP_CIPHER **c, const EVP_MD **hash,
                      int *mac_type, int *mac_secret_size, struct SSL_COMP **comp, int etm);
int tls1_generate_key_block(struct SSL *s, unsigned char *p, int num);
void *OPENSSL_malloc(int size);
int EVP_CIPHER_key_length(const EVP_CIPHER *c);
int EVP_CIPHER_iv_length(const EVP_CIPHER *c);

typedef struct SSL SSL;