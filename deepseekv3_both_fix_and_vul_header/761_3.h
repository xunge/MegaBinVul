#include <stdint.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define VRRP_AUTH_NONE 0
#define VRRP_AUTH_SIMPLE 1
#define VRRP_TYPE_ADVERTISEMENT 1
#define IPPROTO_VRRP 112

typedef struct netdissect_options {
    int ndo_vflag;
    const u_char *ndo_snapend;
} netdissect_options;

struct cksum_vec {
    const u_char *ptr;
    int len;
};

extern const char *type2str[];
extern const char *auth2str[];
extern const char *tok2str(const char * const *, const char *, int);
extern int in_cksum(const struct cksum_vec *, int);
extern uint16_t nextproto4_cksum(netdissect_options *, const struct ip *, const u_char *, int, int, int);
extern const char *ipaddr_string(netdissect_options *, const u_char *);
extern int fn_printn(netdissect_options *, const u_char *, u_int, const u_char *);

#define ND_TCHECK(p) 
#define ND_TTEST2(p, l) 1
#define ND_PRINT(args) 
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))