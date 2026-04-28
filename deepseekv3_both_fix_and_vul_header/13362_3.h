#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/time.h>

#define MAX_CAPTURE_LEN 65535
#define DLT_EN10MB 1
#define DLT_NFLOG 239
#define ETHERTYPE_8021Q 0x8100
#define NFULA_PAYLOAD 0x2
#define IP_MF 0x2000
#define IP_OFFMASK 0x1fff

struct pcap_pkthdr {
    struct timeval ts;
    uint32_t caplen;
    uint32_t len;
};

typedef struct address_t {
    char ip[INET6_ADDRSTRLEN];
} address_t;

typedef struct packet_t {
    uint32_t ip_ver;
    uint8_t proto;
    address_t src;
    address_t dst;
    uint32_t ip_id;
    uint32_t ip_cap_len;
    uint32_t ip_exp_len;
    void *frames;
} packet_t;

typedef struct capture_info_t {
    uint16_t link;
    uint16_t link_hl;
    void *ip_reasm;
} capture_info_t;

typedef struct frame_t {
    u_char *data;
} frame_t;

typedef struct vector_iter_t {
    void *data;
    size_t index;
} vector_iter_t;

typedef struct nflog_tlv_t {
    uint16_t tlv_type;
    uint16_t tlv_length;
} nflog_tlv_t;

typedef struct sll_header {
    uint16_t sll_protocol;
} sll_header;

packet_t* packet_create(uint32_t ip_ver, uint8_t proto, address_t src, address_t dst, uint32_t ip_id);
void packet_add_frame(packet_t *pkt, const struct pcap_pkthdr *header, u_char *packet);
vector_iter_t vector_iterator(void *vector);
packet_t* vector_iterator_next(vector_iter_t *it);
int addressport_equals(address_t a1, address_t a2);
void vector_append(void *vector, packet_t *pkt);
void vector_remove(void *vector, packet_t *pkt);