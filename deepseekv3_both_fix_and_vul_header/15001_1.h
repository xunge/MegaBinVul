#include <limits.h>
#include <stdlib.h>

struct asn1_ctx {
    unsigned char *pointer;
    int error;
};

#define ASN1_ERR_DEC_BADVALUE 0
#define GFP_ATOMIC 0

#define kmalloc(size, flags) malloc(size)
#define kfree(ptr) free(ptr)

static int asn1_subid_decode(struct asn1_ctx *ctx, unsigned long *subid);