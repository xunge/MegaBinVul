#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct isakmp_gen {
    uint16_t len;
};

#define _U_ 
#define ND_PRINT(args)
#define ND_TCHECK(ptr)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define NPSTR(type) ""
#define ISAKMP_NPTYPE_SIG 0

extern int rawprint(netdissect_options *, const uint8_t *, u_int);