#include <stdint.h>
#include <string.h>

#define MAX_HASH_SIZE 64
#define GNUTLS_TLS1 1
#define GNUTLS_TLS1_1 2
#define GNUTLS_MAC_NULL 0
#define GNUTLS_E_INTERNAL_ERROR -1
#define GNUTLS_E_DECRYPTION_FAILED -2
#define GNUTLS_E_DECOMPRESSION_FAILED -3

typedef struct {
    unsigned char *data;
    unsigned int size;
} gnutls_datum_t;

typedef unsigned int gnutls_protocol_t;

typedef struct {
    int read_mac_algorithm;
    int read_bulk_cipher_algorithm;
    int version;
} security_parameters_st;

typedef struct {
    gnutls_datum_t read_mac_secret;
    void *read_cipher_state;
    uint64_t read_sequence_number;
} connection_state_st;

typedef struct gnutls_session_int {
    security_parameters_st security_parameters;
    connection_state_st connection_state;
} *gnutls_session_t;

typedef unsigned char opaque;

typedef struct {
    int dummy;
} digest_hd_st;

#define CIPHER_STREAM 0
#define CIPHER_BLOCK 1

int _gnutls_hash_get_algo_len(int algorithm);
gnutls_protocol_t gnutls_protocol_get_version(gnutls_session_t session);
uint8_t _gnutls_version_get_minor(gnutls_protocol_t ver);
uint8_t _gnutls_version_get_major(gnutls_protocol_t ver);
uint16_t _gnutls_cipher_get_block_size(int algorithm);
int mac_init(digest_hd_st *td, int algorithm, const void *key, size_t key_size, gnutls_protocol_t ver);
int _gnutls_cipher_is_block(int algorithm);
int _gnutls_cipher_decrypt(void *state, void *data, size_t data_size);
uint16_t _gnutls_conv_uint16(uint16_t num);
void _gnutls_hmac(digest_hd_st *handle, const void *text, size_t text_size);
void mac_deinit(digest_hd_st *handle, void *digest, gnutls_protocol_t ver);
void gnutls_assert(void);
#define UINT64DATA(x) (&(x))