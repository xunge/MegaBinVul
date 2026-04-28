#include <stdio.h>
#include <stdlib.h>

typedef struct pcap pcap_t;
struct pcap_pkthdr {
    unsigned int len;
    unsigned int caplen;
};
typedef unsigned char u_char;

#define MAXPACKET 65536
#define MAX_PCAP_PACKET_LEN 65536