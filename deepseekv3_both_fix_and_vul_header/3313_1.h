typedef struct ssl_st SSL;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct ssl_cipher_st SSL_CIPHER;
typedef struct ssl_method_st SSL_METHOD;

struct ssl_st {
    const SSL_METHOD *method;
    SSL3_STATE *s3;
};

struct ssl3_state_st {
    struct {
        const SSL_CIPHER *new_cipher;
    } tmp;
};

struct ssl_cipher_st {
    long algorithm2;
};

struct ssl_method_st {
    long version;
};

#define SSL_HANDSHAKE_MAC_DEFAULT 0
#define TLS1_PRF 0
#define SSL_HANDSHAKE_MAC_SHA256 0
#define TLS1_PRF_SHA256 0
#define TLS1_2_VERSION 0

long TLS1_get_version(SSL *s);