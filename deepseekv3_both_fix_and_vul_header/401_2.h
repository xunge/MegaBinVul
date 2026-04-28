#include <stddef.h>
#include <stdlib.h>

typedef unsigned int TEE_Result;
#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_PARAMETERS 1
#define TEE_ERROR_NOT_IMPLEMENTED 2
#define TEE_ERROR_OUT_OF_MEMORY 3
#define TEE_ERROR_OVERFLOW 4

#define TEE_HANDLE_FLAG_PERSISTENT (1 << 0)
#define TEE_HANDLE_FLAG_INITIALIZED (1 << 1)

#define ATTR_USAGE_POPULATE 0

#define MUL_OVERFLOW(a, b, res) __builtin_mul_overflow(a, b, res)

struct tee_ta_session {
    struct user_ta_ctx *ctx;
};

struct user_ta_ctx;
struct tee_obj;
struct utee_attribute;
struct tee_cryp_obj_type_props;

typedef struct {
    unsigned int attributeID;
    union {
        void *buffer;
        unsigned long value;
    } content;
    unsigned long length;
} TEE_Attribute;

struct tee_obj_info {
    unsigned int handleFlags;
    unsigned int objectType;
};

struct tee_obj {
    struct tee_obj_info info;
};

static inline struct user_ta_ctx *to_user_ta_ctx(void *ctx) { return (struct user_ta_ctx *)ctx; }
static inline void *tee_svc_uref_to_vaddr(unsigned long uref) { return (void *)uref; }

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
TEE_Result tee_obj_get(struct user_ta_ctx *ctx, void *obj, struct tee_obj **o);
const struct tee_cryp_obj_type_props *tee_svc_find_type_props(unsigned int objectType);
TEE_Result copy_in_attrs(struct user_ta_ctx *ctx, struct utee_attribute *usr_attrs, unsigned long attr_count, TEE_Attribute *attrs);
TEE_Result tee_svc_cryp_check_attr(unsigned int usage, const struct tee_cryp_obj_type_props *props, TEE_Attribute *attrs, unsigned long attr_count);
TEE_Result tee_svc_cryp_obj_populate_type(struct tee_obj *o, const struct tee_cryp_obj_type_props *type_props, TEE_Attribute *attrs, unsigned long attr_count);