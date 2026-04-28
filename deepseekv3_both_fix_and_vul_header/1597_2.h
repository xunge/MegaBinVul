#include <stdint.h>
#include <stddef.h>

#define TEE_HANDLE_NULL 0
#define TEE_OPERATION_MAC 0
#define TEE_HANDLE_FLAG_INITIALIZED 0
#define TEE_OPERATION_STATE_ACTIVE 0
#define CONFIG_MAX_CRYPTO_CHUNK_SIZE 0
#define TEE_ERROR_BAD_PARAMETERS 0
#define TEE_SUCCESS 0

typedef uint32_t TEE_Result;

typedef struct {
    uint32_t operationClass;
    uint32_t handleState;
} TEE_OperationInfo;

typedef struct TEE_OperationHandle {
    TEE_OperationInfo info;
    uint32_t operationState;
    void *state;
} *TEE_OperationHandle;

void TEE_Panic(uint32_t error);
TEE_Result utee_hash_update(void *state, const void *chunk, uint32_t chunkSize);