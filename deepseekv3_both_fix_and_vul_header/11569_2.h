#include <stdint.h>
#include <assert.h>
#include <string.h>

typedef unsigned char u_char;

typedef struct pcap pcap_t;

struct pcap_pkthdr {
    uint32_t ts_sec;
    uint32_t ts_usec;
    uint32_t caplen;
    uint32_t len;
};

typedef struct packet_cache {
    u_char *pktdata;
    struct pcap_pkthdr pkthdr;
    struct packet_cache *next;
} packet_cache_t;

typedef struct file_cache {
    packet_cache_t *packet_cache;
    int cached;
} file_cache_t;

typedef struct tcpreplay_opt {
    int preload_pcap;
    struct file_cache *file_cache;
} tcpreplay_opt_t;

typedef struct tcpreplay_t {
    tcpreplay_opt_t *options;
} tcpreplay_t;

extern void *safe_malloc(size_t size);
extern u_char *pcap_next(pcap_t *p, struct pcap_pkthdr *h);