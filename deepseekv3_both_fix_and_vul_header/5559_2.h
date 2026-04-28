#include <stddef.h>

#define V_ASN1_OBJECT          0x01
#define V_ASN1_BOOLEAN         0x02
#define V_ASN1_NULL            0x05
#define V_ASN1_INTEGER         0x06
#define V_ASN1_NEG_INTEGER     0x86
#define V_ASN1_ENUMERATED      0x0A
#define V_ASN1_NEG_ENUMERATED  0x8A
#define V_ASN1_BIT_STRING      0x03
#define V_ASN1_OCTET_STRING    0x04
#define V_ASN1_SEQUENCE        0x10
#define V_ASN1_SET             0x11
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

typedef struct asn1_string_st ASN1_STRING;
typedef struct asn1_object_st ASN1_OBJECT;

typedef struct asn1_type_st {
    int type;
    union {
        char *ptr;
        ASN1_OBJECT *object;
        int boolean;
        ASN1_STRING *string;
    } value;
} ASN1_TYPE;

int OBJ_cmp(const ASN1_OBJECT *a, const ASN1_OBJECT *b);
int ASN1_STRING_cmp(const ASN1_STRING *a, const ASN1_STRING *b);