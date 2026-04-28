#include <stdio.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stddef.h>

typedef unsigned int u_int;

typedef struct netdissect_options netdissect_options;
struct pcap_pkthdr;

struct juniper_l2info_t {
    int pictype;
    u_int header_len;
    u_int length;
    u_int caplen;
};

#define DLT_JUNIPER_PPPOE_ATM 0
#define ETHERTYPE_LEN 2
#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))

int juniper_parse_header(netdissect_options *, const u_char *, const struct pcap_pkthdr *, struct juniper_l2info_t *);
int ethertype_print(netdissect_options *, uint16_t, const u_char *, u_int, u_int, const void *, const void *);
#define ND_PRINT(args) printf args