#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define _enter(FMT, ...) 
#define _leave(FMT, ...) 
#define _debug(FMT, ...) 

#define AFSTOKEN_K5_TIX_MAX 65535
#define EINVAL 22
#define ENOMEM 12

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t __be32;

#define GFP_KERNEL 0

static void *kmemdup(const void *src, size_t len, int flags) {
    void *p = malloc(len);
    if (p)
        memcpy(p, src, len);
    return p;
}