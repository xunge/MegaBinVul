#include <string.h>
#include <stdio.h>

#define SHA256LEN 32
#define SHA256STRLEN (SHA256LEN * 2 + 1)
#define FIELD_SIZE 256

struct tunnel {
    void *ssl_handle;
    struct config *config;
};

struct config {
    char *gateway_host;
    struct x509_digest *cert_whitelist;
};

struct x509_digest {
    char data[SHA256STRLEN];
    struct x509_digest *next;
};

typedef struct {} X509;
typedef struct {} X509_NAME;
typedef struct {} EVP_MD;

#define SSL_VERIFY_PEER 0
#define X509_V_OK 0
#define NID_commonName 0

int SSL_set_verify(void *ssl, int mode, void *callback);
X509 *SSL_get_peer_certificate(void *ssl);
int SSL_get_verify_result(void *ssl);
X509_NAME *X509_get_subject_name(X509 *cert);
X509_NAME *X509_get_issuer_name(X509 *cert);
int X509_NAME_get_text_by_NID(X509_NAME *name, int nid, char *buf, int len);
int X509_check_host(X509 *cert, const char *name, size_t namelen, unsigned int flags, char **peername);
int X509_digest(X509 *cert, const EVP_MD *type, unsigned char *md, unsigned int *len);
char *X509_NAME_oneline(X509_NAME *name, char *buf, int len);
void X509_free(X509 *cert);