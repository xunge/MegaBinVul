#include <stdint.h>

struct dhcp_packet;

#define DHCP_LEASE_TIME 0x33

uint8_t *dhcp_get_option(struct dhcp_packet *packet, ...);
uint32_t get_be32(const uint8_t *data);