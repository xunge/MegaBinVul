#include <stdint.h>
#include <stdio.h>

typedef uint32_t u_int;
typedef unsigned char u_char;

#define DLT_JUNIPER_MLFR 1
#define LLC_UI 3
#define NLPID_Q933 8
#define NLPID_IP 204
#define NLPID_IP6 142

typedef struct {
    int ndo_eflag;
} netdissect_options;

struct pcap_pkthdr {
    uint32_t ts_sec;
    uint32_t ts_usec;
    uint32_t caplen;
    uint32_t len;
};

struct juniper_l2info_t {
    int pictype;
    u_int header_len;
    uint32_t cookie;
    uint32_t bundle;
    uint32_t proto;
    uint32_t length;
    uint32_t caplen;
};

#define EXTRACT_32BITS(p) (*(const uint32_t *)(p))
#define ND_PRINT(args) printf args

int juniper_parse_header(netdissect_options *ndo, const u_char *p, const struct pcap_pkthdr *h, struct juniper_l2info_t *l2info);
void isoclns_print(netdissect_options *ndo, const u_char *p, u_int length, ...);