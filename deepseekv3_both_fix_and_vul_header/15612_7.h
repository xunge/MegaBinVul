#include <stddef.h>

typedef struct stack_st STACK;
typedef struct pkcs7_st PKCS7;
typedef struct pkcs12_safebag_st PKCS12_SAFEBAG;
typedef struct asn1_item_st ASN1_ITEM;

#define STACK_OF(type) struct stack_st_##type
#define ERR_LIB_PKCS12 0
#define PKCS12_R_CONTENT_TYPE_NOT_DATA 0
#define PKCS12_R_DECODE_ERROR 0
#define PKCS12_SAFEBAGS (&PKCS12_SAFEBAGS_it)

extern const ASN1_ITEM PKCS12_SAFEBAGS_it;

struct pkcs7_st {
    union {
        void *data;
    } d;
};

struct asn1_item_st {
    const char *sname;
};

int PKCS7_type_is_data(PKCS7 *p7);
void ERR_raise(int lib, int reason);
STACK_OF(PKCS12_SAFEBAG) *ASN1_item_unpack(void *data, const ASN1_ITEM *it);
const ASN1_ITEM *ASN1_ITEM_rptr(const ASN1_ITEM *it);