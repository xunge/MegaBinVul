#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SHA256LEN 32
#define SHA256STRLEN (2 * SHA256LEN + 1)
#define FIELD_SIZE 256

struct tunnel {
    void *ssl_handle;
    struct {
        char *gateway_host;
        struct x509_digest *cert_whitelist;
    } *config;
};

struct x509_digest {
    char data[SHA256STRLEN];
    struct x509_digest *next;
};

typedef struct X509 X509;
typedef struct X509_NAME X509_NAME;
typedef struct SSL SSL;
typedef struct EVP_MD EVP_MD;

enum MatchResult {
    MatchFound,
    MatchNotFound,
    NoSANPresent,
    MalformedCertificate,
    Error
};

#define SSL_VERIFY_PEER 0
#define X509_V_OK 0
#define NID_commonName 0

int SSL_set_verify(SSL *ssl, int mode, void *callback);
X509 *SSL_get_peer_certificate(SSL *ssl);
X509_NAME *X509_get_subject_name(X509 *cert);
int X509_NAME_get_text_by_NID(X509_NAME *name, int nid, char *buf, int len);
int SSL_get_verify_result(SSL *ssl);
int X509_digest(X509 *cert, const EVP_MD *type, unsigned char *md, unsigned int *len);
const EVP_MD *EVP_sha256(void);
char *X509_NAME_oneline(X509_NAME *name, char *buf, int len);
X509_NAME *X509_get_issuer_name(X509 *cert);
void X509_free(X509 *cert);
void log_error(const char *fmt, ...);
void log_debug(const char *fmt, ...);