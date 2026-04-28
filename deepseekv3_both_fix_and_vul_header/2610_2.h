#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef unsigned char u_char;

typedef struct netdissect_options netdissect_options;
typedef struct isakmp isakmp;

struct isakmp_gen {
    uint16_t len;
    u_char np;
    u_char reserved;
};

#define ND_TCHECK(ext)
#define ND_TCHECK2(ext, len)
#define ND_PRINT(ndo, ...)
#define UNALIGNED_MEMCPY(dst, src, size) memcpy(dst, src, size)
#define NPSTR(np) ""

const u_char *ikev2_sub0_print(netdissect_options *ndo, struct isakmp *base,
                              u_char np, const struct isakmp_gen *ext,
                              const u_char *ep, uint32_t phase, uint32_t doi,
                              uint32_t proto, int depth);