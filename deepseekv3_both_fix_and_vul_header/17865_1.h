#include <stdint.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stddef.h>

struct tcphdr {
    uint16_t source;
    uint16_t dest;
};

struct ndpi_packet_struct {
    struct tcphdr *tcp;
    uint8_t *payload;
    uint16_t payload_packet_len;
};

struct ndpi_flow_struct {
    struct ndpi_packet_struct packet;
};

struct ndpi_detection_module_struct;

#define NDPI_LOG_DBG(ndpi_struct, fmt, ...)
#define NDPI_LOG_DBG2(ndpi_struct, fmt, ...) 
#define NDPI_LOG_INFO(ndpi_struct, fmt, ...)
#define NDPI_EXCLUDE_PROTO(ndpi_struct, flow)

void ndpi_int_oracle_add_connection(struct ndpi_detection_module_struct *ndpi_struct, struct ndpi_flow_struct *flow);