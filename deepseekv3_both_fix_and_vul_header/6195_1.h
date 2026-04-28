#include <stddef.h>
#include <stdint.h>

typedef uint32_t TEE_Result;
typedef uintptr_t uaddr_t;

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_STATE 0xFFFF0000
#define TEE_MEMORY_ACCESS_READ 0x1
#define TEE_MEMORY_ACCESS_ANY_OWNER 0x2

#define TEE_OPERATION_AE 0x10
#define TEE_ALG_GET_CLASS(algo) ((algo) >> 28)

enum cryp_state {
    CRYP_STATE_INITIALIZED
};

struct tee_ta_session {
    void *ctx;
};

struct user_ta_ctx;

struct tee_cryp_state {
    uint32_t algo;
    uint32_t mode;
    void *ctx;
    enum cryp_state state;
};

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
TEE_Result tee_mmu_check_access_rights(struct user_ta_ctx *ctx, uint32_t flags, uaddr_t addr, size_t len);
struct user_ta_ctx *to_user_ta_ctx(void *ctx);
void *tee_svc_uref_to_vaddr(unsigned long uref);
TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, void *state, struct tee_cryp_state **cs);
TEE_Result crypto_authenc_update_aad(void *ctx, uint32_t algo, uint32_t mode, const void *aad, size_t aad_len);