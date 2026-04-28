#include <stdint.h>
#include <stddef.h>

typedef uint32_t TEE_Result;
typedef uintptr_t uaddr_t;

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_STATE 0xFFFF0000
#define TEE_ERROR_SHORT_BUFFER 0xFFFF0001
#define TEE_MEMORY_ACCESS_READ 0x1
#define TEE_MEMORY_ACCESS_WRITE 0x2
#define TEE_MEMORY_ACCESS_ANY_OWNER 0x4

#define TEE_OPERATION_AE 0xA
#define TEE_ALG_GET_CLASS(algo) ((algo) >> 28)

enum cryp_state {
    CRYP_STATE_INITIALIZED
};

struct tee_cryp_state {
    uint32_t algo;
    uint32_t mode;
    void *ctx;
    enum cryp_state state;
};

struct user_ta_ctx;

struct tee_ta_session {
    struct user_ta_ctx *ctx;
};

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, uaddr_t state, struct tee_cryp_state **cs);
struct user_ta_ctx *to_user_ta_ctx(void *ctx);
TEE_Result tee_mmu_check_access_rights(struct user_ta_ctx *ctx, uint32_t flags, uaddr_t addr, size_t len);
TEE_Result get_user_u64_as_size_t(size_t *dst, uint64_t *src);
TEE_Result put_user_u64(uint64_t *dst, uint64_t src);
TEE_Result crypto_authenc_update_payload(void *ctx, uint32_t algo, uint32_t mode, const void *src_data, size_t src_len, void *dst_data, size_t *dst_len);
uaddr_t tee_svc_uref_to_vaddr(unsigned long uref);