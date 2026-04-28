#include <stdlib.h>
#include <stddef.h>

typedef struct PKCS12_st {
    struct {
        struct {
            void *data;
        } d;
    } *authsafes;
} PKCS12;

typedef struct pkcs7_st PKCS7;
typedef struct stack_st_PKCS7 STACK_OF_PKCS7;

#define STACK_OF(type) struct stack_st_##type
#define STACK_OF_PKCS7 STACK_OF(PKCS7)

typedef int ERR_LIB;
#define ERR_LIB_PKCS12 0
#define PKCS12_R_CONTENT_TYPE_NOT_DATA 0
#define PKCS12_R_DECODE_ERROR 0
#define PKCS12_AUTHSAFES 0

int PKCS7_type_is_data(void *);
void ERR_raise(ERR_LIB, int);
void *ASN1_item_unpack(void *, void *);
void *ASN1_ITEM_rptr(void *);
int sk_PKCS7_num(STACK_OF_PKCS7 *);
PKCS7 *sk_PKCS7_value(STACK_OF_PKCS7 *, int);
int ossl_pkcs7_ctx_propagate(void *, PKCS7 *);
void sk_PKCS7_free(STACK_OF_PKCS7 *);