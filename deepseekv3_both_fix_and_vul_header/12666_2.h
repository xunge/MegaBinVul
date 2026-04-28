#include <stdint.h>
#include <string.h>

typedef unsigned bitcount_t;
typedef unsigned wordcount_t;
typedef uint32_t uECC_word_t;

#define uECC_MAX_WORDS 8
#define uECC_VLI_NATIVE_LITTLE_ENDIAN 1
#define BITS_TO_WORDS(bits) ((bits + 31) / 32)

typedef struct uECC_Curve_t *uECC_Curve;
typedef struct uECC_Curve_t {
    wordcount_t num_words;
    wordcount_t num_n_bits;
    uint8_t num_bytes;
    const uECC_word_t *G;
    const uECC_word_t *n;
    const uECC_word_t *p;
    void (*double_jacobian)(uECC_word_t *X1, uECC_word_t *Y1, uECC_word_t *Z1, uECC_Curve curve);
} uECC_Curve_t;

static inline bitcount_t smax(bitcount_t a, bitcount_t b) {
    return (a > b) ? a : b;
}

void uECC_vli_bytesToNative(uECC_word_t *dest, const uint8_t *src, wordcount_t num_bytes);
int uECC_vli_isZero(const uECC_word_t *vli, wordcount_t num_words);
int uECC_vli_cmp_unsafe(const uECC_word_t *left, const uECC_word_t *right, wordcount_t num_words);
void uECC_vli_modInv(uECC_word_t *result, const uECC_word_t *input, const uECC_word_t *mod, wordcount_t num_words);
void bits2int(uECC_word_t *dest, const uint8_t *src, unsigned src_size, uECC_Curve curve);
void uECC_vli_modMult(uECC_word_t *result, const uECC_word_t *left, const uECC_word_t *right, const uECC_word_t *mod, wordcount_t num_words);
void uECC_vli_set(uECC_word_t *dest, const uECC_word_t *src, wordcount_t num_words);
void uECC_vli_modSub(uECC_word_t *result, const uECC_word_t *left, const uECC_word_t *right, const uECC_word_t *mod, wordcount_t num_words);
void XYcZ_add(uECC_word_t *X1, uECC_word_t *Y1, uECC_word_t *X2, uECC_word_t *Y2, uECC_Curve curve);
void apply_z(uECC_word_t *X, uECC_word_t *Y, const uECC_word_t *Z, uECC_Curve curve);
bitcount_t uECC_vli_numBits(const uECC_word_t *vli, wordcount_t num_words);
int uECC_vli_testBit(const uECC_word_t *vli, bitcount_t bit);
void uECC_vli_clear(uECC_word_t *vli, wordcount_t num_words);
void uECC_vli_modMult_fast(uECC_word_t *result, const uECC_word_t *left, const uECC_word_t *right, uECC_Curve curve);
void uECC_vli_sub(uECC_word_t *result, const uECC_word_t *left, const uECC_word_t *right, wordcount_t num_words);
int uECC_vli_equal(const uECC_word_t *left, const uECC_word_t *right, wordcount_t num_words);