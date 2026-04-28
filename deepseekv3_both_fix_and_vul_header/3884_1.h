#include <stdint.h>
#include <string.h>

#define AT91_AES_KEY_SIZE_128 0
#define AT91_AES_KEY_SIZE_192 1
#define AT91_AES_KEY_SIZE_256 2
#define AT91_AES_BLOCK_SIZE_WORD 4
#define AT91_AES_BLOCK_SIZE_BYTE 16
#define AT91_AES_IV_SIZE_WORD 4
#define CONFIG_AES_KEY_SIZE_128

typedef int at91_aes_key_size_t;

extern void at91_aes_init(void);
extern void at91_aes_cleanup(void);
extern int at91_aes_cmac(unsigned int data_length, void *data, unsigned int *computed_cmac, at91_aes_key_size_t key_size, unsigned int *cmac_key);
extern unsigned int at91_aes_roundup(unsigned int data_length);
extern int at91_aes_cbc(unsigned int data_length, void *in_data, void *out_data, int is_encrypt, at91_aes_key_size_t key_size, unsigned int *cipher_key, unsigned int *iv);
extern int consttime_memequal(const void *b1, const void *b2, size_t len);
extern void init_keys(at91_aes_key_size_t *key_size, unsigned int *cipher_key, unsigned int *cmac_key, unsigned int *iv);

static unsigned int cmac_key[8];
static unsigned int cipher_key[8];
static unsigned int iv[AT91_AES_IV_SIZE_WORD];