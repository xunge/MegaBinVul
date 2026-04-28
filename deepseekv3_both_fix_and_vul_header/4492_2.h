typedef struct asn1_object_st ASN1_OBJECT;
typedef struct asn1_string_st ASN1_STRING;
typedef struct asn1_type_st ASN1_TYPE;

#define V_ASN1_OBJECT 1
#define V_ASN1_BOOLEAN 2
#define V_ASN1_NULL 5
#define V_ASN1_INTEGER 6
#define V_ASN1_NEG_INTEGER 7
#define V_ASN1_ENUMERATED 10
#define V_ASN1_NEG_ENUMERATED 11
#define V_ASN1_BIT_STRING 3
#define V_ASN1_OCTET_STRING 4
#define V_ASN1_SEQUENCE 16
#define V_ASN1_SET 17
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
#define V_ASN1_OTHER 0

struct asn1_type_st {
    int type;
    union {
        void *ptr;
        ASN1_OBJECT *object;
        ASN1_STRING *string;
        int boolean;
    } value;
};

int OBJ_cmp(const ASN1_OBJECT *a, const ASN1_OBJECT *b);
int ASN1_STRING_cmp(const ASN1_STRING *a, const ASN1_STRING *b);