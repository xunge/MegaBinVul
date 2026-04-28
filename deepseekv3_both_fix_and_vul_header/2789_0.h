#include <stdlib.h>

typedef int mp_err;
typedef unsigned long mp_digit;

#define MP_VAL -2
#define MP_MEM -1
#define MP_OKAY 0
#define MP_ZPOS 0
#define MP_MIN_PREC 1
#define MP_MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    mp_digit *dp;
    int used;
    int alloc;
    int sign;
} mp_int;

void *MP_CALLOC(size_t num, size_t size);