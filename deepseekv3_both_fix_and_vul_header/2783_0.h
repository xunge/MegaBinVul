#include <stdint.h>

typedef int32_t mp_err;
typedef uint32_t mp_digit;

#define MP_VAL -1
#define MP_OKAY 0
#define MP_DIGIT_BIT 32

typedef struct {
    mp_digit *dp;
    int used;
} mp_int;

void mp_zero(mp_int *a);
mp_err mp_grow(mp_int *a, int size);