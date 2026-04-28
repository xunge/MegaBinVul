#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define TEE_ERROR_NOT_SUPPORTED 0xFFFF0000
#define TEE_SUCCESS 0x00000000
#define TEE_ERROR_OVERFLOW 0xFFFF000F
#define TEE_ERROR_OUT_OF_MEMORY 0xFFFF000C
#define TEE_ERROR_BAD_PARAMETERS 0xFFFF0006
#define TEE_ERROR_NOT_IMPLEMENTED 0xFFFF0009
#define TEE_ALG_DH_DERIVE_SHARED_SECRET 0x80000000
#define TEE_MAIN_ALGO_ECDH 0x80000001
#define TEE_MAIN_ALGO_HKDF 0x80000002
#define TEE_MAIN_ALGO_CONCAT_KDF 0x80000003
#define TEE_MAIN_ALGO_PBKDF2 0x80000004
#define TEE_ALG_ECDH_P192 0x80000005
#define TEE_ALG_ECDH_P224 0x80000006
#define TEE_ALG_ECDH_P256 0x80000007
#define TEE_ALG_ECDH_P384 0x80000008
#define TEE_ALG_ECDH_P521 0x80000009
#define TEE_ATTR_DH_PUBLIC_VALUE 0x8000000A
#define TEE_ATTR_ECC_PUBLIC_VALUE_X 0x8000000B
#define TEE_ATTR_ECC_PUBLIC_VALUE_Y 0x8000000C
#define TEE_ATTR_SECRET_VALUE 0x8000000D
#define TEE_HANDLE_FLAG_INITIALIZED 0x8000000E
#define CFG_CRYPTO_HKDF 1
#define CFG_CRYPTO_CONCAT_KDF 1
#define CFG_CRYPTO_PBKDF2 1

typedef uint32_t TEE_Result;

struct utee_attribute {
    uint32_t attributeID;
    union {
        struct {
            void *buffer;
            size_t length;
        } ref;
        uint32_t value;
    } content;
};

struct tee_ta_session {
    void *ctx;
};

struct tee_obj {
    union {
        struct {
            uint32_t objectType;
            uint32_t handleFlags;
        } info;
    };
    void *attr;
};

struct tee_cryp_state {
    uint32_t algo;
    unsigned long key1;
};

struct tee_cryp_obj_secret {
    size_t key_size;
    size_t alloc_size;
};

struct tee_cryp_obj_type_props;
struct user_ta_ctx;
struct bignum;

struct ecc_public_key {
    struct bignum *x;
    struct bignum *y;
    uint32_t curve;
};

struct ecc_keypair {
    uint32_t curve;
};

typedef struct {
    uint32_t attributeID;
    union {
        struct {
            void *buffer;
            size_t length;
        } ref;
        uint32_t value;
    } content;
} TEE_Attribute;

static inline bool MUL_OVERFLOW(size_t a, size_t b, size_t *res) {
    *res = a * b;
    return a != 0 && *res / a != b;
}

static inline uint32_t TEE_ALG_GET_MAIN_ALG(uint32_t algo) {
    return algo & 0xFF;
}

static inline uint32_t TEE_ALG_GET_DIGEST_HASH(uint32_t algo) {
    return (algo >> 8) & 0xFF;
}

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
struct user_ta_ctx *to_user_ta_ctx(void *ctx);
void *tee_svc_uref_to_vaddr(unsigned long uref);
TEE_Result tee_svc_cryp_get_state(struct tee_ta_session *sess, void *state, struct tee_cryp_state **cs);
TEE_Result tee_obj_get(struct user_ta_ctx *utc, unsigned long key, struct tee_obj **obj);
const struct tee_cryp_obj_type_props *tee_svc_find_type_props(uint32_t objectType);
TEE_Result copy_in_attrs(struct user_ta_ctx *utc, const struct utee_attribute *usr_params, unsigned long param_count, TEE_Attribute *params);
void set_attribute(struct tee_obj *obj, const struct tee_cryp_obj_type_props *type_props, uint32_t attributeID);
struct bignum *crypto_bignum_allocate(size_t size_bits);
void crypto_bignum_free(struct bignum *bn);
TEE_Result crypto_bignum_bin2bn(const uint8_t *buf, size_t len, struct bignum *bn);
size_t crypto_bignum_num_bytes(struct bignum *bn);
void crypto_bignum_bn2bin(struct bignum *bn, uint8_t *buf);
TEE_Result crypto_acipher_dh_shared_secret(void *key, struct bignum *pub, struct bignum *ss);
TEE_Result crypto_acipher_alloc_ecc_public_key(struct ecc_public_key *key, size_t key_size);
void crypto_acipher_free_ecc_public_key(struct ecc_public_key *key);
TEE_Result crypto_acipher_ecc_shared_secret(void *key, struct ecc_public_key *public_key, uint8_t *secret, unsigned long *secret_len);
TEE_Result tee_cryp_hkdf(uint32_t hash_id, const uint8_t *ikm, size_t ikm_len, void *salt, size_t salt_len, void *info, size_t info_len, uint8_t *okm, size_t okm_len);
TEE_Result tee_cryp_concat_kdf(uint32_t hash_id, const uint8_t *shared_secret, size_t shared_secret_len, void *info, size_t info_len, uint8_t *derived_key, size_t derived_key_len);
TEE_Result tee_cryp_pbkdf2(uint32_t hash_id, const uint8_t *password, size_t password_len, void *salt, size_t salt_len, size_t iteration_count, uint8_t *derived_key, size_t derived_key_len);
TEE_Result get_hkdf_params(TEE_Attribute *params, unsigned long param_count, void **salt, size_t *salt_len, void **info, size_t *info_len, size_t *okm_len);
TEE_Result get_concat_kdf_params(TEE_Attribute *params, unsigned long param_count, void **info, size_t *info_len, size_t *derived_key_len);
TEE_Result get_pbkdf2_params(TEE_Attribute *params, unsigned long param_count, void **salt, size_t *salt_len, size_t *derived_key_len, size_t *iteration_count);