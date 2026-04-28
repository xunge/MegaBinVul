#include <stddef.h>

typedef struct stack_st {
    void **data;
    int num;
} STACK;

typedef struct pkcs12_safebag_st {
    int dummy;
} PKCS12_SAFEBAG;

typedef struct pkcs7_st PKCS7;
typedef struct asn1_item_st ASN1_ITEM;

#define STACK_OF(type) struct stack_st_##type
#define ERR_LIB_PKCS12 0
#define PKCS12_R_DECODE_ERROR 0
#define PKCS12_SAFEBAGS 0

struct pkcs7_encrypted_st {
    struct pkcs7_enc_content_st *enc_data;
};

struct pkcs7_enc_content_st {
    void *algorithm;
    void *enc_data;
};

struct pkcs7_ctx_st {
    void *libctx;
    char *propq;
};

struct pkcs7_st {
    int type;
    union {
        struct pkcs7_encrypted_st *encrypted;
    } d;
    struct pkcs7_ctx_st ctx;
};

STACK_OF(PKCS12_SAFEBAG) *PKCS12_item_decrypt_d2i_ex(void *algor, const ASN1_ITEM *it,
                                                    const char *pass, int passlen,
                                                    void *data, int flag,
                                                    void *libctx, const char *propq);
int PKCS7_type_is_encrypted(PKCS7 *p7);
void ERR_raise(int lib, int reason);
const ASN1_ITEM *ASN1_ITEM_rptr(int);