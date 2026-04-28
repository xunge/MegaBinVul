#include <stdint.h>

typedef int32_t mp_err;
typedef uint32_t mp_digit;

#define MP_OKAY 0
#define MP_VAL -1
#define MP_DIGIT_BIT 32
#define MP_MASK 0xFFFFFFFFU

typedef struct {
    mp_digit *dp;
    int used;
    int alloc;
} mp_int;

mp_err mp_copy(const mp_int *a, mp_int *c);
mp_err mp_grow(mp_int *a, int size);
mp_err mp_lshd(mp_int *a, int shift);
void mp_clamp(mp_int *a);