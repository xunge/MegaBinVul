#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BLOSC2_ERROR_NULL_POINTER -1
#define BLOSC2_ERROR_FAILURE -2
#define MAX_DISTANCE 65535
#define NDLZ_UNEXPECT_CONDITIONAL(cond) (cond)

#define BLOSC_UNUSED_PARAM(param) (void)(param)
#define BLOSC_ERROR_NULL(ptr, error) if ((ptr) == NULL) return (error)
#define BLOSC_TRACE_ERROR(msg) 

typedef struct {
    void* schunk;
} blosc2_cparams;

uint32_t XXH32(const void* input, size_t length, uint32_t seed);

int blosc2_meta_get(void* schunk, const char* name, uint8_t** meta, int32_t* meta_len);
void deserialize_meta(uint8_t* smeta, int32_t smeta_len, int8_t* ndim, int64_t* shape, int32_t* chunkshape, int32_t* blockshape);