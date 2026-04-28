#include <stddef.h>
#include <stdint.h>

typedef struct mbedtls_pk_context {
    int dummy;
} mbedtls_pk_context;

typedef struct mbedtls_ssl_ciphersuite_t {
    int key_exchange;
} mbedtls_ssl_ciphersuite_t;

typedef struct mbedtls_ssl_transform {
    const mbedtls_ssl_ciphersuite_t *ciphersuite_info;
} mbedtls_ssl_transform;

typedef struct mbedtls_ssl_session {
    struct {
        mbedtls_pk_context pk;
    } *peer_cert;
} mbedtls_ssl_session;

typedef struct mbedtls_ssl_handshake_params {
    void *ecjpake_ctx;
} mbedtls_ssl_handshake_params;

typedef struct mbedtls_ssl_context {
    unsigned char *in_msg;
    unsigned char in_msgtype;
    size_t in_hslen;
    int minor_ver;
    int state;
    int keep_current_message;
    mbedtls_ssl_transform *transform_negotiate;
    mbedtls_ssl_session *session_negotiate;
    mbedtls_ssl_handshake_params *handshake;
} mbedtls_ssl_context;

typedef enum {
    MBEDTLS_KEY_EXCHANGE_RSA,
    MBEDTLS_KEY_EXCHANGE_ECDH_RSA,
    MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA,
    MBEDTLS_KEY_EXCHANGE_PSK,
    MBEDTLS_KEY_EXCHANGE_RSA_PSK,
    MBEDTLS_KEY_EXCHANGE_DHE_PSK,
    MBEDTLS_KEY_EXCHANGE_ECDHE_PSK,
    MBEDTLS_KEY_EXCHANGE_DHE_RSA,
    MBEDTLS_KEY_EXCHANGE_ECDHE_RSA,
    MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA,
    MBEDTLS_KEY_EXCHANGE_ECJPAKE
} mbedtls_key_exchange_type;

typedef enum {
    MBEDTLS_SSL_MSG_HANDSHAKE,
    MBEDTLS_SSL_MSG_ALERT,
    MBEDTLS_SSL_MSG_CHANGE_CIPHER_SPEC,
    MBEDTLS_SSL_MSG_APPLICATION_DATA
} mbedtls_ssl_msg_type;

typedef enum {
    MBEDTLS_SSL_HS_SERVER_KEY_EXCHANGE,
    MBEDTLS_SSL_HS_CLIENT_KEY_EXCHANGE,
    MBEDTLS_SSL_HS_CERTIFICATE_REQUEST,
    MBEDTLS_SSL_HS_SERVER_HELLO_DONE
} mbedtls_ssl_handshake_type;

typedef enum {
    MBEDTLS_SSL_ALERT_LEVEL_WARNING = 1,
    MBEDTLS_SSL_ALERT_LEVEL_FATAL = 2
} mbedtls_ssl_alert_level;

typedef enum {
    MBEDTLS_SSL_ALERT_MSG_CLOSE_NOTIFY = 0,
    MBEDTLS_SSL_ALERT_MSG_UNEXPECTED_MESSAGE = 10,
    MBEDTLS_SSL_ALERT_MSG_HANDSHAKE_FAILURE = 40,
    MBEDTLS_SSL_ALERT_MSG_ILLEGAL_PARAMETER = 47,
    MBEDTLS_SSL_ALERT_MSG_DECODE_ERROR = 50,
    MBEDTLS_SSL_ALERT_MSG_DECRYPT_ERROR = 51
} mbedtls_ssl_alert_message;

typedef enum {
    MBEDTLS_SSL_MINOR_VERSION_0 = 0,
    MBEDTLS_SSL_MINOR_VERSION_1 = 1,
    MBEDTLS_SSL_MINOR_VERSION_2 = 2,
    MBEDTLS_SSL_MINOR_VERSION_3 = 3
} mbedtls_ssl_minor_version;

typedef enum {
    MBEDTLS_MD_NONE = 0,
    MBEDTLS_MD_SHA1
} mbedtls_md_type_t;

typedef enum {
    MBEDTLS_PK_NONE = 0,
    MBEDTLS_PK_RSA,
    MBEDTLS_PK_ECDSA
} mbedtls_pk_type_t;

#define MBEDTLS_ERR_SSL_UNEXPECTED_MESSAGE               -0x7A00
#define MBEDTLS_ERR_SSL_BAD_HS_SERVER_KEY_EXCHANGE       -0x7B00
#define MBEDTLS_ERR_SSL_INTERNAL_ERROR                   -0x7C00
#define MBEDTLS_ERR_SSL_PK_TYPE_MISMATCH                 -0x7D00

#define MBEDTLS_SSL_DEBUG_MSG(level, args)
#define MBEDTLS_SSL_DEBUG_RET(level, text, ret)
#define MBEDTLS_SSL_DEBUG_BUF(level, text, buf, len)

static int ssl_get_ecdh_params_from_cert(mbedtls_ssl_context *ssl);
static int ssl_parse_server_psk_hint(mbedtls_ssl_context *ssl, unsigned char **p, unsigned char *end);
static int ssl_parse_server_dh_params(mbedtls_ssl_context *ssl, unsigned char **p, unsigned char *end);
static int ssl_parse_server_ecdh_params(mbedtls_ssl_context *ssl, unsigned char **p, unsigned char *end);
static int ssl_parse_signature_algorithm(mbedtls_ssl_context *ssl, unsigned char **p, unsigned char *end, mbedtls_md_type_t *md_alg, mbedtls_pk_type_t *pk_alg);
static int mbedtls_ssl_read_record(mbedtls_ssl_context *ssl);
static void mbedtls_ssl_send_alert_message(mbedtls_ssl_context *ssl, mbedtls_ssl_alert_level level, mbedtls_ssl_alert_message message);
static size_t mbedtls_ssl_hs_hdr_len(mbedtls_ssl_context *ssl);
static mbedtls_pk_type_t mbedtls_ssl_get_ciphersuite_sig_pk_alg(const mbedtls_ssl_ciphersuite_t *info);
static int mbedtls_ssl_get_key_exchange_md_ssl_tls(mbedtls_ssl_context *ssl, unsigned char *hash, unsigned char *params, size_t params_len);
static int mbedtls_ssl_get_key_exchange_md_tls1_2(mbedtls_ssl_context *ssl, unsigned char *hash, unsigned char *params, size_t params_len, mbedtls_md_type_t md_alg);
static int mbedtls_pk_verify(mbedtls_pk_context *ctx, mbedtls_md_type_t md_alg, const unsigned char *hash, size_t hash_len, const unsigned char *sig, size_t sig_len);
static int mbedtls_pk_can_do(const mbedtls_pk_context *ctx, mbedtls_pk_type_t type);
static int mbedtls_ecjpake_read_round_two(void *ctx, const unsigned char *buf, size_t len);
static int mbedtls_ssl_ciphersuite_uses_server_signature(const mbedtls_ssl_ciphersuite_t *info);