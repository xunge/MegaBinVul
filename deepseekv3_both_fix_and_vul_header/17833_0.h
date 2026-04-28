#include <stdint.h>
#include <string.h>

typedef enum
{
    SECURE_ELEMENT_SUCCESS,
    SECURE_ELEMENT_ERROR,
    SECURE_ELEMENT_ERROR_NPE,
    SECURE_ELEMENT_ERROR_BUF_SIZE
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

#define LORAMAC_JOIN_ACCEPT_FRAME_MAX_SIZE 33
#define LORAMAC_JOIN_EUI_FIELD_SIZE 8
#define JOIN_ACCEPT_MIC_COMPUTATION_OFFSET 12

extern void* LR1110;

typedef enum
{
    LR1110_CRYPTO_STATUS_SUCCESS
} lr1110_crypto_status_t;

typedef enum
{
    LR1110_CRYPTO_LORAWAN_VERSION_1_0,
    LR1110_CRYPTO_LORAWAN_VERSION_1_1
} lr1110_crypto_lorawan_version_t;

void lr1110_crypto_process_join_accept(void* crypto, lr1110_crypto_status_t* status, uint8_t encKeyID, uint8_t nwkKey, lr1110_crypto_lorawan_version_t version, uint8_t* micHeader, uint8_t* encJoinAccept, uint8_t encJoinAcceptSize, uint8_t* decJoinAccept);
uint8_t convert_key_id_from_se_to_lr1110(KeyIdentifier_t keyID);
void memcpyr(uint8_t* dst, const uint8_t* src, uint16_t size);