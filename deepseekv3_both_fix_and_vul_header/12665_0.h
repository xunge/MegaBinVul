#include <stdint.h>

typedef unsigned int uECC_word_t;

typedef struct uECC_Curve_t {
    unsigned num_n_bits;
    const uECC_word_t *n;
} *uECC_Curve;

#define BITS_TO_BYTES(bits) (((bits) + 7) / 8)
#define BITS_TO_WORDS(bits) (((bits) + (8 * sizeof(uECC_word_t)) - 1) / (8 * sizeof(uECC_word_t)))
#define uECC_WORD_BITS (8 * sizeof(uECC_word_t))

#if !defined(uECC_VLI_NATIVE_LITTLE_ENDIAN)
void uECC_vli_bytesToNative(uECC_word_t *native, const uint8_t *bits, unsigned bits_size);
#endif

void uECC_vli_clear(uECC_word_t *vli, int num_words);
int uECC_vli_cmp_unsafe(const uECC_word_t *left, const uECC_word_t *right, int num_words);
void uECC_vli_sub(uECC_word_t *result, const uECC_word_t *left, const uECC_word_t *right, int num_words);