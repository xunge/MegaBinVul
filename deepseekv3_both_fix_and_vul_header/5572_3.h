#include <string.h>
#include <stdlib.h>

#define SSL2_ST_GET_CLIENT_MASTER_KEY_A 1
#define SSL2_ST_GET_CLIENT_MASTER_KEY_B 2
#define SSL2_MT_CLIENT_MASTER_KEY 1
#define SSL2_MT_ERROR 2
#define SSL2_PE_UNDEFINED_ERROR 1
#define SSL2_PE_NO_CIPHER 2
#define SSL_F_GET_CLIENT_MASTER_KEY 1
#define SSL_R_READ_WRONG_PACKET_TYPE 1
#define SSL_R_PEER_ERROR 2
#define SSL_R_NO_CIPHER_MATCH 3
#define SSL_R_KEY_ARG_TOO_LONG 4
#define ERR_R_INTERNAL_ERROR 5
#define SSL_R_MESSAGE_TOO_LONG 6
#define SSL_R_NO_PRIVATEKEY 7
#define SSL_R_PROBLEMS_MAPPING_CIPHER_FUNCTIONS 8
#define SSL_R_BAD_LENGTH 9
#define SSL_R_LENGTH_TOO_SHORT 10
#define SSL_R_BAD_RSA_DECRYPT 11
#define SSL_R_WRONG_NUMBER_OF_KEY_BITS 12
#define SSL_MAX_KEY_ARG_LENGTH 8
#define SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER 16384
#define SSL_MAX_MASTER_KEY_LENGTH 48
#define SSL_PKEY_RSA_ENC 0
#define SSL2_CF_8_BYTE_ENC 0x1000
#define RSA_SSLV23_PADDING 2
#define RSA_PKCS1_PADDING 1

typedef struct ssl_st SSL;
typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_cipher_st {
    int algorithm2;
} SSL_CIPHER;
typedef struct evp_cipher_st {
    int key_length;
} EVP_CIPHER;
typedef struct evp_md_st EVP_MD;

struct ssl_st {
    int state;
    int init_num;
    struct buf_mem_st *init_buf;
    SSL_SESSION *session;
    struct ssl2_state_st *s2;
    int (*msg_callback)(int, int, int, const void *, size_t, SSL *, void *);
    void *msg_callback_arg;
    int version;
    int ssl2_rollback;
    struct cert_st *cert;
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
    struct {
        void *privatekey;
    } pkeys[1];
};

struct buf_mem_st {
    void *data;
    size_t length;
};

static int ssl2_read(SSL *s, char *buf, int len) { return 0; }
static int ssl2_part_read(SSL *s, int f, int i) { return 0; }
static void ssl2_return_error(SSL *s, int error) {}
static void SSLerr(int f, int r) {}
static SSL_CIPHER *ssl2_get_cipher_by_char(const unsigned char *p) { return NULL; }
static int ssl_cipher_get_evp(SSL_SESSION *s, const EVP_CIPHER **c, const EVP_MD **md, int *mac_pkey_type, int *mac_secret_size, void **comp) { return 0; }
static int ssl_rsa_private_decrypt(struct cert_st *cert, int flen, unsigned char *from, unsigned char *to, int padding) { return 0; }
static int RAND_pseudo_bytes(unsigned char *buf, int num) { return 0; }
static void ERR_clear_error(void) {}
static int SSL_C_IS_EXPORT(const SSL_CIPHER *c) { return 0; }
static int EVP_CIPHER_key_length(const EVP_CIPHER *c) { return c ? c->key_length : 0; }

#define n2s(c,s) (s = ((unsigned int)((c)[0]) << 8) | (unsigned int)((c)[1]), (c) += 2)