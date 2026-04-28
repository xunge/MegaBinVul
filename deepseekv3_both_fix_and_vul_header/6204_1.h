#include <stddef.h>
#include <stdint.h>

typedef uint32_t TEE_Result;

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_PARAMETERS 1

#define __maybe_unused __attribute__((unused))

enum tee_operation_class {
    TEE_OPERATION_DIGEST,
    TEE_OPERATION_MAC
};

#define TEE_ALG_GET_CLASS(algo) ((algo) & 0xF)

enum cryp_state {
    CRYP_STATE_INITIALIZED
};

struct tee_ta_session {
    void *ctx;
};

struct user_ta_ctx;

struct tee_cryp_state {
    uint32_t algo;
    void *ctx;
    uint32_t key1;
    enum cryp_state state;
};

struct tee_obj_info {
    uint32_t handleFlags;
};

struct tee_obj {
    struct tee_obj_info info;
    void *attr;
};

struct tee_cryp_obj_secret {
    size_t key_size;
};

struct user_ta_ctx *to_user_ta_ctx(void *ctx);

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, void *vaddr, struct tee_cryp_state **cs);
TEE_Result tee_obj_get(struct user_ta_ctx *ctx, uint32_t key, struct tee_obj **o);
TEE_Result crypto_hash_init(void *ctx, uint32_t algo);
TEE_Result crypto_mac_init(void *ctx, uint32_t algo, void *key, size_t key_size);
void *tee_svc_uref_to_vaddr(unsigned long uref);

#define TEE_HANDLE_FLAG_INITIALIZED (1 << 0)