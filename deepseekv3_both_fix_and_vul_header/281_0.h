#include <stdint.h>

typedef struct RIJNDAEL_context {
    uint8_t *keyschenc;
    int rounds;
} RIJNDAEL_context;

extern unsigned int _gcry_aes_amd64_encrypt_block(uint8_t *keysched, unsigned char *out,
                                                  const unsigned char *in, int rounds,
                                                  const void *encT);
extern unsigned int _gcry_aes_arm_encrypt_block(uint8_t *keysched, unsigned char *out,
                                               const unsigned char *in, int rounds,
                                               const void *encT);
extern unsigned int do_encrypt_fn(const RIJNDAEL_context *ctx,
                                 unsigned char *bx, const unsigned char *ax);

extern const void *encT;