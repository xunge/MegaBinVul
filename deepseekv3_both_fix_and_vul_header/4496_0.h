#include <string.h>

#define V_ASN1_NEG 0x100

typedef struct ASN1_INTEGER_st {
    int type;
    int length;
    unsigned char *data;
} ASN1_INTEGER;