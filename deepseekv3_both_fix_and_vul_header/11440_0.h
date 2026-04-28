#include <stddef.h>
#include <string.h>

#define SC_ERROR_INVALID_ARGUMENTS 1

struct sc_card {
    void *drv_data;
};

typedef struct {
    int smtype;
    unsigned char sk_enc[16];
} epass2003_exdata;

enum {
    KEY_TYPE_AES
};

void aes128_decrypt_cbc(const unsigned char *key, size_t key_len, const unsigned char iv[16], const unsigned char *in, size_t in_len, unsigned char *out);
void des3_decrypt_cbc(const unsigned char *key, size_t key_len, const unsigned char iv[16], const unsigned char *in, size_t in_len, unsigned char *out);