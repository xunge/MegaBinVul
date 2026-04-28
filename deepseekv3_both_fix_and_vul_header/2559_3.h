#include <stdint.h>
#include <netinet/in.h>
#include <netinet/ip6.h>
#include <netinet/icmp6.h>
#include <netinet/udp.h>

typedef struct netdissect_options {
    const u_char *ndo_snapend;
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK(p)
#define ND_TTEST2(p, l) 1
#define ND_PRINT(args)

#define MLD_MINLEN 24
#define MLDV2_MINLEN 28

/* ICMPv6 message types */
#define ICMP6_HADISCOV_REPLY 145
#define ICMP6_MOBILEPREFIX_ADVERT 147
#define ICMP6_MEMBERSHIP_QUERY 130
#define ICMP6_MEMBERSHIP_REPORT 131
#define ICMP6_MEMBERSHIP_REDUCTION 132
#define ICMP6_NI_QUERY 139
#define ICMP6_NI_REPLY 140
#define IND_SOLICIT 141
#define IND_ADVERT 142
#define ICMP6_V2_MEMBERSHIP_REPORT 143
#define ICMP6_MOBILEPREFIX_SOLICIT 146
#define ICMP6_HADISCOV_REQUEST 144
#define ND_RPL_MESSAGE 155

static inline uint16_t EXTRACT_16BITS(const void *p) {
    return ntohs(*(const uint16_t *)p);
}

static inline uint32_t EXTRACT_32BITS(const void *p) {
    return ntohl(*(const uint32_t *)p);
}

typedef const char *(*tok2str_func)(const void *, const char *, unsigned int);
typedef const char *(*bittok2str_func)(const void *, const char *, unsigned int);

extern tok2str_func tok2str;
extern bittok2str_func bittok2str;
extern const char *ip6addr_string(netdissect_options *, const struct in6_addr *);
extern const char *tcpport_string(netdissect_options *, int);
extern const char *udpport_string(netdissect_options *, int);
extern void print_unknown_data(netdissect_options *, const u_char *, const char *, int);
extern const struct udphdr *get_upperlayer(netdissect_options *, const u_char *, u_int *);
extern const char *get_rtpref(uint32_t);
extern uint16_t in_cksum_shouldbe(uint16_t, uint16_t);
extern uint16_t icmp6_cksum(netdissect_options *, const struct ip6_hdr *, const struct icmp6_hdr *, u_int);
extern void mld6_print(netdissect_options *, const u_char *);
extern void mldv2_query_print(netdissect_options *, const u_char *, u_int);
extern void mldv2_report_print(netdissect_options *, const u_char *, u_int);
extern void icmp6_opt_print(netdissect_options *, const u_char *, u_int);
extern void icmp6_rrenum_print(netdissect_options *, const u_char *, const u_char *);
extern void icmp6_nodeinfo_print(netdissect_options *, u_int, const u_char *, const u_char *);
extern void rpl_print(netdissect_options *, const struct icmp6_hdr *, const uint8_t *, u_int);