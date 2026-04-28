#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <stddef.h>

typedef struct netdissect_options {
    int ndo_eflag;
    int ndo_vflag;
} netdissect_options;

struct arp_pkthdr {
    u_short ar_hrd;
    u_short ar_pro;
    u_char ar_hln;
    u_char ar_pln;
    u_short ar_op;
    u_char ar_sha[6];
    u_char ar_spa[4];
    u_char ar_tha[6];
    u_char ar_tpa[4];
};

#define ND_TCHECK(p)
#define ND_TTEST2(p, l) 1
#define ND_PRINT(args)
#define ND_DEFAULTPRINT(p, l)

#define HRD(ap) (ap)->ar_hrd
#define PRO(ap) (ap)->ar_pro
#define OP(ap) (ap)->ar_op
#define PROTO_LEN(ap) (ap)->ar_pln
#define HRD_LEN(ap) (ap)->ar_hln
#define ar_tpa(ap) (ap)->ar_tpa
#define TPA(ap) (ap)->ar_tpa
#define THA(ap) (ap)->ar_tha
#define SPA(ap) (ap)->ar_spa
#define SHA(ap) (ap)->ar_sha

#define LINKADDR_ETHER 1
#define LINKADDR_FRELAY 2

#define ARPHRD_ATM2225 19
#define ARPHRD_FRELAY 15

#define ARPOP_REQUEST 1
#define ARPOP_REPLY 2
#define ARPOP_REVREQUEST 3
#define ARPOP_REVREPLY 4
#define ARPOP_INVREQUEST 8
#define ARPOP_INVREPLY 9

#define ETHERTYPE_IP 0x0800
#define ETHERTYPE_TRAIL 0x1000

extern const char *tstr;
extern const char *tok2str(const void *, const char *, int);
extern const char *ipaddr_string(netdissect_options *, const u_char *);
extern const char *linkaddr_string(netdissect_options *, const u_char *, int, int);
extern int isnonzero(const u_char *, int);
extern void atmarp_print(netdissect_options *, const u_char *, u_int, u_int);