#include <stddef.h>

typedef struct X509_st X509;
typedef struct stack_st STACK;

#define STACK_OF(type) struct stack_st_##type
typedef STACK_OF(X509) STACK_OF_X509;

typedef struct pkcs7_st PKCS7;

struct pkcs7_st {
    int type;
    union {
        char *ptr;
        struct pkcs7_signed_st *sign;
        struct pkcs7_signedandenveloped_st *signed_and_enveloped;
    } d;
};

struct pkcs7_signed_st {
    STACK_OF(X509) *cert;
};

struct pkcs7_signedandenveloped_st {
    STACK_OF(X509) *cert;
};

int PKCS7_type_is_signed(const PKCS7 *p7);
int PKCS7_type_is_signedAndEnveloped(const PKCS7 *p7);