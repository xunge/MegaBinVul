#include <stdio.h>
#include <stdlib.h>

#define NID_pkcs7_signed 1
#define PKCS7_F_PKCS7_CTRL 1
#define PKCS7_R_OPERATION_NOT_SUPPORTED_ON_THIS_TYPE 1
#define PKCS7_R_UNKNOWN_OPERATION 2
#define PKCS7_OP_SET_DETACHED_SIGNATURE 1
#define PKCS7_OP_GET_DETACHED_SIGNATURE 2

typedef struct asn1_string_st ASN1_OCTET_STRING;
typedef struct pkcs7_st PKCS7;
typedef struct pkcs7_signed_st PKCS7_SIGNED;
typedef struct pkcs7_content_info_st PKCS7_CONTENT_INFO;

struct asn1_string_st {
    int length;
    unsigned char *data;
};

struct pkcs7_content_info_st {
    int type;
    union {
        ASN1_OCTET_STRING *data;
        void *ptr;
    } d;
};

struct pkcs7_signed_st {
    PKCS7_CONTENT_INFO *contents;
};

struct pkcs7_st {
    int type;
    int detached;
    union {
        PKCS7_SIGNED *sign;
    } d;
};

void ASN1_OCTET_STRING_free(ASN1_OCTET_STRING *a);
int OBJ_obj2nid(int type);
int PKCS7_type_is_data(PKCS7_CONTENT_INFO *ptr);
void PKCS7err(int f, int r);