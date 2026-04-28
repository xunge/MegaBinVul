#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <netinet/in.h>

#define SIZE_ETHERNET 14
#define PCAP_OPEN_ERROR -1
#define ERROR -1
#define LOCAL_IP_MATCH 1
#define REMOTE_IP_MATCH 2
#define TH_SYN 0x02

typedef struct input_addr {
    uint8_t byte1;
    uint8_t byte2;
    uint8_t byte3;
    uint8_t byte4;
} input_addr;

typedef struct mac_addr {
    uint8_t byte1;
    uint8_t byte2;
    uint8_t byte3;
    uint8_t byte4;
    uint8_t byte5;
    uint8_t byte6;
} mac_addr;

typedef struct ether_hdr {
    uint8_t ether_dhost[6];
    uint8_t ether_shost[6];
    uint16_t ether_type;
} ether_hdr;

typedef struct ipv4_hdr {
    uint8_t ip_hl;
    input_addr ip_src;
    input_addr ip_dst;
} ipv4_hdr;

typedef struct tcp_hdr {
    uint8_t th_off;
    uint16_t th_sport;
    uint16_t th_dport;
    uint8_t th_flags;
} tcp_hdr;

typedef struct pcap_pkthdr {
    uint32_t ts_sec;
    uint32_t ts_usec;
    uint32_t caplen;
    uint32_t len;
} pcap_pkthdr;

typedef struct pcap_dumper_t {
    FILE *f;
} pcap_dumper_t;

typedef struct pcap_t {
    FILE *f;
} pcap_t;

int compip(input_addr* local_ip, input_addr* remote_ip, input_addr* sip);
void fix_all_checksum_liveplay(ipv4_hdr* iphdr);
pcap_t* set_offline_filter(char* file);
int pcap_next_ex(pcap_t* p, pcap_pkthdr** h, const u_char** pkt);
pcap_dumper_t* pcap_dump_open(pcap_t* p, const char* fname);
void pcap_dump(u_char* d, pcap_pkthdr* h, const u_char* pkt);
void pcap_dump_close(pcap_dumper_t* d);
void pcap_close(pcap_t* p);