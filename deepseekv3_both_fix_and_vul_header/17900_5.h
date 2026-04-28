#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MAX_HASH_SIZE 64
#define MAX_PREAMBLE_SIZE 13
#define AEAD_EXPLICIT_DATA_SIZE 8
#define AEAD_IMPLICIT_DATA_SIZE 4
#define UINT64DATA(x) (x)
#define GNUTLS_E_INTERNAL_ERROR -1
#define GNUTLS_E_UNEXPECTED_PACKET_LENGTH -2
#define GNUTLS_E_DECRYPTION_FAILED -3
#define GNUTLS_E_DECOMPRESSION_FAILED -4
#define GNUTLS_SSL3 0

typedef enum {
    CIPHER_STREAM,
    CIPHER_BLOCK
} cipher_type_t;

typedef struct {
    uint8_t *data;
    size_t size;
} gnutls_datum_t;

typedef struct {
    unsigned int version;
} security_parameters_st;

typedef struct {
    security_parameters_st security_parameters;
} *gnutls_session_t;

typedef struct {
    gnutls_datum_t IV;
    struct {
        void *cipher;
    } cipher_state;
} cipher_read_state;

typedef struct {
    int cipher_algorithm;
    cipher_read_state read;
} record_parameters_st;

typedef uint64_t uint64;

static inline int gnutls_assert_val(int x) { return x; }
static inline void gnutls_assert(void) {}
static inline void _gnutls_record_log(const char *fmt, ...) {}

static cipher_type_t _gnutls_cipher_is_block(int algo) { return CIPHER_STREAM; }
static unsigned int _gnutls_auth_cipher_tag_len(void *state) { return 0; }
static int _gnutls_version_has_explicit_iv(unsigned int version) { return 0; }
static int _gnutls_auth_cipher_is_aead(void *state) { return 0; }
static int _gnutls_auth_cipher_setiv(void *state, const void *iv, size_t iv_size) { return 0; }
static int _gnutls_auth_cipher_add_auth(void *state, const void *data, size_t data_size) { return 0; }
static int _gnutls_auth_cipher_decrypt2(void *state, const void *in, size_t in_size, void *out, size_t out_size) { return 0; }
static int _gnutls_cipher_decrypt(void *handle, void *data, size_t data_size) { return 0; }
static int _gnutls_auth_cipher_tag(void *state, void *tag, size_t tag_size) { return 0; }
static unsigned int make_preamble(uint64_t sequence, uint8_t type, int length, unsigned int version, uint8_t *preamble) { return 0; }
static unsigned int gnutls_protocol_get_version(gnutls_session_t session) { return 0; }
static int gnutls_cipher_get_block_size(int algorithm) { return 0; }