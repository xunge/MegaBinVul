#include <stdint.h>
#include <string.h>

#define MAX_HASH_SIZE 64
#define PREAMBLE_SIZE 13

typedef enum {
    CIPHER_STREAM,
    CIPHER_BLOCK
} cipher_type;

typedef enum {
    GNUTLS_MAC_NULL,
    GNUTLS_E_DECRYPTION_FAILED,
    GNUTLS_E_DECOMPRESSION_FAILED,
    GNUTLS_E_INTERNAL_ERROR
} gnutls_error_codes;

typedef struct {
    unsigned char *data;
    unsigned int size;
} gnutls_datum_t;

typedef struct {
    void *cipher_state;
    gnutls_datum_t mac_secret;
    uint64_t sequence_number;
} read_params_st;

typedef struct {
    int mac_algorithm;
    int cipher_algorithm;
    read_params_st read;
} record_parameters_st;

typedef struct gnutls_session_int {
    struct {
        int version;
    } security_parameters;
} *gnutls_session_t;

typedef unsigned char opaque;

typedef struct {
    void *context;
} digest_hd_st;

#define UINT64DATA(x) (x)

int gnutls_protocol_get_version(gnutls_session_t session);
int _gnutls_hash_get_algo_len(int algorithm);
int gnutls_cipher_get_block_size(int algorithm);
int _gnutls_cipher_is_block(int algorithm);
int _gnutls_cipher_decrypt(void *state, unsigned char *data, int size);
int _gnutls_version_has_explicit_iv(int version);
int _gnutls_version_has_variable_padding(int version);
uint16_t _gnutls_conv_uint16(uint16_t value);
int mac_init(digest_hd_st *td, int algorithm, unsigned char *secret, int size, int version);
int mac_hash(digest_hd_st *td, opaque *data, int size, int version);
int mac_deinit(digest_hd_st *td, unsigned char *out, int version);
int make_preamble(uint64_t seq, uint8_t type, uint16_t length, int version, opaque *out);
void _gnutls_record_log(const char *format, ...);
void gnutls_assert(void);