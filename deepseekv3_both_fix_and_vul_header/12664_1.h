#include <stdint.h>
#include <string.h>

#define uECC_MAX_WORDS 8
#define uECC_VLI_NATIVE_LITTLE_ENDIAN 1
#define BITS_TO_WORDS(bits) ((bits + 31) / 32)
#define BITS_TO_BYTES(bits) ((bits + 7) / 8)

typedef unsigned int uECC_word_t;
typedef unsigned long bitcount_t;
typedef unsigned int wordcount_t;

typedef struct uECC_Curve_t {
    wordcount_t num_words;
    bitcount_t num_n_bits;
    wordcount_t num_bytes;
    const uECC_word_t *p;
    const uECC_word_t *n;
    const uECC_word_t *G;
} *uECC_Curve;

typedef struct EccPoint {
    uECC_word_t x[uECC_MAX_WORDS];
    uECC_word_t y[uECC_MAX_WORDS];
} EccPoint;

extern int (*g_rng_function)(uint8_t *dest, unsigned size);

int uECC_vli_isZero(const uECC_word_t *vli, wordcount_t num_words);
int uECC_vli_cmp(const uECC_word_t *left, const uECC_word_t *right, wordcount_t num_words);
uECC_word_t regularize_k(const uECC_word_t *k, uECC_word_t *tmp, uECC_word_t *s, uECC_Curve curve);
int uECC_generate_random_int(uECC_word_t *random, const uECC_word_t *top, wordcount_t num_words);
void EccPoint_mult(uECC_word_t *result, const EccPoint *point, const uECC_word_t *scalar, const uECC_word_t *initial_Z, bitcount_t num_bits, uECC_Curve curve);
void uECC_vli_clear(uECC_word_t *vli, wordcount_t num_words);
void uECC_vli_modMult(uECC_word_t *result, const uECC_word_t *left, const uECC_word_t *right, const uECC_word_t *mod, wordcount_t num_words);
void uECC_vli_modInv(uECC_word_t *result, const uECC_word_t *input, const uECC_word_t *mod, wordcount_t num_words);
void uECC_vli_nativeToBytes(uint8_t *bytes, int num_bytes, const uECC_word_t *native);
void uECC_vli_bytesToNative(uECC_word_t *native, const uint8_t *bytes, int num_bytes);
void uECC_vli_set(uECC_word_t *dest, const uECC_word_t *src, wordcount_t num_words);
void uECC_vli_modAdd(uECC_word_t *result, const uECC_word_t *left, const uECC_word_t *right, const uECC_word_t *mod, wordcount_t num_words);
bitcount_t uECC_vli_numBits(const uECC_word_t *vli, wordcount_t max_words);
void bits2int(uECC_word_t *native, const uint8_t *bits, unsigned bits_size, uECC_Curve curve);