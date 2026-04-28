#include <stddef.h>

typedef struct bio_st BIO;
typedef struct pkcs7_ctx_st PKCS7_CTX;
typedef struct pkcs7_st {
    void *type;
    union {
        struct {
            void *md_algs;
        } *sign;
    } d;
} PKCS7;
typedef struct X509_algor_st X509_ALGOR;
typedef struct asn1_value_st ASN1_VALUE;
typedef struct stack_st {
    X509_ALGOR **data;
    int num;
} STACK_OF_X509_ALGOR;
#define STACK_OF(X509_ALGOR) STACK_OF_X509_ALGOR

#define SMIME_OLDMIME 0x400
#define NID_pkcs7_signed 22
#define NID_undef 0

int OBJ_obj2nid(const void *obj);
const PKCS7_CTX *ossl_pkcs7_get0_ctx(const PKCS7 *p7);
void *ossl_pkcs7_ctx_get0_libctx(const PKCS7_CTX *ctx);
const char *ossl_pkcs7_ctx_get0_propq(const PKCS7_CTX *ctx);
const void *ASN1_ITEM_rptr(const void *);
int SMIME_write_ASN1_ex(BIO *bio, ASN1_VALUE *val, BIO *data, int flags,
                       int ctype_nid, int econt_nid, STACK_OF_X509_ALGOR *mdalgs,
                       const void *it, void *libctx, const char *propq);

#define ASN1_ITEM_rptr(type) ((const void*)&type##_it)
extern const void PKCS7_it;