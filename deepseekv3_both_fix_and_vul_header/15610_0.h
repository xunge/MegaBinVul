#include <stddef.h>
#include <stdlib.h>

typedef struct pkcs7_st PKCS7;
typedef struct pkcs12_st PKCS12;
typedef struct stack_st_PKCS7 {
    PKCS7 **data;
    int num;
    int sorted;
} STACK_OF_PKCS7;

#define ERR_LIB_PKCS12 0
#define PKCS12_R_CONTENT_TYPE_NOT_DATA 0
#define PKCS12_R_DECODE_ERROR 0
#define PKCS12_AUTHSAFES "PKCS12_AUTHSAFES"

struct pkcs7_st {
    int type;
    union {
        unsigned char *data;
    } d;
};

struct pkcs12_st {
    PKCS7 *authsafes;
};

int PKCS7_type_is_data(const PKCS7 *p7);
STACK_OF_PKCS7 *ASN1_item_unpack(const unsigned char *data, void *it);
void *ASN1_ITEM_rptr(const char *name);
int sk_PKCS7_num(const STACK_OF_PKCS7 *sk);
PKCS7 *sk_PKCS7_value(const STACK_OF_PKCS7 *sk, int idx);
void sk_PKCS7_free(STACK_OF_PKCS7 *sk);
int ossl_pkcs7_ctx_propagate(PKCS7 *src, PKCS7 *dest);
void ERR_raise(int lib, int reason);

typedef STACK_OF_PKCS7 *STACK_OF_PKCS7_PTR;
#define STACK_OF(type) struct stack_st_##type
#define sk_PKCS7_num(sk) ((sk) ? (sk)->num : 0)
#define sk_PKCS7_value(sk, i) ((sk) ? (sk)->data[i] : NULL)
#define sk_PKCS7_free(sk) do { if (sk) free((sk)->data); free(sk); } while(0)