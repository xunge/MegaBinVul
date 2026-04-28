#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct crypto_aead_aes256gcm_state crypto_aead_aes256gcm_state;

extern int crypto_aead_aes256gcm_encrypt_afternm(
    unsigned char *c, unsigned long long *clen,
    const unsigned char *m, unsigned long long mlen,
    const unsigned char *ad, unsigned long long adlen,
    const unsigned char *nsec,
    const unsigned char *npub,
    const crypto_aead_aes256gcm_state *ctx
);

#define crypto_aead_aes256gcm_ABYTES 16

class AES_GCM_EncryptContext {
public:
    bool Encrypt(
        const void *pPlaintextData, size_t cbPlaintextData,
        const void *pIV,
        void *pEncryptedDataAndTag, uint32_t *pcbEncryptedDataAndTag,
        const void *pAdditionalAuthenticationData, size_t cbAuthenticationData
    );
private:
    crypto_aead_aes256gcm_state *m_ctx;
};

typedef uint32_t uint32;