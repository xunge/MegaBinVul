#include <stdint.h>
#include <arpa/inet.h>
#include <string.h>

typedef unsigned char u_char;

typedef struct netdissect_options netdissect_options;

struct isakmp_gen {
    uint16_t len;
    u_char np;
};

#define ND_TCHECK(a)
#define ND_TCHECK2(a, b)
#define ND_PRINT(a)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define NPSTR(np) ""