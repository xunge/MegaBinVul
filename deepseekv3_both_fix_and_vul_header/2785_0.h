#include <stdint.h>

#define MP_WARRAY 32
#define MP_DIGIT_BIT 32
#define MP_MASK 0xFFFFFFFFU

typedef int32_t mp_err;
typedef uint32_t mp_digit;
typedef uint64_t mp_word;

#define MP_OKAY 0
#define MP_VAL -1

#define MP_MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef struct {
    int used;
    int alloc;
    mp_digit *dp;
} mp_int;

void mp_clamp(mp_int *a);
mp_err mp_grow(mp_int *a, int size);
#define MP_ZERO_DIGITS(p, n) memset((p), 0, (n) * sizeof(mp_digit))