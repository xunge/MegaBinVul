#include <stddef.h>

#define MBEDTLS_ERR_SSL_FEATURE_UNAVAILABLE -0x7F00
#define MBEDTLS_ERR_SSL_BAD_HS_SERVER_KEY_EXCHANGE -0x7B00

typedef struct mbedtls_ssl_context mbedtls_ssl_context;
#define MBEDTLS_SSL_DEBUG_MSG(level, message)