#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define MPA_NUMBASE_METADATA_SIZE_IN_U32 4

struct bignum;
struct mpa_numbase_struct {
    size_t alloc;
};

size_t mpa_StaticVarSizeInU32(size_t size_bits);

void *TEE_Malloc(size_t size, int flags);
#define TEE_MALLOC_FILL_ZERO 0