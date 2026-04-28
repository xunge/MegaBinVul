#include <stdlib.h>

typedef struct ASN1_VALUE_st ASN1_VALUE;

typedef struct ASN1_ITEM_st {
    int utype;
    const struct ASN1_PRIMITIVE_FUNCS_st *funcs;
} ASN1_ITEM;

typedef struct ASN1_PRIMITIVE_FUNCS_st {
    int (*prim_c2i)(ASN1_VALUE **pval, const unsigned char *cont, int len,
                   int utype, char *free_cont, const ASN1_ITEM *it);
} ASN1_PRIMITIVE_FUNCS;

typedef struct ASN1_STRING_st {
    int type;
    unsigned char *data;
    int length;
} ASN1_STRING;

typedef struct ASN1_TYPE_st {
    int type;
    union {
        ASN1_VALUE *asn1_value;
        void *ptr;
    } value;
} ASN1_TYPE;

typedef struct ASN1_OBJECT_st ASN1_OBJECT;
typedef struct ASN1_BIT_STRING_st ASN1_BIT_STRING;
typedef struct ASN1_INTEGER_st {
    int type;
} ASN1_INTEGER;

#define V_ASN1_OBJECT          0x06
#define V_ASN1_NULL            0x05
#define V_ASN1_BOOLEAN         0x01
#define V_ASN1_BIT_STRING      0x03
#define V_ASN1_INTEGER         0x02
#define V_ASN1_NEG_INTEGER     0x102
#define V_ASN1_ENUMERATED      0x0A
#define V_ASN1_NEG_ENUMERATED  0x10A
#define V_ASN1_OCTET_STRING    0x04
#define V_ASN1_NUMERICSTRING   0x12
#define V_ASN1_PRINTABLESTRING 0x13
#define V_ASN1_T61STRING       0x14
#define V_ASN1_VIDEOTEXSTRING  0x15
#define V_ASN1_IA5STRING       0x16
#define V_ASN1_UTCTIME         0x17
#define V_ASN1_GENERALIZEDTIME 0x18
#define V_ASN1_GRAPHICSTRING   0x19
#define V_ASN1_VISIBLESTRING   0x1A
#define V_ASN1_GENERALSTRING   0x1B
#define V_ASN1_UNIVERSALSTRING 0x1C
#define V_ASN1_BMPSTRING       0x1E
#define V_ASN1_UTF8STRING      0x0C
#define V_ASN1_OTHER           0x00
#define V_ASN1_SET             -1
#define V_ASN1_SEQUENCE        -2
#define V_ASN1_ANY             -3
#define V_ASN1_NEG             0x100

#define ASN1_F_ASN1_EX_C2I 0
#define ASN1_R_NULL_IS_WRONG_LENGTH 0
#define ASN1_R_BOOLEAN_IS_WRONG_LENGTH 0
#define ASN1_R_BMPSTRING_IS_WRONG_LENGTH 0
#define ASN1_R_UNIVERSALSTRING_IS_WRONG_LENGTH 0
#define ERR_R_MALLOC_FAILURE 0

typedef int ASN1_BOOLEAN;

ASN1_TYPE *ASN1_TYPE_new(void);
void ASN1_TYPE_free(ASN1_TYPE *a);
void ASN1_TYPE_set(ASN1_TYPE *a, int type, void *value);
int c2i_ASN1_OBJECT(ASN1_OBJECT **a, const unsigned char **pp, long length);
int c2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a, const unsigned char **pp, long length);
int c2i_ASN1_INTEGER(ASN1_INTEGER **a, const unsigned char **pp, long length);
ASN1_STRING *ASN1_STRING_type_new(int type);
int ASN1_STRING_set(ASN1_STRING *str, const void *data, int len);
void ASN1_STRING_free(ASN1_STRING *a);
void ASN1err(int f, int r);
void OPENSSL_free(void *ptr);