#include <stdlib.h>
#include <string.h>

typedef int mp_err;
typedef unsigned long mp_digit;

#define MP_VAL -1
#define MP_MEM -2
#define MP_OKAY 0

#define MP_REALLOC(ptr, oldsize, newsize) realloc(ptr, newsize)

#define MP_ZERO_DIGITS(p, n) memset((p), 0, (n) * sizeof(mp_digit))

typedef struct {
    mp_digit *dp;
    int alloc;
} mp_int;