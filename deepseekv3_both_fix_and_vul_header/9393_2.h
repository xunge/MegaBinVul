#include <stddef.h>

typedef struct ssl_method_st SSL_METHOD;

#define SSL2_VERSION 0
#define SSL3_VERSION 0
#define TLS1_VERSION 0
#define TLS1_1_VERSION 0
#define TLS1_2_VERSION 0

#ifndef OPENSSL_NO_SSL2
static const SSL_METHOD *SSLv2_client_method(void);
#endif
static const SSL_METHOD *SSLv3_client_method(void);
static const SSL_METHOD *TLSv1_client_method(void);
static const SSL_METHOD *TLSv1_1_client_method(void);
static const SSL_METHOD *TLSv1_2_client_method(void);