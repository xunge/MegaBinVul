#include <stdint.h>

#define ETH_ALEN 6
#define BOOTREQUEST 1
#define DHCP_MESSAGE_TYPE 53
#define DHCP_MINTYPE 1
#define DHCP_MAXTYPE 8

struct dhcp_packet {
    uint8_t op;
    uint8_t hlen;
};

uint8_t *dhcp_get_option(struct dhcp_packet *packet, ...);