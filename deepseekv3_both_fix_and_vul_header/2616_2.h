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
    uint8_t type;
    uint8_t reserved;
};

#define _U_ 
#define ND_PRINT(args)
#define ND_TCHECK(ptr)
#define UNALIGNED_MEMCPY(dst, src, len) memcpy(dst, src, len)
#define NPSTR(x) ""
#define ISAKMP_NPTYPE_VID 0

static int rawprint(netdissect_options *ndo, const uint8_t *data, int len) {
    return 0;
}