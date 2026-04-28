#include <stdlib.h>
#include <stddef.h>

typedef unsigned long mp_limb_t;
typedef unsigned long long mp_twolimb_t;

typedef struct {
    mp_limb_t *limbs;
    size_t nlimbs;
} mpn_t;

#define GMP_LIMB_BITS (sizeof(mp_limb_t) * 8)

static size_t xsum(size_t a, size_t b) {
    return a + b;
}