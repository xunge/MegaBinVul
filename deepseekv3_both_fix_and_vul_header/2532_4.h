#include <stdint.h>
#include <stdio.h>

typedef unsigned int u_int;
typedef unsigned char u_char;

#define DLT_JUNIPER_GGSN 0

typedef struct netdissect_options {
    int ndo_eflag;
} netdissect_options;

struct pcap_pkthdr {
    unsigned int len;
    unsigned int caplen;
};

struct juniper_l2info_t {
    int pictype;
    u_int header_len;
    u_int length;
    uint8_t cookie[8];
};

struct juniper_ggsn_header {
    uint8_t svc_id;
    uint8_t flags_len;
    uint8_t proto;
    uint8_t flags;
    uint8_t vlan_id[2];
    uint8_t res[2];
};

#define JUNIPER_PROTO_IPV4 0
#define JUNIPER_PROTO_IPV6 1

#define ND_TCHECK(x)
#define ND_PRINT(args) printf args
#define EXTRACT_16BITS(p) ((p)[0] << 8 | (p)[1])

struct tok {
    const char *name;
    int v;
};

extern const struct tok juniper_protocol_values[];
extern int juniper_parse_header(netdissect_options *, const u_char *, const struct pcap_pkthdr *, struct juniper_l2info_t *);
extern void ip_print(netdissect_options *, const u_char *, u_int);
extern void ip6_print(netdissect_options *, const u_char *, u_int);