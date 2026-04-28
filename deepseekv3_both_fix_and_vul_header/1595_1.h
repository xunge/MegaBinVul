#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define TEE_HANDLE_NULL NULL
#define CONFIG_MAX_CRYPTO_CHUNK_SIZE 4096

typedef uint32_t TEE_Result;

#define TEE_ERROR_BAD_PARAMETERS 0xFFFF0000
#define TEE_ERROR_SHORT_BUFFER 0xFFFF0001
#define TEE_SUCCESS 0x00000000

#define TEE_OPERATION_CIPHER 0x00000000
#define TEE_HANDLE_FLAG_INITIALIZED 0x00000001
#define TEE_OPERATION_STATE_ACTIVE 0x00000001

struct TEE_OperationInfo {
    uint32_t operationClass;
    uint32_t handleState;
};

struct TEE_OperationHandle {
    struct TEE_OperationInfo info;
    uint32_t operationState;
    size_t block_size;
    size_t buffer_offs;
    bool buffer_two_blocks;
    void *state;
};

typedef struct TEE_OperationHandle *TEE_OperationHandle;

extern TEE_Result tee_buffer_update(TEE_OperationHandle operation,
                                  TEE_Result (*func)(void *, const void *, uint32_t, void *, uint64_t *),
                                  const void *srcData, uint32_t srcLen,
                                  void *destData, uint64_t *destLen);

extern TEE_Result utee_cipher_update(void *state, const void *srcData,
                                   uint32_t srcLen, void *destData,
                                   uint64_t *destLen);

extern void TEE_Panic(TEE_Result res);