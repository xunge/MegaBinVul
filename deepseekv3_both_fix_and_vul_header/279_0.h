#include <stddef.h>
#include <stdint.h>

typedef struct RIJNDAEL_context {
    unsigned int rounds;
    uint32_t *keyschdec;
} RIJNDAEL_context;

extern unsigned int _gcry_aes_amd64_decrypt_block(uint32_t *keysched, unsigned char *out,
                                                 const unsigned char *in, unsigned int rounds,
                                                 const void *tables);
extern unsigned int _gcry_aes_arm_decrypt_block(uint32_t *keysched, unsigned char *out,
                                               const unsigned char *in, unsigned int rounds,
                                               const void *tables);
extern unsigned int do_decrypt_fn(const RIJNDAEL_context *ctx, unsigned char *bx,
                                 const unsigned char *ax);

extern const void *dec_tables;