#include <stddef.h>
#include <stdint.h>

typedef uint32_t TEE_Result;
typedef unsigned long uaddr_t;

#define TEE_ERROR_BAD_PARAMETERS 0xFFFF0006
#define TEE_SUCCESS 0x00000000
#define TEE_ERROR_BAD_STATE 0xFFFF0007

#define TEE_MEMORY_ACCESS_READ 0x00000001
#define TEE_MEMORY_ACCESS_ANY_OWNER 0x00000002

#define TEE_OPERATION_DIGEST 0x00000001
#define TEE_OPERATION_MAC 0x00000002

#define TEE_ALG_GET_CLASS(algo) ((algo) & 0xFF000000)

#define CRYP_STATE_INITIALIZED 0x00000001

struct tee_ta_session;
struct user_ta_ctx;
struct tee_cryp_state {
    uint32_t state;
    uint32_t algo;
    void *ctx;
};

struct tee_ta_session {
    struct user_ta_ctx *ctx;
};

static inline struct user_ta_ctx *to_user_ta_ctx(void *ctx) { return (struct user_ta_ctx *)ctx; }

extern TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
extern TEE_Result tee_mmu_check_access_rights(struct user_ta_ctx *ctx, uint32_t flags, uaddr_t addr, size_t len);
extern TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, uaddr_t state, struct tee_cryp_state **cs);
extern TEE_Result crypto_hash_update(void *ctx, uint32_t algo, const void *chunk, size_t chunk_size);
extern TEE_Result crypto_mac_update(void *ctx, uint32_t algo, const void *chunk, size_t chunk_size);