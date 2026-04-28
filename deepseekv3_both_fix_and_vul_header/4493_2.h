#include <stddef.h>
#include <string.h>

typedef struct ASN1_VALUE_st ASN1_VALUE;
typedef int ASN1_BOOLEAN;

struct ASN1_STRING_st {
    int type;
    unsigned char *data;
    int length;
    int flags;
};
typedef struct ASN1_STRING_st ASN1_STRING;

struct ASN1_OBJECT_st {
    unsigned char *data;
    int length;
};
typedef struct ASN1_OBJECT_st ASN1_OBJECT;

struct ASN1_TYPE_st {
    int type;
    union {
        ASN1_VALUE *asn1_value;
    } value;
};
typedef struct ASN1_TYPE_st ASN1_TYPE;

struct ASN1_ITEM_st {
    int itype;
    int utype;
    int size;
    const struct ASN1_PRIMITIVE_FUNCS_st *funcs;
};
typedef struct ASN1_ITEM_st ASN1_ITEM;

struct ASN1_PRIMITIVE_FUNCS_st {
    int (*prim_i2c)(ASN1_VALUE **pval, unsigned char *cout, int *putype, const ASN1_ITEM *it);
};
typedef struct ASN1_PRIMITIVE_FUNCS_st ASN1_PRIMITIVE_FUNCS;

struct ASN1_BIT_STRING_st {
    int dummy;
};
typedef struct ASN1_BIT_STRING_st ASN1_BIT_STRING;

struct ASN1_INTEGER_st {
    int dummy;
};
typedef struct ASN1_INTEGER_st ASN1_INTEGER;

#define V_ASN1_BOOLEAN 1
#define V_ASN1_OBJECT 3
#define V_ASN1_NULL 5
#define V_ASN1_INTEGER 2
#define V_ASN1_NEG_INTEGER 258
#define V_ASN1_ENUMERATED 10
#define V_ASN1_NEG_ENUMERATED 266
#define V_ASN1_BIT_STRING 6
#define V_ASN1_OCTET_STRING 4
#define V_ASN1_NUMERICSTRING 18
#define V_ASN1_PRINTABLESTRING 19
#define V_ASN1_T61STRING 20
#define V_ASN1_VIDEOTEXSTRING 21
#define V_ASN1_IA5STRING 22
#define V_ASN1_UTCTIME 23
#define V_ASN1_GENERALIZEDTIME 24
#define V_ASN1_GRAPHICSTRING 25
#define V_ASN1_VISIBLESTRING 26
#define V_ASN1_GENERALSTRING 27
#define V_ASN1_UNIVERSALSTRING 28
#define V_ASN1_BMPSTRING 30
#define V_ASN1_UTF8STRING 12
#define V_ASN1_SEQUENCE 16
#define V_ASN1_SET 17
#define V_ASN1_ANY 0

#define ASN1_ITYPE_PRIMITIVE 0
#define ASN1_ITYPE_MSTRING 1
#define ASN1_TFLG_NDEF 0x800
#define ASN1_STRING_FLAG_NDEF 0x010

int i2c_ASN1_BIT_STRING(ASN1_BIT_STRING *a, unsigned char **pp);
int i2c_ASN1_INTEGER(ASN1_INTEGER *a, unsigned char **pp);