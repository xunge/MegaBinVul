#include <stdint.h>
#include <stdlib.h>

typedef uint32_t TEE_Result;

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_STATE 1
#define TEE_ERROR_NOT_SUPPORTED 2
#define TEE_ERROR_OUT_OF_MEMORY 3
#define TEE_MALLOC_FILL_ZERO 0

#define TEE_TYPE_DATA 0
#define TEE_USAGE_DEFAULT 0

struct tee_cryp_obj_type_props {
    size_t quanta;
    size_t min_size;
    size_t max_size;
    size_t alloc_size;
};

struct tee_cryp_obj_secret {
    size_t alloc_size;
};

struct tee_obj_info {
    uint32_t objectType;
    size_t maxKeySize;
    uint32_t objectUsage;
};

struct tee_obj {
    void *attr;
    struct tee_obj_info info;
};

const struct tee_cryp_obj_type_props *tee_svc_find_type_props(uint32_t obj_type);

void *TEE_Malloc(size_t size, uint32_t flags);