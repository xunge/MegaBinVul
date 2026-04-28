#include <limits.h>
#include <string.h>

typedef int mp_err;
typedef unsigned long mp_digit;
typedef unsigned long long mp_word;

#define MP_OKAY 0
#define MP_VAL -1
#define MP_WARRAY 32
#define MP_MASK ((mp_digit)((1ULL << (sizeof(mp_digit) * CHAR_BIT - 1)) - 1 + \
                           (1ULL << (sizeof(mp_digit) * CHAR_BIT - 1))))
#define MP_DIGIT_BIT (sizeof(mp_digit) * CHAR_BIT)

#define MP_MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef struct {
    int used;
    int alloc;
    mp_digit *dp;
} mp_int;

void mp_clamp(mp_int *a);
mp_err mp_grow(mp_int *a, int size);
#define MP_ZERO_DIGITS(d, n) memset((d), 0, (n) * sizeof(mp_digit))