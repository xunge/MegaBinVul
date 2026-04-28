#include <stdlib.h>

typedef struct PKCS7_st PKCS7;
typedef struct PKCS12_st PKCS12;
typedef struct pkcs7_ctx_st {
    void *libctx;
    char *propq;
} PKCS7_CTX;

struct stack_st_PKCS7 {
    PKCS7 **data;
    int num;
};
typedef struct stack_st_PKCS7 STACK_OF_PKCS7;

struct PKCS7_data_st {
    void *data;
};

struct PKCS12_authsafes_st {
    struct PKCS7_data_st d;
    PKCS7_CTX ctx;
};

struct PKCS12_st {
    struct PKCS12_authsafes_st *authsafes;
};

#define ERR_LIB_PKCS12 0
#define PKCS12_R_CONTENT_TYPE_NOT_DATA 0
#define PKCS12_R_DECODE_ERROR 0
#define PKCS12_AUTHSAFES NULL

int PKCS7_type_is_data(const void *);
void ERR_raise(int, int);
STACK_OF_PKCS7 *ASN1_item_unpack_ex(const void *, const void *, void *, void *);
const void *ASN1_ITEM_rptr(const void *);
void *ossl_pkcs7_ctx_get0_libctx(PKCS7_CTX *);
void *ossl_pkcs7_ctx_get0_propq(PKCS7_CTX *);
int sk_PKCS7_num(const STACK_OF_PKCS7 *);
PKCS7 *sk_PKCS7_value(const STACK_OF_PKCS7 *, int);
int ossl_pkcs7_ctx_propagate(void *, PKCS7 *);
void sk_PKCS7_free(STACK_OF_PKCS7 *);

#define STACK_OF(type) STACK_OF_##type