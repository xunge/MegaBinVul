#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

struct uip_ip_hdr {
    uint8_t proto;
};

struct uip_ext_hdr {
    uint8_t next;
    uint8_t len;
};

#define UIP_IPH_LEN 0
#define UIP_TCPH_LEN 0
#define UIP_UDPH_LEN 0
#define UIP_ICMPH_LEN 0
#define UIP_PROTO_TCP 0
#define UIP_PROTO_UDP 0
#define UIP_PROTO_ICMP6 0

bool uip_is_proto_ext_hdr(uint8_t protocol);