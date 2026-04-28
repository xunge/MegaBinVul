#include <stdint.h>
#include <string.h>
#include <stddef.h>

#define GNUTLS_RANDOM_SIZE 32
#define GNUTLS_MAX_SESSION_ID_SIZE 32
#define GNUTLS_E_UNEXPECTED_PACKET_LENGTH -1
#define GNUTLS_E_UNSUPPORTED_VERSION_PACKET -2
#define GNUTLS_E_RECEIVED_ILLEGAL_PARAMETER -3
#define GNUTLS_E_UNWANTED_ALGORITHM -4

#define GNUTLS_EXT_FLAG_TLS12_SERVER_HELLO 1
#define GNUTLS_EXT_FLAG_TLS13_SERVER_HELLO 2
#define GNUTLS_EXT_VERSION_NEG 1
#define GNUTLS_EXT_MANDATORY 2
#define GNUTLS_EXT_APPLICATION 3
#define GNUTLS_EXT_TLS 4
#define _GNUTLS_EXT_TLS_POST_CS 5

#define HSK_HRR_RECEIVED 1
#define HSK_SERVER_HELLO_RECEIVED 2
#define HSK_PSK_SELECTED 4

#define DECR_LEN(len, size) do { len -= size; if (len < 0) return GNUTLS_E_UNEXPECTED_PACKET_LENGTH; } while (0)
#define unlikely(x) (x)

typedef struct security_parameters_st {
    uint8_t session_id[GNUTLS_MAX_SESSION_ID_SIZE];
    size_t session_id_size;
    int etm;
    struct {
        struct {
            int block_algorithm;
        } *cs;
    };
} security_parameters_st;

typedef struct gnutls_session_int {
    struct {
        struct {
            int force_etm;
        } *priorities;
        unsigned int hsk_flags;
        uint8_t hrr_cs[2];
    } internals;
    security_parameters_st security_parameters;
    struct {
        struct {
            uint8_t tls13[32];
        } proto;
    } key;
} *gnutls_session_t;

typedef struct version_entry_st {
    int id;
    uint8_t major;
    uint8_t minor;
    int tls13_sem;
} version_entry_st;

typedef struct cipher_entry_st {
    int block_algorithm;
} cipher_entry_st;

enum {
    CIPHER_BLOCK = 1
};

const version_entry_st *get_version(gnutls_session_t session);
const version_entry_st *nversion_to_entry(uint8_t major, uint8_t minor);
int _gnutls_set_current_version(gnutls_session_t session, int id);
int _gnutls_parse_hello_extensions(gnutls_session_t session, unsigned int flags, int type, uint8_t *data, int len);
int _gnutls_set_server_random(gnutls_session_t session, const version_entry_st *vers, uint8_t *random);
int client_check_if_resuming(gnutls_session_t session, uint8_t *session_id, uint8_t session_id_len);
int set_client_ciphersuite(gnutls_session_t session, uint8_t *cs_pos);
int _tls13_init_secret(gnutls_session_t session, void *data, int len);
int set_auth_types(gnutls_session_t session);
void reset_binders(gnutls_session_t session);
int _gnutls_nversion_is_supported(gnutls_session_t session, uint8_t major, uint8_t minor);
int _gnutls_cipher_type(const cipher_entry_st *cipher);
const cipher_entry_st *cipher_to_entry(int algorithm);
void gnutls_memset(void *data, int c, size_t size);
void gnutls_assert(void);
int gnutls_assert_val(int ret);
void _gnutls_handshake_log(const char *fmt, ...);