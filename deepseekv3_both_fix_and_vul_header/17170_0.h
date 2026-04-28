#include <stddef.h>

#define MBEDTLS_ERR_SSL_FEATURE_UNAVAILABLE -0x7080
#define MBEDTLS_ERR_SSL_BAD_HS_SERVER_KEY_EXCHANGE -0x7B00
#define MBEDTLS_SSL_DEBUG_MSG(level, message)

typedef struct mbedtls_ssl_context {
    // dummy definition since actual contents aren't used in this function
} mbedtls_ssl_context;