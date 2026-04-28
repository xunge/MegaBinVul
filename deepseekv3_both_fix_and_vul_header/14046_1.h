#include <stddef.h>

typedef struct asn1_string_st {
    unsigned char *data;
    int length;
} ASN1_OCTET_STRING;

typedef struct IPAddressFamily_st {
    ASN1_OCTET_STRING *addressFamily;
} IPAddressFamily;