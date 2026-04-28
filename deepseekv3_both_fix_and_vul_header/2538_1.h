#include <netinet/in.h>
#include <string.h>
#include <stdio.h>

typedef struct netdissect_options netdissect_options;

#define ND_TTEST2(p, l) 1
#define EXTRACT_32BITS(p) (*(p) << 24 | *((p)+1) << 16 | *((p)+2) << 8 | *((p)+3))
#define ISIS_MASK_TLV_EXTD_IP_UPDOWN(x) ((x) & 0x80)
#define ISIS_MASK_TLV_EXTD_IP_SUBTLV(x) ((x) & 0x40)
#define ISIS_MASK_TLV_EXTD_IP6_IE(x) ((x) & 0x80)
#define ISIS_MASK_TLV_EXTD_IP6_SUBTLV(x) ((x) & 0x40)

const char *ipaddr_string(netdissect_options *, const void *);
const char *ip6addr_string(netdissect_options *, const void *);
int isis_print_ip_reach_subtlv(netdissect_options *, const uint8_t *, u_int, u_int, const char *);
#define ND_PRINT(args) printf args