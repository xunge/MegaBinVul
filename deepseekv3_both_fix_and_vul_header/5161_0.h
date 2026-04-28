#include <stddef.h>
#include <stdint.h>

typedef uint32_t __be32;

struct snmp_ctx {
    __be32 from;
    __be32 to;
    int (*check)(void);
    unsigned char *begin;
};

#define EINVAL 22
#define pr_debug(fmt, ...) 
#define fast_csum(ctx, data)