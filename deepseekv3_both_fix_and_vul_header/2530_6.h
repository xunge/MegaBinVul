#include <stdint.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>

typedef unsigned int u_int;
typedef unsigned char u_char;

typedef struct netdissect_options {
    int ndo_eflag;
} netdissect_options;

struct pcap_pkthdr;

struct juniper_l2info_t {
    int pictype;
    u_int header_len;
    u_int length;
};

#define DLT_JUNIPER_MONITOR 0
#define EXTRACT_16BITS(p) ((u_int16_t)ntohs(*(const u_int16_t *)(p)))
#define EXTRACT_32BITS(p) ((u_int32_t)ntohl(*(const u_int32_t *)(p)))
#define ND_PRINT(args) printf args

int juniper_parse_header(netdissect_options *ndo, const u_char *p,
                        const struct pcap_pkthdr *h, struct juniper_l2info_t *l2info);
void ip_heuristic_guess(netdissect_options *ndo, const u_char *p, u_int length);

u_int juniper_monitor_print(netdissect_options *ndo,
                          const struct pcap_pkthdr *h,
                          register const u_char *p);