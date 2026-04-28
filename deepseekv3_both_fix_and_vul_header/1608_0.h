#include <stdlib.h>
#include <stdint.h>

typedef uint32_t TEE_Result;
#define TEE_SUCCESS 0
#define TEE_ERROR_OUT_OF_MEMORY 1

TEE_Result mac_get_ctx_size(uint32_t algo, size_t *ctx_size);

#define TEE_Malloc(size, flags) calloc(1, size)
#define TEE_MALLOC_FILL_ZERO 0