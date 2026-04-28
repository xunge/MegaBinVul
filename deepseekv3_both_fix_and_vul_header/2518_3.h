#include <stdint.h>
#include <netinet/in.h>

typedef struct netdissect_options {
    int ndo_eflag;
    int ndo_vflag;
    const u_char *ndo_snapend;
} netdissect_options;

struct ip6_hdr {
    union {
        struct {
            uint32_t ip6_un1_flow;
            uint16_t ip6_un1_plen;
            uint8_t ip6_un1_nxt;
            uint8_t ip6_un1_hlim;
        } ip6_un1;
        uint8_t ip6_un2_vfc;
    } ip6_ctlun;
    struct in6_addr ip6_src;
    struct in6_addr ip6_dst;
};

#define ip6_vfc ip6_ctlun.ip6_un2_vfc
#define ip6_flow ip6_ctlun.ip6_un1.ip6_un1_flow
#define ip6_plen ip6_ctlun.ip6_un1.ip6_un1_plen
#define ip6_nxt ip6_ctlun.ip6_un1.ip6_un1_nxt
#define ip6_hlim ip6_ctlun.ip6_un1.ip6_un1_hlim

#define IP6_VERSION(ip6) (((ip6)->ip6_vfc & 0xf0) >> 4)

#define ND_TCHECK(p)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))

#define IPPROTO_MOBILITY_OLD 62
#define IPPROTO_MOBILITY 135
#define IPPROTO_IPCOMP 108
#define IPPROTO_OSPF 89
#define IPPROTO_IPV4 4
#define IPPROTO_PGM 113

typedef uint8_t u_char;
typedef uint32_t u_int;

const char *tok2str(const char **, const char *, int);
const char *ip6addr_string(const netdissect_options *, const struct in6_addr *);
int hbhopt_print(netdissect_options *, const u_char *);
int dstopt_print(netdissect_options *, const u_char *);
int frag6_print(netdissect_options *, const u_char *, const u_char *);
int mobility_print(netdissect_options *, const u_char *, const u_char *);
int rt6_print(netdissect_options *, const u_char *, const u_char *);
void sctp_print(netdissect_options *, const u_char *, const u_char *, u_int);
void dccp_print(netdissect_options *, const u_char *, const u_char *, u_int);
void tcp_print(netdissect_options *, const u_char *, u_int, const u_char *, int);
void udp_print(netdissect_options *, const u_char *, u_int, const u_char *, int);
void icmp6_print(netdissect_options *, const u_char *, u_int, const u_char *, int);
int ah_print(netdissect_options *, const u_char *);
int esp_print(netdissect_options *, const u_char *, u_int, const u_char *, int *, int *);
void ipcomp_print(netdissect_options *, const u_char *);
void pim_print(netdissect_options *, const u_char *, u_int, const u_char *);
void ospf6_print(netdissect_options *, const u_char *, u_int);
void ip_print(netdissect_options *, const u_char *, u_int);
void pgm_print(netdissect_options *, const u_char *, u_int, const u_char *);
void gre_print(netdissect_options *, const u_char *, u_int);
void rsvp_print(netdissect_options *, const u_char *, u_int);