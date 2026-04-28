#include <stdint.h>
#include <stddef.h>

#define TEE_MAX_HASH_SIZE 64
#define TEE_HANDLE_NULL 0
#define TEE_OPERATION_MAC 1
#define TEE_HANDLE_FLAG_INITIALIZED 1
#define TEE_OPERATION_STATE_ACTIVE 1
#define TEE_OPERATION_STATE_INITIAL 0
#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_PARAMETERS 1
#define TEE_ERROR_MAC_INVALID 2

typedef uint32_t TEE_Result;

typedef struct {
    struct {
        uint32_t operationClass;
        uint32_t handleState;
    } info;
    uint32_t operationState;
} *TEE_OperationHandle;

TEE_Result TEE_MACComputeFinal(TEE_OperationHandle operation,
                              const void *message, uint32_t messageLen,
                              uint8_t *mac, uint32_t *macLen);

int buf_compare_ct(const void *a, const void *b, size_t len);

void TEE_Panic(TEE_Result res);