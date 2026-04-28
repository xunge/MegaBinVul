#include <stddef.h>

typedef struct asn1_object_st ASN1_OBJECT;
typedef struct asn1_type_st ASN1_TYPE;
typedef struct asn1_string_st ASN1_STRING;

typedef struct X509_algor_st {
    ASN1_OBJECT *algorithm;
    ASN1_TYPE *parameter;
} X509_ALGOR;

typedef struct asn1_type_st {
    int type;
    union {
        ASN1_STRING *sequence;
    } value;
} ASN1_TYPE;

typedef struct asn1_string_st {
    unsigned char *data;
    int length;
} ASN1_STRING;

int OBJ_obj2nid(ASN1_OBJECT *obj);
X509_ALGOR *d2i_X509_ALGOR(X509_ALGOR **a, const unsigned char **in, long len);

#define NID_mgf1 911
#define V_ASN1_SEQUENCE 16