#include <stddef.h>
#include <stdint.h>

typedef uint32_t TEE_Result;
typedef unsigned long uaddr_t;

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_PARAMETERS 1
#define TEE_MEMORY_ACCESS_READ 1
#define TEE_MEMORY_ACCESS_ANY_OWNER 2
#define TEE_HANDLE_FLAG_INITIALIZED 1
#define CRYP_STATE_INITIALIZED 1

struct tee_ta_session {
    struct tee_ta_context *ctx;
};

struct tee_ta_context;

struct tee_obj {
    struct {
        uint32_t handleFlags;
    } info;
    void *attr;
};

struct tee_cryp_state {
    void *ctx;
    uint32_t algo;
    uint32_t mode;
    uint32_t key1;
    void (*ctx_finalize)(void);
    uint32_t state;
};

struct tee_cryp_obj_secret {
    size_t key_size;
};

struct user_ta_ctx;

static inline struct user_ta_ctx *to_user_ta_ctx(struct tee_ta_context *ctx) {
    return (struct user_ta_ctx *)ctx;
}

static inline uaddr_t tee_svc_uref_to_vaddr(unsigned long uref) {
    return (uaddr_t)uref;
}

typedef void (*tee_cryp_ctx_finalize_func_t)(void);

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
TEE_Result tee_mmu_check_access_rights(struct user_ta_ctx *ctx, uint32_t flags, uaddr_t addr, size_t len);
TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, uaddr_t state, struct tee_cryp_state **cs);
TEE_Result tee_obj_get(struct user_ta_ctx *ctx, uint32_t key, struct tee_obj **o);
TEE_Result crypto_authenc_init(void *ctx, uint32_t algo, uint32_t mode, uint8_t *key, size_t key_size, const void *nonce, size_t nonce_len, size_t tag_len, size_t aad_len, size_t payload_len);
void crypto_authenc_final(void);