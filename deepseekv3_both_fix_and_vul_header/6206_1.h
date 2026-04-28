#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef uint32_t TEE_Result;
typedef unsigned long vaddr_t;

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_PARAMETERS 1
#define TEE_ERROR_OUT_OF_MEMORY 2
#define TEE_ERROR_NOT_SUPPORTED 3

#define TEE_ALG_GET_CLASS(algo) ((algo) & 0xF0000000)
#define TEE_OPERATION_EXTENSION 0x10000000
#define TEE_OPERATION_CIPHER 0x20000000
#define TEE_OPERATION_AE 0x30000000
#define TEE_OPERATION_MAC 0x40000000
#define TEE_OPERATION_DIGEST 0x50000000
#define TEE_OPERATION_ASYMMETRIC_CIPHER 0x60000000
#define TEE_OPERATION_ASYMMETRIC_SIGNATURE 0x70000000
#define TEE_OPERATION_KEY_DERIVATION 0x80000000

#define TEE_ALG_AES_XTS 0x20000010
#define TEE_ALG_RSASSA_PKCS1_V1_5 0x70000030

#define CRYP_STATE_UNINITIALIZED 0

#define __maybe_unused __attribute__((unused))

struct tee_cryp_state {
    unsigned long algo;
    unsigned long mode;
    unsigned long state;
    void *ctx;
    vaddr_t key1;
    vaddr_t key2;
    struct {
        struct tee_cryp_state *tqe_next;
        struct tee_cryp_state **tqe_prev;
    } link;
};

struct tee_obj {
    bool busy;
};

struct tee_ta_session {
    void *ctx;
};

struct user_ta_ctx {
    struct {
        struct tee_cryp_state *tqh_first;
        struct tee_cryp_state **tqh_last;
    } cryp_states;
};

#define TAILQ_INSERT_TAIL(head, elm, field) do { \
    (elm)->field.tqe_next = NULL; \
    (elm)->field.tqe_prev = (head)->tqh_last; \
    *(head)->tqh_last = (elm); \
    (head)->tqh_last = &(elm)->field.tqe_next; \
} while (0)

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
struct user_ta_ctx *to_user_ta_ctx(void *ctx);
TEE_Result tee_obj_get(struct user_ta_ctx *utc, vaddr_t key, struct tee_obj **obj);
TEE_Result tee_svc_cryp_check_key_type(struct tee_obj *obj, unsigned long algo, unsigned long mode);
vaddr_t tee_svc_uref_to_vaddr(unsigned long uref);
TEE_Result tee_svc_copy_kaddr_to_uref(uint32_t *state, struct tee_cryp_state *cs);
void cryp_state_free(struct user_ta_ctx *utc, struct tee_cryp_state *cs);
TEE_Result crypto_cipher_alloc_ctx(void **ctx, unsigned long algo);
TEE_Result crypto_authenc_alloc_ctx(void **ctx, unsigned long algo);
TEE_Result crypto_mac_alloc_ctx(void **ctx, unsigned long algo);
TEE_Result crypto_hash_alloc_ctx(void **ctx, unsigned long algo);