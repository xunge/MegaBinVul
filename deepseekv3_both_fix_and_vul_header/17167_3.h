#include <stddef.h>
#include <stdint.h>

typedef struct mbedtls_pk_context {
    int dummy;
} mbedtls_pk_context;

typedef struct mbedtls_ssl_ciphersuite_t {
    int key_exchange;
} mbedtls_ssl_ciphersuite_t;

typedef struct mbedtls_ssl_transform {
    mbedtls_ssl_ciphersuite_t *ciphersuite_info;
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
    mbedtls_ssl_transform *transform_negotiate;
    unsigned char *in_msg;
    int in_msgtype;
    size_t in_hslen;
    int state;
    int keep_current_message;
    int minor_ver;
    mbedtls_ssl_session *session_negotiate;
    mbedtls_ssl_handshake_params *handshake;
} mbedtls_ssl_context;

#define MBEDTLS_SSL_DEBUG_MSG(level, message)
#define MBEDTLS_SSL_DEBUG_RET(level, text, ret)
#define MBEDTLS_SSL_DEBUG_BUF(level, text, buf, len)

#define MBEDTLS_ERR_SSL_UNEXPECTED_MESSAGE -0x7A00
#define MBEDTLS_ERR_SSL_BAD_HS_SERVER_KEY_EXCHANGE -0x7B00
#define MBEDTLS_ERR_SSL_INTERNAL_ERROR -0x7C00
#define MBEDTLS_ERR_SSL_PK_TYPE_MISMATCH -0x7D00

#define MBEDTLS_SSL_ALERT_LEVEL_FATAL 2
#define MBEDTLS_SSL_ALERT_MSG_HANDSHAKE_FAILURE 40
#define MBEDTLS_SSL_ALERT_MSG_UNEXPECTED_MESSAGE 10
#define MBEDTLS_SSL_ALERT_MSG_ILLEGAL_PARAMETER 47
#define MBEDTLS_SSL_ALERT_MSG_DECODE_ERROR 50
#define MBEDTLS_SSL_ALERT_MSG_DECRYPT_ERROR 51

#define MBEDTLS_SSL_MSG_HANDSHAKE 22
#define MBEDTLS_SSL_HS_SERVER_KEY_EXCHANGE 12

#define MBEDTLS_KEY_EXCHANGE_RSA 1
#define MBEDTLS_KEY_EXCHANGE_ECDH_RSA 2
#define MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA 3
#define MBEDTLS_KEY_EXCHANGE_PSK 4
#define MBEDTLS_KEY_EXCHANGE_RSA_PSK 5
#define MBEDTLS_KEY_EXCHANGE_DHE_PSK 6
#define MBEDTLS_KEY_EXCHANGE_ECDHE_PSK 7
#define MBEDTLS_KEY_EXCHANGE_DHE_RSA 8
#define MBEDTLS_KEY_EXCHANGE_ECDHE_RSA 9
#define MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA 10
#define MBEDTLS_KEY_EXCHANGE_ECJPAKE 11

#define MBEDTLS_MD_NONE 0
#define MBEDTLS_MD_SHA1 1
#define MBEDTLS_PK_NONE 0
#define MBEDTLS_PK_ECDSA 1

#define MBEDTLS_SSL_MINOR_VERSION_3 3

static int ssl_get_ecdh_params_from_cert(mbedtls_ssl_context *ssl);
static int ssl_parse_server_psk_hint(mbedtls_ssl_context *ssl, unsigned char **p, unsigned char *end);
static int ssl_parse_server_dh_params(mbedtls_ssl_context *ssl, unsigned char **p, unsigned char *end);
static int ssl_parse_server_ecdh_params(mbedtls_ssl_context *ssl, unsigned char **p, unsigned char *end);
static int ssl_parse_signature_algorithm(mbedtls_ssl_context *ssl, unsigned char **p, unsigned char *end, int *md_alg, int *pk_alg);
static int mbedtls_ssl_read_record(mbedtls_ssl_context *ssl);
static void mbedtls_ssl_send_alert_message(mbedtls_ssl_context *ssl, int level, int message);
static size_t mbedtls_ssl_hs_hdr_len(mbedtls_ssl_context *ssl);
static int mbedtls_ssl_ciphersuite_uses_server_signature(const mbedtls_ssl_ciphersuite_t *info);
static int mbedtls_ssl_get_ciphersuite_sig_pk_alg(const mbedtls_ssl_ciphersuite_t *info);
static int mbedtls_ssl_get_key_exchange_md_ssl_tls(mbedtls_ssl_context *ssl, unsigned char *hash, unsigned char *params, size_t params_len);
static int mbedtls_ssl_get_key_exchange_md_tls1_2(mbedtls_ssl_context *ssl, unsigned char *hash, unsigned char *params, size_t params_len, int md_alg);
static const void *mbedtls_md_info_from_type(int md_type);
static size_t mbedtls_md_get_size(const void *md_info);
static int mbedtls_pk_can_do(const mbedtls_pk_context *pk, int type);
static int mbedtls_pk_verify(const mbedtls_pk_context *pk, int md_alg, const unsigned char *hash, size_t hash_len, const unsigned char *sig, size_t sig_len);
static int mbedtls_ecjpake_read_round_two(void *ctx, const unsigned char *buf, size_t len);