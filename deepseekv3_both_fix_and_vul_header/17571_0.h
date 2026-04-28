#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

struct ndpi_packet_struct {
    const uint8_t *payload;
    uint16_t payload_packet_len;
};