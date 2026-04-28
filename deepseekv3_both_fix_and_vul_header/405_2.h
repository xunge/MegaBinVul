#include <stdint.h>
#include <stdlib.h>

typedef uint32_t TEE_Result;
typedef uint64_t uaddr_t;

#define TEE_SUCCESS 0
#define TEE_ERROR_OVERFLOW 1
#define TEE_ERROR_OUT_OF_MEMORY 2
#define TEE_ERROR_GENERIC 3
#define TEE_ERROR_BAD_PARAMETERS 4
#define TEE_ERROR_SHORT_BUFFER 5

#define TEE_MEMORY_ACCESS_READ 0x1
#define TEE_MEMORY_ACCESS_WRITE 0x2
#define TEE_MEMORY_ACCESS_ANY_OWNER 0x4

#define TEE_HANDLE_FLAG_INITIALIZED 0x1

#define TEE_MODE_ENCRYPT 0
#define TEE_MODE_DECRYPT 1
#define TEE_MODE_SIGN 2

#define TEE_ATTR_RSA_OAEP_LABEL 0x1

#define CFG_CRYPTO_RSASSA_NA1 1

#define MUL_OVERFLOW(a, b, res) __builtin_mul_overflow(a, b, res)

enum {
    TEE_ALG_RSA_NOPAD,
    TEE_ALG_RSAES_PKCS1_V1_5,
    TEE_ALG_RSAES_PKCS1_OAEP_MGF1_SHA1,
    TEE_ALG_RSAES_PKCS1_OAEP_MGF1_SHA224,
    TEE_ALG_RSAES_PKCS1_OAEP_MGF1_SHA256,
    TEE_ALG_RSAES_PKCS1_OAEP_MGF1_SHA384,
    TEE_ALG_RSAES_PKCS1_OAEP_MGF1_SHA512,
    TEE_ALG_RSASSA_PKCS1_V1_5,
    TEE_ALG_RSASSA_PKCS1_V1_5_MD5,
    TEE_ALG_RSASSA_PKCS1_V1_5_SHA1,
    TEE_ALG_RSASSA_PKCS1_V1_5_SHA224,
    TEE_ALG_RSASSA_PKCS1_V1_5_SHA256,
    TEE_ALG_RSASSA_PKCS1_V1_5_SHA384,
    TEE_ALG_RSASSA_PKCS1_V1_5_SHA512,
    TEE_ALG_RSASSA_PKCS1_PSS_MGF1_SHA1,
    TEE_ALG_RSASSA_PKCS1_PSS_MGF1_SHA224,
    TEE_ALG_RSASSA_PKCS1_PSS_MGF1_SHA256,
    TEE_ALG_RSASSA_PKCS1_PSS_MGF1_SHA384,
    TEE_ALG_RSASSA_PKCS1_PSS_MGF1_SHA512,
    TEE_ALG_DSA_SHA1,
    TEE_ALG_DSA_SHA224,
    TEE_ALG_DSA_SHA256,
    TEE_ALG_ECDSA_P192,
    TEE_ALG_ECDSA_P224,
    TEE_ALG_ECDSA_P256,
    TEE_ALG_ECDSA_P384,
    TEE_ALG_ECDSA_P521
};

struct utee_attribute {
    uint32_t attributeID;
    union {
        struct {
            void *buffer;
            size_t length;
        } ref;
    } content;
};

struct tee_cryp_state {
    uint32_t algo;
    uint32_t mode;
    uint32_t key1;
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

struct user_ta_ctx {
};

struct TEE_Attribute {
    uint32_t attributeID;
    union {
        struct {
            void *buffer;
            size_t length;
        } ref;
    } content;
};

typedef struct TEE_Attribute TEE_Attribute;

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, uaddr_t state, struct tee_cryp_state **cs);
TEE_Result tee_mmu_check_access_rights(struct user_ta_ctx *utc, uint32_t flags, uaddr_t addr, size_t len);
TEE_Result tee_svc_copy_from_user(void *dst, const void *src, size_t len);
TEE_Result tee_svc_copy_to_user(void *dst, const void *src, size_t len);
TEE_Result copy_in_attrs(struct user_ta_ctx *utc, const struct utee_attribute *usr_params, size_t num_params, TEE_Attribute *params);
TEE_Result tee_obj_get(struct user_ta_ctx *utc, uint32_t key, struct tee_obj **o);
TEE_Result crypto_acipher_rsanopad_encrypt(void *attr, const void *src, size_t src_len, void *dst, size_t *dst_len);
TEE_Result crypto_acipher_rsanopad_decrypt(void *attr, const void *src, size_t src_len, void *dst, size_t *dst_len);
TEE_Result crypto_acipher_rsaes_encrypt(uint32_t algo, void *attr, void *label, size_t label_len, const void *src, size_t src_len, void *dst, size_t *dst_len);
TEE_Result crypto_acipher_rsaes_decrypt(uint32_t algo, void *attr, void *label, size_t label_len, const void *src, size_t src_len, void *dst, size_t *dst_len);
TEE_Result crypto_acipher_rsassa_sign(uint32_t algo, void *attr, int salt_len, const void *src, size_t src_len, void *dst, size_t *dst_len);
TEE_Result crypto_acipher_dsa_sign(uint32_t algo, void *attr, const void *src, size_t src_len, void *dst, size_t *dst_len);
TEE_Result crypto_acipher_ecc_sign(uint32_t algo, void *attr, const void *src, size_t src_len, void *dst, size_t *dst_len);
int pkcs1_get_salt_len(const TEE_Attribute *params, size_t num_params, size_t hash_len);
struct user_ta_ctx *to_user_ta_ctx(void *ctx);
uaddr_t tee_svc_uref_to_vaddr(unsigned long uref);