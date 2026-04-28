#include <string.h>
#include <stdlib.h>

#define SSL2_ST_GET_CLIENT_MASTER_KEY_A 1
#define SSL2_ST_GET_CLIENT_MASTER_KEY_B 2
#define SSL2_MT_CLIENT_MASTER_KEY 2
#define SSL2_MT_ERROR 0
#define SSL2_PE_UNDEFINED_ERROR 0
#define SSL2_PE_NO_CIPHER 1
#define SSL_F_GET_CLIENT_MASTER_KEY 0
#define SSL_R_READ_WRONG_PACKET_TYPE 0
#define SSL_R_PEER_ERROR 0
#define SSL_R_NO_CIPHER_MATCH 0
#define SSL_R_KEY_ARG_TOO_LONG 0
#define SSL_R_MESSAGE_TOO_LONG 0
#define SSL_R_NO_PRIVATEKEY 0
#define SSL_R_PROBLEMS_MAPPING_CIPHER_FUNCTIONS 0
#define SSL_R_BAD_LENGTH 0
#define SSL_R_LENGTH_TOO_SHORT 0
#define ERR_R_INTERNAL_ERROR 0
#define SSL_MAX_KEY_ARG_LENGTH 8
#define SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER 0x4000
#define SSL_PKEY_RSA_ENC 0
#define SSL_MAX_MASTER_KEY_LENGTH 48
#define SSL2_CF_8_BYTE_ENC 0x2000
#define RSA_SSLV23_PADDING 2
#define RSA_PKCS1_PADDING 1

typedef struct ssl_cipher_st {
    unsigned long algorithm2;
} SSL_CIPHER;

typedef struct evp_cipher_st {
    int key_len;
} EVP_CIPHER;

typedef struct evp_md_st EVP_MD;
typedef struct rsa_st RSA;
typedef struct ssl_comp_st SSL_COMP;
typedef struct ssl_st SSL;

struct ssl_st {
    int state;
    int init_num;
    struct buf_st *init_buf;
    struct ssl_session_st *session;
    struct ssl2_state_st *s2;
    struct cert_st *cert;
    int (*msg_callback)(int, int, int, const void*, size_t, SSL*, void*);
    void *msg_callback_arg;
    int version;
    int ssl2_rollback;
};

struct buf_st {
    unsigned char *data;
    int length;
};

struct ssl_session_st {
    const SSL_CIPHER *cipher;
    unsigned char key_arg[SSL_MAX_KEY_ARG_LENGTH];
    int key_arg_length;
    unsigned char master_key[SSL_MAX_MASTER_KEY_LENGTH];
    int master_key_length;
};

struct ssl2_state_st {
    struct {
        int clear;
        int enc;
    } tmp;
    int ssl2_rollback;
};

struct cert_st {
    struct cert_pkey_st *pkeys;
};

struct cert_pkey_st {
    RSA *privatekey;
};

static int EVP_CIPHER_key_length(const EVP_CIPHER *c) {
    return c->key_len;
}

static void n2s(unsigned char **p, unsigned short *s) {
    *s = ((*p)[0] << 8) | (*p)[1];
    *p += 2;
}

static int ssl2_read(SSL *s, char *buf, int len) { return 0; }
static int ssl2_part_read(SSL *s, int func, int ret) { return 0; }
static void ssl2_return_error(SSL *s, int reason) {}
static const SSL_CIPHER *ssl2_get_cipher_by_char(const unsigned char *p) { return NULL; }
static int ssl_cipher_get_evp(struct ssl_session_st *s, const EVP_CIPHER **c, const EVP_MD **md, int *mac_pkey_type, int *mac_secret_size, const SSL_COMP **comp) { return 0; }
static int ssl_rsa_private_decrypt(struct cert_st *cert, int len, unsigned char *from, unsigned char *to, int padding) { return 0; }
static int SSL_C_IS_EXPORT(const SSL_CIPHER *c) { return 0; }
static void SSLerr(int func, int reason) {}
static int RAND_pseudo_bytes(unsigned char *buf, int num) { return 0; }
static void ERR_clear_error(void) {}