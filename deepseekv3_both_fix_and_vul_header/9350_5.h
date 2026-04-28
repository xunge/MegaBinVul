#include <string.h>
#include <stddef.h>

#define SSL_MAX_MASTER_KEY_LENGTH 48
#define SSL_MAX_KEY_ARG_LENGTH 8
#define SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER 16709

#define SSL2_ST_GET_CLIENT_MASTER_KEY_A 0x101
#define SSL2_ST_GET_CLIENT_MASTER_KEY_B 0x102
#define SSL2_MT_CLIENT_MASTER_KEY 2
#define SSL2_MT_ERROR 0
#define SSL2_PE_UNDEFINED_ERROR 0x0000
#define SSL2_PE_NO_CIPHER 0x0001
#define SSL_F_GET_CLIENT_MASTER_KEY 100
#define SSL_R_READ_WRONG_PACKET_TYPE 1000
#define SSL_R_PEER_ERROR 1001
#define SSL_R_NO_CIPHER_MATCH 1002
#define SSL_R_KEY_ARG_TOO_LONG 1003
#define ERR_R_INTERNAL_ERROR 2000
#define SSL_R_MESSAGE_TOO_LONG 1004
#define SSL_R_NO_PRIVATEKEY 1005
#define SSL_R_PROBLEMS_MAPPING_CIPHER_FUNCTIONS 1006
#define SSL_R_BAD_LENGTH 1007
#define SSL_R_LENGTH_TOO_SHORT 1008

#define SSL_PKEY_RSA_ENC 0
#define SSL2_CF_8_BYTE_ENC 0x2000
#define RSA_SSLV23_PADDING 2
#define RSA_PKCS1_PADDING 1

typedef struct SSL_CIPHER {
    unsigned long algorithm2;
} SSL_CIPHER;
typedef struct EVP_CIPHER EVP_CIPHER;
typedef struct EVP_MD EVP_MD;

typedef struct SSL {
    int state;
    int init_num;
    struct {
        void *data;
        int length;
    } *init_buf;
    struct {
        struct {
            int clear;
            int enc;
        } tmp;
        int ssl2_rollback;
    } *s2;
    struct {
        SSL_CIPHER *cipher;
        unsigned char master_key[SSL_MAX_MASTER_KEY_LENGTH];
        int master_key_length;
        unsigned char key_arg[SSL_MAX_KEY_ARG_LENGTH];
        int key_arg_length;
        void *ciphers;
    } *session;
    struct {
        struct {
            void *privatekey;
        } pkeys[1];
    } *cert;
    void (*msg_callback)(int, int, int, void*, size_t, void*, void*);
    void *msg_callback_arg;
    int version;
} SSL;

static int ssl2_part_read(SSL *s, int f, int i) { return 0; }
static void ssl2_return_error(SSL *s, int code) {}
static void SSLerr(int f, int r) {}
static SSL_CIPHER *ssl2_get_cipher_by_char(const unsigned char *p) { return NULL; }
static int sk_SSL_CIPHER_find(void *sk, SSL_CIPHER *cipher) { return 0; }
static int ssl_cipher_get_evp(void *session, const EVP_CIPHER **c, const EVP_MD **md, void *a, void *b, void *d) { return 0; }
static int ssl2_read(SSL *s, char *buf, int len) { return 0; }
static int ssl_rsa_private_decrypt(void *cert, int len, unsigned char *from, unsigned char *to, int padding) { return 0; }
static void ERR_clear_error(void) {}
static unsigned char constant_time_eq_int_8(int a, int b) { return 0; }
static unsigned char constant_time_select_8(unsigned char a, unsigned char b, unsigned char c) { return 0; }
static void OPENSSL_cleanse(void *ptr, size_t len) {}
static int RAND_pseudo_bytes(unsigned char *buf, int num) { return 0; }
static int SSL_C_IS_EXPORT(SSL_CIPHER *c) { return 0; }
static unsigned int EVP_CIPHER_key_length(const EVP_CIPHER *c) { return 0; }

#define n2s(c,s) (s = ((unsigned int)((c)[0]) << 8) | (unsigned int)((c)[1]), (c) += 2)