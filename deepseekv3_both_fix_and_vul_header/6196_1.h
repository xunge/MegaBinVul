#include <stdint.h>
#include <stddef.h>

typedef uint32_t TEE_Result;
#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_STATE 0xFFFF0006
#define TEE_ERROR_BAD_PARAMETERS 0xFFFF0004
#define TEE_ERROR_SHORT_BUFFER 0xFFFF0010

enum tee_mode {
    TEE_MODE_DECRYPT
};

enum tee_operation_class {
    TEE_OPERATION_AE
};

struct tee_cryp_state {
    uint32_t state;
    enum tee_mode mode;
    uint32_t algo;
    void *ctx;
};

struct tee_ta_session {
    void *ctx;
};

struct user_ta_ctx;

#define TEE_MEMORY_ACCESS_READ 0x1
#define TEE_MEMORY_ACCESS_WRITE 0x2
#define TEE_MEMORY_ACCESS_ANY_OWNER 0x4

#define CRYP_STATE_INITIALIZED 1

typedef unsigned long uaddr_t;

#define TEE_ALG_GET_CLASS(algo) ((algo) >> 28)

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, void *state, struct tee_cryp_state **cs);
TEE_Result tee_mmu_check_access_rights(struct user_ta_ctx *ctx, uint32_t flags, uaddr_t addr, size_t len);
TEE_Result get_user_u64_as_size_t(size_t *dst, uint64_t *src);
TEE_Result put_user_u64(uint64_t *dst, size_t src);
TEE_Result crypto_authenc_dec_final(void *ctx, uint32_t algo, const void *src, size_t src_len, void *dst, size_t *dst_len, const void *tag, size_t tag_len);
struct user_ta_ctx *to_user_ta_ctx(void *ctx);
void *tee_svc_uref_to_vaddr(unsigned long uref);