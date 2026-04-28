#include <string.h>
#include <stddef.h>

#define MDC2_BLOCK 8

typedef struct MDC2_CTX {
    unsigned char data[MDC2_BLOCK];
    int num;
} MDC2_CTX;

void mdc2_body(MDC2_CTX *c, const unsigned char *in, size_t len);