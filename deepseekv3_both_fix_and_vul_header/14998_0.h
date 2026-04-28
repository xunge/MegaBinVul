#include <stddef.h>

struct asn1_ctx {
    unsigned char *pointer;
    unsigned char *end;
};

static int asn1_octet_decode(struct asn1_ctx *ctx, unsigned char *ch);