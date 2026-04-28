#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t TEE_Result;
typedef uintptr_t uaddr_t;

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_PARAMETERS 1
#define TEE_ERROR_OUT_OF_MEMORY 2
#define TEE_ERROR_OVERFLOW 3
#define TEE_ERROR_NOT_SUPPORTED 4

#define TEE_MEMORY_ACCESS_READ 0x1
#define TEE_MEMORY_ACCESS_ANY_OWNER 0x2

#define TEE_MODE_VERIFY 1
#define TEE_HANDLE_FLAG_INITIALIZED 0x1

#define TEE_ALG_RSASSA_PKCS1_V1_5 0x70004830
#define TEE_MAIN_ALGO_RSA 0x10
#define TEE_MAIN_ALGO_DSA 0x20
#define TEE_MAIN_ALGO_ECDSA 0x30

#define TEE_ALG_GET_MAIN_ALG(algo) ((algo) & 0xFF)
#define TEE_DIGEST_HASH_TO_ALGO(algo) ((algo) >> 8)

#define MUL_OVERFLOW(a, b, res) __builtin_mul_overflow(a, b, res)

struct utee_attribute {
    uint32_t attribute_id;
    union {
        struct {
            const void *a;
            size_t b;
        } memref;
        uint32_t value;
    } content;
};

struct TEE_Attribute {
    uint32_t attribute_id;
    union {
        struct {
            void *a;
            size_t b;
        } memref;
        uint32_t value;
    } content;
};
typedef struct TEE_Attribute TEE_Attribute;

struct tee_obj {
    struct {
        uint32_t handleFlags;
    } info;
    void *attr;
};

struct tee_cryp_state {
    uint32_t mode;
    uint32_t algo;
    uint32_t key1;
};

struct tee_ta_session {
    void *ctx;
};

struct user_ta_ctx {
    // Context fields
};

extern TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
extern struct user_ta_ctx *to_user_ta_ctx(void *ctx);
extern uaddr_t tee_svc_uref_to_vaddr(unsigned long uref);
extern TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, uaddr_t state, struct tee_cryp_state **cs);
extern TEE_Result tee_mmu_check_access_rights(struct user_ta_ctx *utc, uint32_t flags, uaddr_t addr, size_t len);
extern TEE_Result copy_in_attrs(struct user_ta_ctx *utc, const struct utee_attribute *usr_params, size_t num_params, TEE_Attribute *params);
extern TEE_Result tee_obj_get(struct user_ta_ctx *utc, uint32_t key, struct tee_obj **o);
extern TEE_Result tee_hash_get_digest_size(uint32_t algo, size_t *size);
extern int pkcs1_get_salt_len(TEE_Attribute *params, size_t num_params, size_t hash_size);
extern TEE_Result crypto_acipher_rsassa_verify(uint32_t algo, void *attr, int salt_len, const void *data, size_t data_len, const void *sig, size_t sig_len);
extern TEE_Result crypto_acipher_dsa_verify(uint32_t algo, void *attr, const void *data, size_t data_len, const void *sig, size_t sig_len);
extern TEE_Result crypto_acipher_ecc_verify(uint32_t algo, void *attr, const void *data, size_t data_len, const void *sig, size_t sig_len);