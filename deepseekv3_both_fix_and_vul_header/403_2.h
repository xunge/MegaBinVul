#include <stddef.h>
#include <stdlib.h>

typedef unsigned int TEE_Result;

#define TEE_SUCCESS 0
#define TEE_ERROR_BAD_STATE 0xFFFF0006
#define TEE_ERROR_NOT_SUPPORTED 0xFFFF0004
#define TEE_ERROR_OVERFLOW 0xFFFF300F
#define TEE_ERROR_OUT_OF_MEMORY 0xFFFF000C
#define TEE_ERROR_EXCESS_DATA 0xFFFF000F
#define TEE_ERROR_BAD_FORMAT 0xFFFF0007

#define TEE_HANDLE_FLAG_PERSISTENT (1 << 0)
#define TEE_HANDLE_FLAG_INITIALIZED (1 << 1)

#define TEE_TYPE_AES 0xA0000010
#define TEE_TYPE_DES 0xA0000011
#define TEE_TYPE_DES3 0xA0000013
#define TEE_TYPE_HMAC_MD5 0xA0000001
#define TEE_TYPE_HMAC_SHA1 0xA0000002
#define TEE_TYPE_HMAC_SHA224 0xA0000003
#define TEE_TYPE_HMAC_SHA256 0xA0000004
#define TEE_TYPE_HMAC_SHA384 0xA0000005
#define TEE_TYPE_HMAC_SHA512 0xA0000006
#define TEE_TYPE_GENERIC_SECRET 0xA0000000
#define TEE_TYPE_RSA_KEYPAIR 0xA1000030
#define TEE_TYPE_DSA_KEYPAIR 0xA1000031
#define TEE_TYPE_DH_KEYPAIR 0xA1000032
#define TEE_TYPE_ECDSA_KEYPAIR 0xA1000041
#define TEE_TYPE_ECDH_KEYPAIR 0xA1000042

#define ATTR_USAGE_GENERATE_KEY 0xC0000000

struct tee_ta_session {
    void *ctx;
};

struct tee_obj {
    struct {
        unsigned int handleFlags;
        unsigned int objectType;
        unsigned int keySize;
    } info;
    unsigned int have_attrs;
    void *attr;
};

struct tee_cryp_obj_secret {
    size_t alloc_size;
    size_t key_size;
};

struct tee_cryp_obj_type_props {
    unsigned int quanta;
    unsigned int min_size;
    unsigned int max_size;
    unsigned int num_type_attrs;
};

struct utee_attribute;

struct TEE_Attribute {
    unsigned int attributeID;
    void *content;
    size_t contentLength;
};

typedef struct TEE_Attribute TEE_Attribute;

static inline int MUL_OVERFLOW(size_t a, size_t b, size_t *res) {
    *res = a * b;
    return a && (*res / a != b);
}

TEE_Result tee_ta_get_current_session(struct tee_ta_session **sess);
TEE_Result tee_obj_get(void *ctx, unsigned long vaddr, struct tee_obj **obj);
TEE_Result copy_in_attrs(void *ctx, const struct utee_attribute *usr_params,
                        unsigned long param_count, struct TEE_Attribute *params);
TEE_Result tee_svc_cryp_check_attr(unsigned int usage,
                                  const struct tee_cryp_obj_type_props *props,
                                  const struct TEE_Attribute *attrs,
                                  unsigned long attr_count);
TEE_Result crypto_rng_read(void *buf, size_t blen);
TEE_Result tee_svc_obj_generate_key_rsa(struct tee_obj *o,
                                       const struct tee_cryp_obj_type_props *props,
                                       unsigned long key_size,
                                       const struct TEE_Attribute *params,
                                       unsigned long param_count);
TEE_Result tee_svc_obj_generate_key_dsa(struct tee_obj *o,
                                      const struct tee_cryp_obj_type_props *props,
                                      unsigned long key_size);
TEE_Result tee_svc_obj_generate_key_dh(struct tee_obj *o,
                                     const struct tee_cryp_obj_type_props *props,
                                     unsigned long key_size,
                                     const struct TEE_Attribute *params,
                                     unsigned long param_count);
TEE_Result tee_svc_obj_generate_key_ecc(struct tee_obj *o,
                                      const struct tee_cryp_obj_type_props *props,
                                      unsigned long key_size,
                                      const struct TEE_Attribute *params,
                                      unsigned long param_count);
const struct tee_cryp_obj_type_props *tee_svc_find_type_props(unsigned int type);
void *to_user_ta_ctx(void *ctx);
unsigned long tee_svc_uref_to_vaddr(unsigned long uref);