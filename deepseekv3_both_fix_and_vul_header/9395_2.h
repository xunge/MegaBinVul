#include <stddef.h>

typedef struct ssl_method_st SSL_METHOD;

#define SSL2_VERSION 0x0002
#define SSL3_VERSION 0x0300
#define TLS1_VERSION 0x0301
#define TLS1_1_VERSION 0x0302
#define TLS1_2_VERSION 0x0303

#ifndef OPENSSL_NO_SSL2
static const SSL_METHOD *SSLv2_server_method(void);
#endif
static const SSL_METHOD *SSLv3_server_method(void);
static const SSL_METHOD *TLSv1_server_method(void);
static const SSL_METHOD *TLSv1_1_server_method(void);
static const SSL_METHOD *TLSv1_2_server_method(void);