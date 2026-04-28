#include <stdint.h>
#include <stddef.h>

typedef struct st_picoquic_crypto_context_t {
    void *aead_encrypt;
} picoquic_crypto_context_t;

typedef struct st_picoquic_cnx_t {
    picoquic_crypto_context_t crypto_context[3];
    uint64_t *protoop_inputv;
} picoquic_cnx_t;

typedef uint64_t protoop_arg_t;

protoop_arg_t picoquic_aead_get_checksum_length(void *aead_encrypt);