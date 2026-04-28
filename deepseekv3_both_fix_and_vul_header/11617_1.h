#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct pcap pcap_t;

struct pcap_pkthdr {
    uint32_t ts_sec;
    uint32_t ts_usec;
    uint32_t caplen;
    uint32_t len;
};

typedef unsigned char u_char;

#define MAXPACKET 65536
#define MAX_PCAP_PACKET_LEN 65536

int pcap_next_ex(pcap_t *p, struct pcap_pkthdr **pkt_header, const u_char **pkt_data);