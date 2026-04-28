#include <stddef.h>

typedef struct stack_st STACK;
typedef struct pkcs7_signer_info_st PKCS7_SIGNER_INFO;

typedef struct pkcs7_st {
    int type;
    union {
        struct pkcs7_signed_st *sign;
        struct pkcs7_signedandenveloped_st *signed_and_enveloped;
        void *ptr;
    } d;
} PKCS7;

typedef struct pkcs7_signed_st {
    STACK *signer_info;
} PKCS7_SIGNED;

typedef struct pkcs7_signedandenveloped_st {
    STACK *signer_info;
} PKCS7_SIGNED_AND_ENVELOPED;

#define STACK_OF(type) struct stack_st_##type
#define PKCS7_type_is_signed(p7) ((p7)->type == 1)
#define PKCS7_type_is_signedAndEnveloped(p7) ((p7)->type == 2)