#include <string.h>
#include <stdio.h>
#include <strings.h>

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

typedef void X509;
typedef void X509_NAME;
typedef void SSL;
typedef void EVP_MD;

#define SSL_VERIFY_PEER 0
#define X509_V_OK 0
#define NID_commonName 0