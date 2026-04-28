#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

struct asn1_ctx {
    unsigned char *pointer;
    int error;
};

#define ASN1_ERR_DEC_BADVALUE 1
#define GFP_ATOMIC 0
#define ULONG_MAX (~0UL)

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
int net_ratelimit(void);
int asn1_subid_decode(struct asn1_ctx *ctx, unsigned long *subid);