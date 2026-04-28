#include <stdbool.h>
#include <stddef.h>

typedef struct {
    // 假设这些结构体包含必要的成员
} ecc_int256_t;

typedef struct {
    // 假设这些结构体包含必要的成员
} ecc_25519_work_t;

typedef struct {
    ecc_25519_work_t s1;
    ecc_25519_work_t u2;
    ecc_int256_t r;
} ecdsa_verify_context_t;

void ecc_25519_scalarmult(ecc_25519_work_t *out, const ecc_25519_work_t *point, const ecc_25519_work_t *scalar);
void ecc_25519_add(ecc_25519_work_t *out, const ecc_25519_work_t *a, const ecc_25519_work_t *b);
void ecc_25519_store_xy_legacy(ecc_int256_t *x, ecc_int256_t *y, const ecc_25519_work_t *point);
void ecc_25519_gf_sub(ecc_int256_t *out, const ecc_int256_t *a, const ecc_int256_t *b);
bool ecc_25519_gf_is_zero(const ecc_int256_t *a);