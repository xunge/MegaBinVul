#include <stdlib.h>
#include <stddef.h>

typedef struct pkcs12_safebag_st PKCS12_SAFEBAG;
typedef struct stack_st_PKCS12_SAFEBAG {
    PKCS12_SAFEBAG **data;
    int num;
    int sorted;
} STACK_OF_PKCS12_SAFEBAG;

typedef struct PKCS7_encrypted_st {
    struct {
        void *algorithm;
        void *enc_data;
    } *enc_data;
} PKCS7_ENCRYPT;

typedef struct PKCS7_st {
    union {
        PKCS7_ENCRYPT *encrypted;
    } d;
    struct {
        void *libctx;
        const char *propq;
    } ctx;
} PKCS7;

#define STACK_OF(type) struct stack_st_##type
#define DECLARE_STACK_OF(type) STACK_OF(type)
#define PKCS12_SAFEBAGS "PKCS12_SAFEBAGS"

int PKCS7_type_is_encrypted(PKCS7 *p7);
void *ASN1_ITEM_rptr(const char *name);
STACK_OF_PKCS12_SAFEBAG *PKCS12_item_decrypt_d2i_ex(void *a, void *b, const char *c, int d, void *e, int f, void *g, const char *h);

#define ERR_LIB_PKCS12 0
#define PKCS12_R_DECODE_ERROR 0