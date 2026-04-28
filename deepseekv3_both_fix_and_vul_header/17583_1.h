#include <string.h>
#include <stdint.h>

#define OT_PBKDF2_SALT_MAX_LEN 32
#define OT_COMMISSIONING_PASSPHRASE_MIN_SIZE 6
#define OT_COMMISSIONING_PASSPHRASE_MAX_SIZE 255
#define OT_NETWORK_NAME_MAX_SIZE 16
#define OT_EXT_PAN_ID_SIZE 8
#define OT_PSKC_MAX_SIZE 16

enum otError {
    OT_ERROR_NONE,
    OT_ERROR_INVALID_ARGS
};

namespace Mac {
    struct ExtendedPanId {
        uint8_t m8[OT_EXT_PAN_ID_SIZE];
    };
}

struct Pskc {
    uint8_t m8[OT_PSKC_MAX_SIZE];
};

class Commissioner {
public:
    otError GeneratePskc(const char *aPassPhrase,
                        const char *aNetworkName,
                        const Mac::ExtendedPanId &aExtPanId,
                        Pskc &aPskc);
};

#define VerifyOrExit(condition, action) \
    do { if (!(condition)) { action; goto exit; } } while (false)

extern void otPbkdf2Cmac(const uint8_t *aPassPhrase, uint16_t aPassPhraseLen,
                        const uint8_t *aSalt, uint16_t aSaltLen,
                        uint32_t aIterationCounter, uint16_t aKeyLen, uint8_t *aKey);