#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>
#include <netinet/icmp6.h>

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_PRINT(args)
#define ND_TCHECK(a)
#define ND_TCHECK2(a, b)
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))

#define ICMP6_NI_QUERY 139
#define ICMP6_NI_REPLY 140
#define ICMP6_NI_SUCCESS 0
#define ICMP6_NI_REFUSED 1
#define ICMP6_NI_UNKNOWN 2
#define ICMP6_NI_SUBJ_IPV6 0
#define ICMP6_NI_SUBJ_FQDN 1
#define ICMP6_NI_SUBJ_IPV4 2

#define NI_QTYPE_NOOP 0
#define NI_QTYPE_SUPTYPES 1
#define NI_QTYPE_FQDN 2
#define NI_QTYPE_NODEADDR 3

#define NI_NODEADDR_FLAG_ANYCAST 0x01
#define NI_NODEADDR_FLAG_GLOBAL 0x02
#define NI_NODEADDR_FLAG_SITELOCAL 0x04
#define NI_NODEADDR_FLAG_LINKLOCAL 0x08
#define NI_NODEADDR_FLAG_COMPAT 0x10
#define NI_NODEADDR_FLAG_ALL 0x20
#define NI_NODEADDR_FLAG_TRUNCATE 0x40

struct icmp6_nodeinfo {
    uint8_t     ni_type;
    uint8_t     ni_code;
    uint16_t    ni_cksum;
    uint16_t    ni_qtype;
    uint16_t    ni_flags;
};

void ip6addr_string(netdissect_options *, const void *);
void ipaddr_string(netdissect_options *, const void *);
void dnsname_print(netdissect_options *, const u_char *, const u_char *);
void safeputchar(netdissect_options *, int);