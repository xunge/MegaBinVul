#include <stdint.h>
#include <string.h>
#include <sys/types.h>

typedef unsigned int u_int;
typedef unsigned char u_char;

typedef struct netdissect_options {
    int ndo_eflag;
} netdissect_options;

struct pcap_pkthdr {
    unsigned int len;
    unsigned int caplen;
};

struct juniper_l2info_t {
    int pictype;
    int header_len;
    int cookie_len;
    int length;
    int caplen;
    uint32_t cookie;
    uint32_t bundle;
    uint16_t proto;
};

#define DLT_JUNIPER_MFR 0
#define AS_PIC_COOKIE_LEN 0
#define JUNIPER_LSQ_L3_PROTO_IPV4 1
#define JUNIPER_LSQ_L3_PROTO_IPV6 2
#define JUNIPER_LSQ_L3_PROTO_MPLS 3
#define JUNIPER_LSQ_L3_PROTO_ISO 4
#define LLCSAP_ISONS 0xFE
#define LLC_UI 0x03
#define NLPID_Q933 0x08
#define NLPID_IP 0xCC
#define NLPID_IP6 0x8E
#define EXTRACT_32BITS(p) 0
#define ND_PRINT(args)

int juniper_parse_header(netdissect_options *, const u_char *, const struct pcap_pkthdr *, struct juniper_l2info_t *);
void mfr_print(netdissect_options *, const u_char *, u_int);
void ip_print(netdissect_options *, const u_char *, u_int);
void ip6_print(netdissect_options *, const u_char *, u_int);
void mpls_print(netdissect_options *, const u_char *, u_int);
void isoclns_print(netdissect_options *, const u_char *, u_int, ...);