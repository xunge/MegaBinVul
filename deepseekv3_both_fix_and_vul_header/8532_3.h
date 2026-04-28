#include <stdint.h>
#include <stddef.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef uint8_t BYTE;

typedef struct rdpRdp
{
    void* rc4_decrypt_key;
    unsigned int decrypt_use_count;
    BYTE* decrypt_key;
    BYTE* decrypt_update_key;
    int rc4_key_len;
    unsigned int decrypt_checksum_use_count;
} rdpRdp;

void security_key_update(BYTE* decrypt_key, BYTE* decrypt_update_key, int rc4_key_len);
void crypto_rc4_free(void* rc4_key);
void* crypto_rc4_init(BYTE* key, int key_len);
void crypto_rc4(void* rc4_key, int length, BYTE* input, BYTE* output);