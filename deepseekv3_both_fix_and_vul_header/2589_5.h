#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <netinet/in.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct icmp6_nodeinfo {
    u_int ni_type;
    u_int ni_code;
    uint16_t ni_qtype;
    uint16_t ni_flags;
};

struct icmp6_hdr {
    uint8_t icmp6_type;
    uint8_t icmp6_code;
    uint16_t icmp6_cksum;
    /* other fields as needed */
};

#define ND_PRINT(args)
#define ND_TCHECK2(ptr, len)
#define EXTRACT_16BITS(p) (*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) (*(const uint32_t *)(p))
#define ND_TTEST2(ptr, len) 1
#define ICMP6_NI_QUERY 0
#define ICMP6_NI_REPLY 1
#define NI_QTYPE_NOOP 0
#define NI_QTYPE_SUPTYPES 1
#define NI_QTYPE_FQDN 2
#define NI_QTYPE_NODEADDR 3
#define ICMP6_NI_SUBJ_IPV6 0
#define ICMP6_NI_SUBJ_FQDN 1
#define ICMP6_NI_SUBJ_IPV4 2
#define ICMP6_NI_SUCCESS 0
#define ICMP6_NI_REFUSED 1
#define ICMP6_NI_UNKNOWN 2
#define NI_NODEADDR_FLAG_ANYCAST 0x01
#define NI_NODEADDR_FLAG_GLOBAL 0x02
#define NI_NODEADDR_FLAG_SITELOCAL 0x04
#define NI_NODEADDR_FLAG_LINKLOCAL 0x08
#define NI_NODEADDR_FLAG_COMPAT 0x10
#define NI_NODEADDR_FLAG_ALL 0x20
#define NI_NODEADDR_FLAG_TRUNCATE 0x40

const char *ip6addr_string(netdissect_options *, const void *);
const char *ipaddr_string(netdissect_options *, const void *);
void safeputchar(netdissect_options *, int);
void dnsname_print(netdissect_options *, const u_char *, const u_char *);