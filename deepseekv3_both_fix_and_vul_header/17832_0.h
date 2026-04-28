#include <stdint.h>
#include <string.h>

typedef enum
{
    SECURE_ELEMENT_SUCCESS,
    SECURE_ELEMENT_ERROR_NPE,
    SECURE_ELEMENT_ERROR_BUF_SIZE,
    SECURE_ELEMENT_FAIL_ENCRYPT,
    SECURE_ELEMENT_FAIL_CMAC,
    SECURE_ELEMENT_ERROR_INVALID_LORAWAM_SPEC_VERSION
} SecureElementStatus_t;

typedef enum
{
    JOIN_REQ
} JoinReqIdentifier_t;

typedef enum
{
    NWK_KEY,
    J_S_ENC_KEY,
    J_S_INT_KEY
} KeyIdentifier_t;

#define LORAMAC_JOIN_ACCEPT_FRAME_MAX_SIZE 28
#define LORAMAC_MHDR_FIELD_SIZE 1
#define LORAMAC_MIC_FIELD_SIZE 4
#define LORAMAC_JOIN_EUI_FIELD_SIZE 8
#define JOIN_ACCEPT_MIC_COMPUTATION_OFFSET 12
#define USE_LRWAN_1_1_X_CRYPTO 1

extern SecureElementStatus_t SecureElementAesEncrypt(uint8_t* buffer, uint8_t size, KeyIdentifier_t keyID, uint8_t* encBuffer);
extern SecureElementStatus_t SecureElementVerifyAesCmac(uint8_t* micBxBuffer, uint8_t bufferSize, uint32_t expectedMic, KeyIdentifier_t keyID);
extern void memcpy1(uint8_t *dst, const uint8_t *src, uint16_t size);
extern void memcpyr(uint8_t *dst, const uint8_t *src, uint16_t size);