#include <stdint.h>

#define PICO_SIZE_IP4HDR 20
#define PICO_IPV4_EVIL 0x8000
#define PICO_IPV4_MOREFRAG 0x2000
#define PICO_IPV4_FRAG_MASK 0x1FFF

struct pico_ip4 {
    uint32_t addr;
};

struct pico_ipv4_hdr {
    uint8_t vhl;
    uint8_t tos;
    uint16_t len;
    uint16_t id;
    uint16_t frag;
    uint8_t ttl;
    uint8_t proto;
    uint16_t crc;
    struct pico_ip4 src;
    struct pico_ip4 dst;
    uint8_t options[];
};

struct pico_frame {
    uint8_t *buffer;
    uint8_t *net_hdr;
    uint8_t *transport_hdr;
    uint16_t buffer_len;
    uint16_t net_len;
    uint16_t transport_len;
    uint16_t frag;
    struct pico_device *dev;
};

struct pico_stack;
struct pico_protocol;
struct pico_device;

uint16_t short_be(uint16_t val);
void pico_frame_discard(struct pico_frame *f);
int pico_ipv4_crc_check(struct pico_frame *f);
int pico_ipv4_is_valid_src(struct pico_stack *S, uint32_t addr, struct pico_device *dev);
int pico_icmp4_param_problem(struct pico_stack *S, struct pico_frame *f, uint8_t code);
void pico_ipv4_process_frag(struct pico_ipv4_hdr *hdr, struct pico_frame *f, uint8_t proto);
void pico_socket_ipv4_process_in(struct pico_frame *f);
int pico_ipv4_process_bcast_in(struct pico_stack *S, struct pico_frame *f);
int pico_ipv4_process_mcast_in(struct pico_frame *f);
int pico_ipv4_process_local_unicast_in(struct pico_stack *S, struct pico_frame *f);
void pico_ipv4_process_finally_try_forward(struct pico_stack *S, struct pico_frame *f);
int ipfilter(struct pico_frame *f);