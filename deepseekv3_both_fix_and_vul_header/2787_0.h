#include <limits.h>

typedef int mp_err;
typedef unsigned long mp_digit;
typedef unsigned long long mp_word;

#define MP_VAL -1
#define MP_OKAY 0
#define MP_WARRAY 0
#define MP_MAXFAST 0
#define MP_MASK ((mp_word)((1ULL << (CHAR_BIT * sizeof(mp_digit))) - 1))
#define MP_DIGIT_BIT (CHAR_BIT * sizeof(mp_digit))

typedef struct {
    int used;
    mp_digit *dp;
} mp_int;

mp_err s_mp_mul_digs_fast(const mp_int *a, const mp_int *b, mp_int *c, int digs);
mp_err mp_init_size(mp_int *a, int size);
void mp_clamp(mp_int *a);
void mp_exch(mp_int *a, mp_int *b);
void mp_clear(mp_int *a);

#define MP_MIN(a, b) ((a) < (b) ? (a) : (b))