#include <stdint.h>

typedef int32_t mp_err;
typedef uint32_t mp_digit;
typedef uint64_t mp_word;

#define MP_VAL -1
#define MP_OKAY 0
#define MP_HAS(x) (1)
#define MP_WARRAY 0
#define MP_MAXFAST 0
#define MP_MASK 0xFFFFFFFFUL
#define MP_DIGIT_BIT 32

typedef struct {
    int used;
    mp_digit *dp;
} mp_int;

mp_err s_mp_mul_high_digs_fast(const mp_int *a, const mp_int *b, mp_int *c, int digs);
mp_err mp_init_size(mp_int *a, int size);
void mp_clamp(mp_int *a);
void mp_exch(mp_int *a, mp_int *b);
void mp_clear(mp_int *a);

#define MP_MIN(x, y) ((x) < (y) ? (x) : (y))
#define MP_MAX(x, y) ((x) > (y) ? (x) : (y))