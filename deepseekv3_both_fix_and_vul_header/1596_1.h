#include <stdint.h>
#include <stddef.h>

#define TEE_HANDLE_NULL 0
#define TEE_OPERATION_MAC 0
#define TEE_HANDLE_FLAG_INITIALIZED 0
#define TEE_OPERATION_STATE_ACTIVE 0
#define TEE_OPERATION_STATE_INITIAL 0
#define CONFIG_MAX_CRYPTO_CHUNK_SIZE 0
#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_PARAMETERS 0
#define TEE_ERROR_SHORT_BUFFER 0

typedef uint32_t TEE_Result;

struct tee_operation_info {
    uint32_t operationClass;
    uint32_t handleState;
};

struct tee_operation_state {
    uint32_t state;
};

typedef struct {
    struct tee_operation_info info;
    struct tee_operation_state *state;
    uint32_t operationState;
} *TEE_OperationHandle;

void TEE_Panic(TEE_Result res);

TEE_Result utee_hash_final(struct tee_operation_state *state, const void *message, uint32_t messageLen, void *mac, uint64_t *macLen);