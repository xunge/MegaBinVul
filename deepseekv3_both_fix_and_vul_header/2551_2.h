#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_eflag;
    int ndo_vflag;
} netdissect_options;

struct atmarp_pkthdr {
    u_short ar_hrd;
    u_short ar_pro;
    u_char  ar_hln;
    u_char  ar_pln;
    u_short ar_op;
};

#define ND_TCHECK(p)
#define ND_TTEST2(p, l) 1
#define ND_PRINT(args)
#define ND_DEFAULTPRINT(p, l)

#define ATMHRD(ap) ((ap)->ar_hrd)
#define ATMPRO(ap) ((ap)->ar_pro)
#define ATMOP(ap)  ((ap)->ar_op)
#define ATMSPROTO_LEN(ap) ((ap)->ar_pln)
#define ATMTPROTO_LEN(ap) ((ap)->ar_pln)
#define ATMTHRD_LEN(ap) ((ap)->ar_hln)
#define ATMSHRD_LEN(ap) ((ap)->ar_hln)
#define ATMTPA(ap) ((u_char *)(ap) + sizeof(struct atmarp_pkthdr))
#define ATMSPA(ap) ATMTPA(ap)
#define ATMTHA(ap) ATMTPA(ap)
#define ATMSHA(ap) ATMTPA(ap)
#define ATMTSA(ap) ATMTPA(ap)
#define ATMSSA(ap) ATMTPA(ap)
#define ATMTSLN(ap) 0
#define ATMSSLN(ap) 0

#define ETHERTYPE_IP    0x0800
#define ETHERTYPE_TRAIL 0x1000

#define ARPOP_REQUEST   1
#define ARPOP_REPLY     2
#define ARPOP_INVREQUEST 8
#define ARPOP_INVREPLY  9
#define ARPOP_NAK       10

static const char *tstr = "[|atm]";

static const char *tok2str(const char *str, const char *fmt, int val) {
    return NULL;
}

static const char *ipaddr_string(netdissect_options *ndo, const void *addr) {
    return NULL;
}

static void atmarp_addr_print(netdissect_options *ndo, const u_char *ha, u_int hrdlen, const u_char *suba, u_int sublen) {
}