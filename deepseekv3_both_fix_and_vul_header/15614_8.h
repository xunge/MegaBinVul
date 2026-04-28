#include <stddef.h>

typedef struct bio_st BIO;
typedef struct asn1_object_st ASN1_OBJECT;
typedef struct asn1_value_st ASN1_VALUE;
typedef struct pkcs7_ctx_st PKCS7_CTX;
typedef struct x509_algor_st X509_ALGOR;
typedef struct stack_st {
    X509_ALGOR **data;
    int num;
} STACK_OF_X509_ALGOR;
typedef struct asn1_item_st ASN1_ITEM;
typedef struct ossl_lib_ctx_st OSSL_LIB_CTX;
typedef struct pkcs7_signed_st {
    STACK_OF_X509_ALGOR *md_algs;
} PKCS7_SIGNED;
typedef struct pkcs7_st {
    ASN1_OBJECT *type;
    union {
        PKCS7_SIGNED *sign;
    } d;
} PKCS7;

#define SMIME_OLDMIME 0x400
#define NID_pkcs7_signed 20
#define NID_undef 0

int OBJ_obj2nid(const ASN1_OBJECT *o);
const PKCS7_CTX *ossl_pkcs7_get0_ctx(const PKCS7 *p7);
void *ossl_pkcs7_ctx_get0_libctx(const PKCS7_CTX *ctx);
const char *ossl_pkcs7_ctx_get0_propq(const PKCS7_CTX *ctx);
int SMIME_write_ASN1_ex(BIO *bio, ASN1_VALUE *val, BIO *data, int flags,
                        int ctype_nid, int econt_nid,
                        STACK_OF_X509_ALGOR *mdalgs,
                        const ASN1_ITEM *it,
                        OSSL_LIB_CTX *libctx, const char *propq);
const ASN1_ITEM *ASN1_ITEM_rptr_pkcs7(void);

#define STACK_OF(type) struct stack_st
typedef STACK_OF_X509_ALGOR *STACK_OF_X509_ALGOR_PTR;
#define ASN1_ITEM_rptr(type) ASN1_ITEM_rptr_##type()