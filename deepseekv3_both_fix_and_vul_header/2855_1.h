#include <stdio.h>
#include <stdlib.h>

#define MAXPACKET 65536

typedef unsigned char u_char;

typedef struct pcap_pkthdr {
    unsigned int len;
    unsigned int caplen;
} pcap_pkthdr;

typedef void pcap_t;

u_char *pcap_next(pcap_t *p, pcap_pkthdr *h);