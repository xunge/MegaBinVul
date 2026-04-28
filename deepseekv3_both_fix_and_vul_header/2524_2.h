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
#define ND_TCHECK(expr)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define NPSTR(type) ""
#define ISAKMP_NPTYPE_NONCE 0

extern int rawprint(netdissect_options *, const uint8_t *, int);
extern int ike_show_somedata(netdissect_options *, const u_char *, const u_char *);