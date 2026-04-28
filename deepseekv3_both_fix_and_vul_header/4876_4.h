#include <stdio.h>
#include <stdlib.h>

typedef struct ssl_cipher_st SSL_CIPHER;
typedef struct ssl_st SSL;
typedef struct stack_st STACK_OF;

#define STACK_OF(type) struct stack_st_##type
#define sk_SSL_CIPHER_num(sk) 0
#define sk_SSL_CIPHER_value(sk,i) NULL

struct ssl_cipher_st {
    int algorithm_ssl;
    int algorithm_mkey;
    int algorithm_auth;
    char *name;
    long id;
    int strength_bits;
    int alg_bits;
    int mask;
    int mask_strength;
    int mask_alg;
    int mask_ssl;
    int mask_mkey;
    int mask_auth;
};

struct ssl_st {
    void *kssl_ctx;
    void *psk_client_callback;
    struct {
        int srp_Mask;
    } srp_ctx;
    int renegotiate;
};

#define SSL_TLSV1_2 0
#define SSL_kKRB5 0
#define SSL_aKRB5 0
#define SSL_kPSK 0
#define SSL_aPSK 0
#define SSL_kSRP 0
#define SSL_aSRP 0
#define TLS1_2_VERSION 0
#define SSL3_CK_SCSV 0

int ssl_put_cipher_by_char(SSL *s, SSL_CIPHER *c, unsigned char *p);
int TLS1_get_client_version(SSL *s);