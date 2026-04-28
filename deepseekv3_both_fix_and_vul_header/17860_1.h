#include <stdint.h>
#include <arpa/inet.h>
#include <stddef.h>

struct ndpi_detection_module_struct;
struct ndpi_flow_struct;

struct ndpi_packet_struct {
    struct {
        uint16_t source;
        uint16_t dest;
    } *udp;
    struct {
        uint16_t dest;
    } *tcp;
    uint8_t *payload;
    uint16_t payload_packet_len;
};

struct tpkt {
    uint16_t len;
};

struct ndpi_flow_struct {
    struct ndpi_packet_struct packet;
    struct {
        struct {
            struct {
                uint32_t h323_valid_packets;
            } tcp;
        } l4;
    };
};

#define NDPI_LOG_DBG(ndpi_struct, fmt, ...)
#define NDPI_LOG_DBG2(ndpi_struct, fmt, ...)
#define NDPI_LOG_INFO(ndpi_struct, fmt, ...)
#define NDPI_PROTOCOL_RDP 0
#define NDPI_PROTOCOL_H323 0
#define NDPI_PROTOCOL_UNKNOWN 0
#define NDPI_EXCLUDE_PROTO(ndpi_struct, flow)

void ndpi_set_detected_protocol(struct ndpi_detection_module_struct *ndpi_struct, struct ndpi_flow_struct *flow, uint16_t proto1, uint16_t proto2);