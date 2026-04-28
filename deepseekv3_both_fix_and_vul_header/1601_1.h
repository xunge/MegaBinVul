#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_PARAMETERS 1
#define TEE_ERROR_OUT_OF_MEMORY 2
#define TEE_ERROR_NOT_SUPPORTED 3

#define TEE_MALLOC_FILL_ZERO 0
#define TEE_ALG_AES_XTS 0
#define TEE_OPERATION_CIPHER 0
#define TEE_OPERATION_AE 1
#define TEE_OPERATION_MAC 2
#define TEE_OPERATION_DIGEST 3
#define TEE_OPERATION_ASYMMETRIC_CIPHER 4
#define TEE_OPERATION_ASYMMETRIC_SIGNATURE 5
#define TEE_OPERATION_KEY_DERIVATION 6

typedef uint32_t TEE_Result;
typedef unsigned long vaddr_t;

struct tee_cryp_state {
    unsigned long algo;
    unsigned long mode;
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

struct user_ta_ctx {
    struct {
        struct tee_cryp_state *tqh_first;
        struct tee_cryp_state **tqh_last;
    } cryp_states;
};

struct tee_ta_session {
    struct user_ta_ctx *ctx;
};

#define TAILQ_INSERT_TAIL(head, elm, field) do { \
    (elm)->field.tqe_next = NULL; \
    (elm)->field.tqe_prev = (head)->tqh_last; \
    *(head)->tqh_last = (elm); \
    (head)->tqh_last = &(elm)->field.tqe_next; \
} while (0)

#define TEE_ALG_GET_CLASS(algo) ((algo) >> 8)

static inline TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess) {
    return TEE_SUCCESS;
}

static inline struct user_ta_ctx *to_user_ta_ctx(void *ctx) {
    return (struct user_ta_ctx *)ctx;
}

static inline TEE_Result tee_obj_get(struct user_ta_ctx *utc, vaddr_t key, struct tee_obj **obj) {
    return TEE_SUCCESS;
}

static inline TEE_Result tee_svc_cryp_check_key_type(struct tee_obj *obj, unsigned long algo, unsigned long mode) {
    return TEE_SUCCESS;
}

static inline void *TEE_Malloc(size_t size, uint32_t flags) {
    return calloc(1, size);
}

static inline TEE_Result crypto_cipher_alloc_ctx(void **ctx, unsigned long algo) {
    return TEE_SUCCESS;
}

static inline TEE_Result crypto_mac_alloc_ctx(void **ctx, unsigned long algo) {
    return TEE_SUCCESS;
}

static inline TEE_Result crypto_hash_alloc_ctx(void **ctx, unsigned long algo) {
    return TEE_SUCCESS;
}

static inline TEE_Result tee_svc_copy_kaddr_to_uref(uint32_t *state, struct tee_cryp_state *cs) {
    return TEE_SUCCESS;
}

static inline vaddr_t tee_svc_uref_to_vaddr(unsigned long uref) {
    return (vaddr_t)uref;
}

static inline void cryp_state_free(struct user_ta_ctx *utc, struct tee_cryp_state *cs) {
    free(cs);
}