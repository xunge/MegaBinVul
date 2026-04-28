#include <stddef.h>

typedef unsigned char byte;

typedef struct WC_RNG WC_RNG;

typedef struct {
    int dummy;
} mp_int;

#define MP_OKAY 0
#define MP_LT -1
#define MP_YES 1
#define MP_ZERO_E -100
#define MEMORY_E -101

#define ECC_MAXSIZE 66
#define ECC_MAXSIZE_GEN (ECC_MAXSIZE + 8)
#define WOLFSSL_SMALL_STACK
#define DYNAMIC_TYPE_ECC_BUFFER 1

int wc_RNG_GenerateBlock(WC_RNG* rng, byte* buf, int size);
int mp_read_unsigned_bin(mp_int* a, const byte* buf, int size);
int mp_iszero(mp_int* a);
int mp_cmp(mp_int* a, mp_int* b);
int mp_mod(mp_int* a, mp_int* b, mp_int* c);
void ForceZero(void* mem, int len);
void* XMALLOC(size_t n, void* heap, int type);
void XFREE(void* p, void* heap, int type);