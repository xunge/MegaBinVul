#include <stdint.h>

#define PROTO_TCP 6
#define PROTO_UDP 17

uint16_t net_checksum_tcpudp(int plen, int proto, uint8_t *src, uint8_t *data);