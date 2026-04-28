#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t TEE_Result;
typedef unsigned long uaddr_t;

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_STATE 0xFFFF0000
#define TEE_ERROR_SHORT_BUFFER 0xFFFF0001

#define TEE_MEMORY_ACCESS_READ 0x1
#define TEE_MEMORY_ACCESS_WRITE 0x2
#define TEE_MEMORY_ACCESS_ANY_OWNER 0x4

enum cryp_state {
    CRYP_STATE_INITIALIZED
};

struct tee_cryp_state {
    void *ctx;
    uint32_t algo;
    uint32_t mode;
    enum cryp_state state;
    void (*ctx_finalize)(void *ctx, uint32_t algo);
};

struct user_ta_ctx;

struct tee_ta_session {
    struct user_ta_ctx *ctx;
};

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, void *state, struct tee_cryp_state **cs);
TEE_Result tee_mmu_check_access_rights(struct user_ta_ctx *ctx, uint32_t flags, uaddr_t addr, size_t len);
TEE_Result get_user_u64_as_size_t(size_t *dst, uint64_t *src);
TEE_Result put_user_u64(uint64_t *dst, size_t src);
TEE_Result tee_do_cipher_update(void *ctx, uint32_t algo, uint32_t mode, bool last_block, const void *src, size_t src_len, void *dst);
struct user_ta_ctx *to_user_ta_ctx(void *ctx);
void *tee_svc_uref_to_vaddr(unsigned long uref);