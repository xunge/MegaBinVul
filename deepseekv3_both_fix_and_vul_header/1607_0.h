#include <stdlib.h>
#include <stdint.h>

typedef uint32_t TEE_Result;
#define TEE_SUCCESS 0
#define TEE_ERROR_OUT_OF_MEMORY 1

void *TEE_Malloc(size_t size, uint32_t flags);
#define TEE_MALLOC_FILL_ZERO 0

TEE_Result cipher_get_ctx_size(uint32_t algo, size_t *ctx_size);