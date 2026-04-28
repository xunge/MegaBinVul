#include <stdint.h>

typedef struct {
    uint8_t bytes[32];
} ecc_int256_t;

typedef struct {
    ecc_int256_t r;
    ecc_int256_t s;
} ecdsa_signature_t;

typedef struct {
    ecc_int256_t r;
    ecc_int256_t u2;
    ecc_int256_t s1;
} ecdsa_verify_context_t;

void ecc_25519_gf_recip(ecc_int256_t *out, const ecc_int256_t *in);
void ecc_25519_gf_reduce(ecc_int256_t *out, const ecc_int256_t *in);
void ecc_25519_gf_mult(ecc_int256_t *out, const ecc_int256_t *a, const ecc_int256_t *b);
void ecc_25519_scalarmult_base(ecc_int256_t *out, const ecc_int256_t *n);