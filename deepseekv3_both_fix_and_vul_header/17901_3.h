#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PREAMBLE_SIZE 16
#define AEAD_IMPLICIT_DATA_SIZE 4
#define AEAD_EXPLICIT_DATA_SIZE 8
#define CIPHER_BLOCK 1

typedef enum {
    GNUTLS_E_MEMORY_ERROR = -1,
    GNUTLS_E_INTERNAL_ERROR = -2
} gnutls_error_codes;

typedef enum {
    GNUTLS_RND_NONCE
} gnutls_rnd_level;

typedef struct {
    uint8_t *data;
    size_t size;
} gnutls_datum_t;

typedef struct {
    struct {
        void *cipher_state;
        gnutls_datum_t IV;
        uint64_t sequence_number;
    } write;
    int cipher_algorithm;
    int mac_algorithm;
    unsigned int epoch;
} record_parameters_st;

typedef struct gnutls_session_int {
    struct {
        struct {
            int no_padding;
        } priorities;
    } internals;
    struct {
        int version;
    } security_parameters;
} *gnutls_session_t;

typedef enum {
    CONTENT_TYPE_CHANGE_CIPHER_SPEC = 20,
    CONTENT_TYPE_ALERT = 21,
    CONTENT_TYPE_HANDSHAKE = 22,
    CONTENT_TYPE_APPLICATION_DATA = 23
} content_type_t;

#define IS_DTLS(session) (0)
#define UINT64DATA(x) ((uint8_t*)&(x))

/* Function prototypes */
int _gnutls_auth_cipher_tag_len(void *cipher_state);
int gnutls_cipher_get_block_size(int algorithm);
int _gnutls_cipher_is_block(int algorithm);
int gnutls_protocol_get_version(gnutls_session_t session);
int _gnutls_version_has_explicit_iv(int version);
int _gnutls_auth_cipher_is_aead(void *cipher_state);
void _gnutls_hard_log(const char *format, ...);
const char *gnutls_cipher_get_name(int algorithm);
const char *gnutls_mac_get_name(int algorithm);
int make_preamble(uint8_t *seq, content_type_t type, size_t size, int ver, uint8_t *preamble);
int calc_enc_length(gnutls_session_t session, size_t size, int tag_size, uint8_t *pad, 
                   int random_pad, unsigned block_algo, int auth_cipher, int blocksize);
int gnutls_assert_val(int ret);
int _gnutls_rnd(gnutls_rnd_level level, void *data, size_t len);
int _gnutls_auth_cipher_setiv(void *cipher_state, const void *iv, size_t iv_size);
int _gnutls_auth_cipher_add_auth(void *cipher_state, const void *data, size_t data_size);
int _gnutls_auth_cipher_encrypt2_tag(void *cipher_state, const void *plain, size_t plain_size,
                                    void *cipher, size_t cipher_size, void *tag, size_t tag_size,
                                    size_t auth_size);