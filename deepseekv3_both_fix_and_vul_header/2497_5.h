#include <stdint.h>
#include <stddef.h>

#define DLT_JUNIPER_ATM1 123
#define ATM_OAM_NOHEC 0

typedef unsigned int u_int;
typedef unsigned char u_char;

typedef struct netdissect_options netdissect_options;
typedef struct pcap_pkthdr {
    uint32_t ts_sec;
    uint32_t ts_usec;
    uint32_t caplen;
    uint32_t len;
} pcap_pkthdr;

struct juniper_l2info_t {
    int pictype;
    u_int header_len;
    u_char cookie[8];
    u_int length;
    u_int caplen;
};

u_int EXTRACT_24BITS(const u_char *);
int juniper_parse_header(netdissect_options *, const u_char *, const struct pcap_pkthdr *, struct juniper_l2info_t *);
void oam_print(netdissect_options *, const u_char *, u_int, int);
int llc_print(netdissect_options *, const u_char *, u_int, u_int, const void *, const void *);
void isoclns_print(netdissect_options *, const u_char *, u_int, ...);
int ip_heuristic_guess(netdissect_options *, const u_char *, u_int);