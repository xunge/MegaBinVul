#include <stdint.h>
#include <stddef.h>

#define READ_ONCE(x) (x)
#define ADD_OVERFLOW(a, b, res) (*(res) = (a) + (b), 0)

typedef uint32_t TEE_Result;
#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_PARAMETERS 1
#define TEE_ERROR_SECURITY 2

struct optee_msg_param_rmem {
    uint64_t shm_ref;
    uint64_t offs;
    uint64_t size;
};

struct mobj {
    size_t size;
};

struct param_mem {
    struct mobj *mobj;
    uint64_t offs;
    uint64_t size;
};

struct mobj *mobj_reg_shm_get_by_cookie(uint64_t shm_ref);