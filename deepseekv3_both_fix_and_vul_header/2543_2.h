#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

typedef uint32_t u_int;

struct pcap_pkthdr {
    u_int caplen;
    u_int len;
};

typedef struct pktap_header {
    uint32_t pkt_dlt;
    uint32_t pkt_len;
    uint32_t pkt_rectype;
} pktap_header_t;

typedef struct netdissect_options {
    int ndo_eflag;
    int ndo_suppress_default_print;
} netdissect_options;

typedef u_int (*if_printer)(netdissect_options *ndo, const struct pcap_pkthdr *h, const u_char *p);

#define PKT_REC_NONE 0
#define PKT_REC_PACKET 1

#define EXTRACT_LE_32BITS(p) (*(const uint32_t *)(p))

#define ND_PRINT(args)
#define ND_DEFAULTPRINT(p, caplen)

u_int pktap_header_print(netdissect_options *ndo, const u_char *p, u_int length);
if_printer lookup_printer(uint32_t dlt);