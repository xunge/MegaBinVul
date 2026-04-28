#include <stddef.h>
#include <string.h>

#define MBEDTLS_ERR_SSL_PRIVATE_KEY_REQUIRED -0x7800
#define MBEDTLS_ERR_SSL_BAD_HS_CLIENT_KEY_EXCHANGE -0x7B00
#define MBEDTLS_ERR_SSL_UNKNOWN_IDENTITY -0x7C00

#define MBEDTLS_SSL_DEBUG_MSG(level, message)
#define MBEDTLS_SSL_DEBUG_BUF(level, description, buf, len)

#define MBEDTLS_SSL_ALERT_LEVEL_FATAL 2
#define MBEDTLS_SSL_ALERT_MSG_UNKNOWN_PSK_IDENTITY 115

typedef struct mbedtls_ssl_conf {
    int (*f_psk)(void *, struct mbedtls_ssl_context *, const unsigned char *, size_t);
    void *p_psk;
    const unsigned char *psk;
    const unsigned char *psk_identity;
    size_t psk_identity_len;
    size_t psk_len;
} mbedtls_ssl_conf;

typedef struct mbedtls_ssl_context {
    mbedtls_ssl_conf *conf;
} mbedtls_ssl_context;

static int mbedtls_ssl_safer_memcmp(const void *a, const void *b, size_t n) {
    const unsigned char *x = a;
    const unsigned char *y = b;
    int diff = 0;
    
    for (size_t i = 0; i < n; i++)
        diff |= x[i] ^ y[i];
    
    return diff;
}

static void mbedtls_ssl_send_alert_message(mbedtls_ssl_context *ssl, unsigned char level, unsigned char message) {
    (void)ssl;
    (void)level;
    (void)message;
}