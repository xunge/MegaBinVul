#include <string.h>

typedef enum {
    AT91_AES_KEY_SIZE_128,
    AT91_AES_KEY_SIZE_192,
    AT91_AES_KEY_SIZE_256
} at91_aes_key_size_t;

#define AT91_AES_IV_SIZE_WORD 4
#define AT91_AES_BLOCK_SIZE_WORD 4
#define AT91_AES_BLOCK_SIZE_BYTE 16

extern void init_keys(at91_aes_key_size_t *key_size, unsigned int *cipher_key, unsigned int *cmac_key, unsigned int *iv);
extern void at91_aes_init(void);
extern int at91_aes_cmac(unsigned int data_length, void *data, unsigned int *computed_cmac, at91_aes_key_size_t key_size, unsigned int *cmac_key);
extern unsigned int at91_aes_roundup(unsigned int length);
extern int at91_aes_cbc(unsigned int data_length, void *input, void *output, int is_encrypt, at91_aes_key_size_t key_size, unsigned int *key, unsigned int *iv);
extern void at91_aes_cleanup(void);