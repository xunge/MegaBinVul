#include <stdint.h>
#include <stddef.h>

#define TEE_NUM_PARAMS 4
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define OPTEE_MSG_ATTR_TYPE_TMEM_INPUT 0
#define OPTEE_MSG_ATTR_TYPE_TMEM_OUTPUT 1
#define OPTEE_MSG_ATTR_TYPE_TMEM_INOUT 2
#define OPTEE_MSG_ATTR_TYPE_RMEM_INPUT 3
#define OPTEE_MSG_ATTR_TYPE_RMEM_OUTPUT 4
#define OPTEE_MSG_ATTR_TYPE_RMEM_INOUT 5

struct mobj;
struct tee_ta_param {
    union {
        struct {
            struct mobj *mobj;
        } mem;
    } u[TEE_NUM_PARAMS];
};

void mobj_put(struct mobj *mobj);