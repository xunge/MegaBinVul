#include <stddef.h>

#define ASN1_PRI 0

struct asn1_ctx {
    unsigned char *pointer;
};

static int asn1_id_decode(struct asn1_ctx *ctx, unsigned int *cls, unsigned int *con, unsigned int *tag);
static int asn1_length_decode(struct asn1_ctx *ctx, unsigned int *def, unsigned int *len);