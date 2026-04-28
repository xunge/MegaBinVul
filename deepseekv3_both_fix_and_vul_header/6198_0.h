#include <stdint.h>

typedef uint32_t TEE_Result;
#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_PARAMETERS 0xFFFF0006
#define TEE_ERROR_BAD_STATE 0xFFFF0007

enum tee_operation_class {
    TEE_OPERATION_CIPHER,
    TEE_OPERATION_AE,
    TEE_OPERATION_DIGEST,
    TEE_OPERATION_MAC
};

#define TEE_ALG_GET_CLASS(algo) ((algo) & 0xF0000000)

struct tee_cryp_state {
    uint32_t algo;
    uint32_t mode;
    uint32_t state;
    void *ctx;
};

struct tee_ta_session;

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, void *addr, struct tee_cryp_state **cs);
void *tee_svc_uref_to_vaddr(unsigned long uref);

void crypto_cipher_copy_state(void *dst_ctx, void *src_ctx, uint32_t algo);
void crypto_authenc_copy_state(void *dst_ctx, void *src_ctx, uint32_t algo);
void crypto_hash_copy_state(void *dst_ctx, void *src_ctx, uint32_t algo);
void crypto_mac_copy_state(void *dst_ctx, void *src_ctx, uint32_t algo);