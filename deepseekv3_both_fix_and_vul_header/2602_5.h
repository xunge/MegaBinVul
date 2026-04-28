#include <sys/types.h>
#include <stdio.h>

#define CHDLC_HDRLEN 4

struct pcap_pkthdr {
    u_int len;
    u_int caplen;
};

typedef struct netdissect_options netdissect_options;
typedef unsigned int u_int;

#define ND_PRINT(args) printf args
u_int chdlc_print(netdissect_options *ndo, const u_char *p, u_int length);