#include <stdio.h>
#include <stdlib.h>

#define MAXPACKET 65536

typedef unsigned char u_char;

struct pcap_pkthdr {
    unsigned int ts_sec;
    unsigned int ts_usec;
    unsigned int caplen;
    unsigned int len;
};

typedef struct pcap pcap_t;

int pcap_next_ex(pcap_t *pcap, struct pcap_pkthdr **pkthdr, const u_char **pktdata);