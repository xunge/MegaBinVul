#include <stddef.h>
#include <stdint.h>

typedef uint32_t TEE_Result;
typedef unsigned long uaddr_t;
typedef unsigned long size_t;

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_STATE 0xFFFF0000
#define TEE_ERROR_BAD_PARAMETERS 0xFFFF0006
#define TEE_MEMORY_ACCESS_READ 0x00000001
#define TEE_MEMORY_ACCESS_ANY_OWNER 0x00000002
#define TEE_HANDLE_FLAG_INITIALIZED 0x00000001
#define TEE_OPERATION_CIPHER 0x00000001

enum cryp_state {
    CRYP_STATE_INITIALIZED
};

struct tee_cryp_state {
    uint32_t algo;
    uint32_t mode;
    void *ctx;
    void *key1;
    void *key2;
    void (*ctx_finalize)(void);
    enum cryp_state state;
};

struct tee_ta_session {
    void *ctx;
};

struct tee_obj {
    struct {
        uint32_t handleFlags;
    } info;
    void *attr;
};

struct tee_cryp_obj_secret {
    size_t key_size;
};

struct user_ta_ctx;

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
struct user_ta_ctx *to_user_ta_ctx(void *ctx);
TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, uaddr_t state, struct tee_cryp_state **cs);
uint32_t TEE_ALG_GET_CLASS(uint32_t algo);
TEE_Result tee_mmu_check_access_rights(struct user_ta_ctx *utc, uint32_t flags, uaddr_t addr, size_t len);
TEE_Result tee_obj_get(struct user_ta_ctx *utc, void *key, struct tee_obj **obj);
TEE_Result crypto_cipher_init(void *ctx, uint32_t algo, uint32_t mode, uint8_t *key1, size_t key1_size, uint8_t *key2, size_t key2_size, const void *iv, size_t iv_len);
void crypto_cipher_final(void);