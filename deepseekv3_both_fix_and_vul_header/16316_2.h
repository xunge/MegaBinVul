#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct crypto_aead_aes256gcm_state crypto_aead_aes256gcm_state;
extern int crypto_aead_aes256gcm_decrypt_afternm(
    unsigned char *m, unsigned long long *mlen,
    unsigned char *nsec,
    const unsigned char *c, unsigned long long clen,
    const unsigned char *ad, unsigned long long adlen,
    const unsigned char *npub, const crypto_aead_aes256gcm_state *ctx
);
#define crypto_aead_aes256gcm_ABYTES 16

class AES_GCM_DecryptContext {
public:
    bool Decrypt(
        const void *pEncryptedDataAndTag, size_t cbEncryptedDataAndTag,
        const void *pIV,
        void *pPlaintextData, uint32_t *pcbPlaintextData,
        const void *pAdditionalAuthenticationData, size_t cbAuthenticationData
    );
private:
    crypto_aead_aes256gcm_state *m_ctx;
};

typedef uint32_t uint32;