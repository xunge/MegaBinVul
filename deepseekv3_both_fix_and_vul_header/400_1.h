#include <stdint.h>
#include <string.h>

#define TEE_NUM_PARAMS 4
#define TEE_PARAM_TYPE_GET(types, index) (((types) >> ((index) * 4)) & 0xF)

enum {
    TEE_PARAM_TYPE_NONE = 0,
    TEE_PARAM_TYPE_VALUE_INPUT,
    TEE_PARAM_TYPE_VALUE_OUTPUT,
    TEE_PARAM_TYPE_VALUE_INOUT,
    TEE_PARAM_TYPE_MEMREF_INPUT,
    TEE_PARAM_TYPE_MEMREF_OUTPUT,
    TEE_PARAM_TYPE_MEMREF_INOUT
};

#define TEE_MEMORY_ACCESS_READ (1 << 0)
#define TEE_MEMORY_ACCESS_WRITE (1 << 1)
#define TEE_MEMORY_ACCESS_ANY_OWNER (1 << 2)

#define TEE_SUCCESS 0
#define TEE_ERROR_ACCESS_DENIED 0xFFFF0003

typedef uint32_t TEE_Result;

struct mobj_virt;
extern struct mobj_virt mobj_virt;

struct user_ta_ctx;
struct tee_ta_param {
    uint32_t types;
    union {
        struct {
            struct mobj_virt *mobj;
            uintptr_t offs;
            size_t size;
        } mem;
        struct {
            uint32_t a;
            uint32_t b;
        } val;
    } u[TEE_NUM_PARAMS];
};

struct utee_params {
    uint32_t types;
    uint32_t vals[TEE_NUM_PARAMS * 2];
};

int tee_mmu_check_access_rights(struct user_ta_ctx *utc, uint32_t flags,
                               uintptr_t addr, size_t size);