#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define EXPORT

typedef enum {
    CRYPTOINFO_MODE_CLEAR,
    CRYPTOINFO_MODE_AES_CTR,
    CRYPTOINFO_MODE_AES_CBC
} cryptoinfo_mode_t;

typedef struct {
    uint32_t encryptBlocks;
    uint32_t skipBlocks;
} cryptoinfo_pattern_t;

typedef struct AMediaCodecCryptoInfo {
    int numsubsamples;
    uint8_t key[16];
    uint8_t iv[16];
    cryptoinfo_mode_t mode;
    cryptoinfo_pattern_t pattern;
    size_t *clearbytes;
    size_t *encryptedbytes;
} AMediaCodecCryptoInfo;