#include <stdint.h>
#include <stddef.h>

typedef uint32_t TEE_Result;
typedef uintptr_t uaddr_t;
typedef uint64_t size_t;

#define TEE_ERROR_BAD_PARAMETERS 0xFFFF0006
#define TEE_SUCCESS 0x00000000
#define TEE_ERROR_BAD_STATE 0xFFFF0007
#define TEE_ERROR_SHORT_BUFFER 0xFFFF0010

#define TEE_MEMORY_ACCESS_READ 0x1
#define TEE_MEMORY_ACCESS_WRITE 0x2
#define TEE_MEMORY_ACCESS_ANY_OWNER 0x4

#define TEE_ALG_GET_CLASS(algo) ((algo) >> 8)
#define TEE_OPERATION_DIGEST 0x1
#define TEE_OPERATION_MAC 0x2

#define CRYP_STATE_INITIALIZED 0x1

struct tee_cryp_state {
    uint32_t state;
    uint32_t algo;
    void *ctx;
};

struct user_ta_ctx;

struct tee_ta_session {
    struct user_ta_ctx *ctx;
};

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
struct user_ta_ctx *to_user_ta_ctx(void *ctx);
TEE_Result tee_mmu_check_access_rights(struct user_ta_ctx *ctx, uint32_t flags, uaddr_t addr, size_t len);
TEE_Result get_user_u64_as_size_t(size_t *dst, uint64_t *src);
TEE_Result put_user_u64(uint64_t *dst, size_t src);
TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, uaddr_t state, struct tee_cryp_state **cs);
TEE_Result tee_hash_get_digest_size(uint32_t algo, size_t *size);
TEE_Result crypto_hash_update(void *ctx, uint32_t algo, const void *chunk, size_t chunk_size);
TEE_Result crypto_hash_final(void *ctx, uint32_t algo, void *hash, size_t hash_size);
TEE_Result tee_mac_get_digest_size(uint32_t algo, size_t *size);
TEE_Result crypto_mac_update(void *ctx, uint32_t algo, const void *chunk, size_t chunk_size);
TEE_Result crypto_mac_final(void *ctx, uint32_t algo, void *hash, size_t hash_size);
uaddr_t tee_svc_uref_to_vaddr(unsigned long uref);