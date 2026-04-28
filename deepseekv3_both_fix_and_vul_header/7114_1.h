#include <stdlib.h>

typedef struct pkcs7_st PKCS7;
typedef struct pkcs7_recip_info_st PKCS7_RECIP_INFO;
typedef struct stack_st_PKCS7_RECIP_INFO STACK_OF_PKCS7_RECIP_INFO;
#define STACK_OF(type) struct stack_st_##type
#define DECLARE_STACK_OF(type) STACK_OF(type);

struct pkcs7_st {
    union {
        void *ptr;
        struct pkcs7_signed_st *signed_and_enveloped;
        struct pkcs7_enveloped_st *enveloped;
    } d;
};

struct pkcs7_signed_st {
    STACK_OF_PKCS7_RECIP_INFO *recipientinfo;
};

struct pkcs7_enveloped_st {
    STACK_OF_PKCS7_RECIP_INFO *recipientinfo;
};

int PKCS7_type_is_signedAndEnveloped(const PKCS7 *p7);
int PKCS7_type_is_enveloped(const PKCS7 *p7);