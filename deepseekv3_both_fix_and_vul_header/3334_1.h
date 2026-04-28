#include <stddef.h>

#define SSL_ST_CONNECT 0x1000
#define EVP_MAX_MD_SIZE 64

typedef struct ssl_cipher_st SSL_CIPHER;
typedef struct ssl_method_st SSL_METHOD;
typedef struct ssl3_enc_method SSL3_ENC_METHOD;
typedef struct ssl_st SSL;

struct ssl_st {
    SSL_METHOD *method;
    struct ssl3_state_st *s3;
    int state;
};

struct ssl3_state_st {
    struct {
        SSL_CIPHER *new_cipher;
        unsigned char peer_finish_md[EVP_MAX_MD_SIZE];
        size_t peer_finish_md_len;
    } tmp;
};

struct ssl_method_st {
    SSL3_ENC_METHOD *ssl3_enc;
};

struct ssl3_enc_method {
    const char *client_finished_label;
    int client_finished_label_len;
    const char *server_finished_label;
    int server_finished_label_len;
    int (*final_finish_mac)(SSL *s, const char *sender, int slen, unsigned char *md);
};