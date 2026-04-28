#include <stdint.h>
#include <stddef.h>

typedef int krb5_error_code;

#define ASN1_OVERRUN 1
#define ASN1_MISMATCH_INDEF 2
#define ASN1_OVERFLOW 3

#define CONSTRUCTED 0x20

typedef struct taginfo {
    unsigned int asn1class;
    unsigned int construction;
    unsigned int tagnum;
    size_t tag_len;
    size_t tag_end_len;
} taginfo;