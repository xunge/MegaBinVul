#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

struct krb5_tagged_data {
    uint32_t tag;
    size_t data_len;
    void *data;
};

typedef uint32_t __be32;

#define _enter(fmt, ...)
#define _leave(fmt, ...) 
#define _debug(fmt, ...)

#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22

static void *kmemdup(const void *src, size_t len, int gfp) {
    void *p = malloc(len);
    if (p)
        memcpy(p, src, len);
    return p;
}