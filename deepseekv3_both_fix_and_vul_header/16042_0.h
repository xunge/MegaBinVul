#include <stdint.h>
#include <string.h>

struct pico_ip4 {
    uint32_t addr;
};

struct pico_ipv4_hdr {
    struct pico_ip4 src;
    struct pico_ip4 dst;
    uint8_t proto;
    uint8_t tos;
};

struct pico_trans {
    uint16_t sport;
    uint16_t dport;
};

struct pico_icmp4_hdr {
    uint8_t type;
    uint8_t code;
};

struct filter_node {
    void *fdev;
    uint32_t out_addr;
    uint32_t in_addr;
    uint16_t out_port;
    uint16_t in_port;
    uint8_t proto;
    uint8_t priority;
    uint8_t tos;
};

struct pico_frame {
    void *net_hdr;
    void *transport_hdr;
    void *buffer;
    uint32_t buffer_len;
    void *dev;
    uint8_t priority;
};

#define PICO_PROTO_TCP 6
#define PICO_PROTO_UDP 17
#define PICO_PROTO_ICMP4 1
#define PICO_ICMP_UNREACH 3
#define PICO_ICMP_UNREACH_FILTER_PROHIB 13

static inline uint16_t short_be(uint16_t val) {
    return ((val >> 8) & 0xFF) | ((val & 0xFF) << 8);
}

int ipfilter_apply_filter(struct pico_frame *f, struct filter_node *temp);