#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

#define P_OPCODE_MASK 0xF8
#define P_CONTROL_HARD_RESET_CLIENT_V1 1
#define P_CONTROL_HARD_RESET_CLIENT_V2 2
#define P_CONTROL_HARD_RESET_SERVER_V1 3
#define P_CONTROL_HARD_RESET_SERVER_V2 4
#define P_HARD_RESET_CLIENT_MAX_COUNT 5
#define P_PACKET_ID_ARRAY_LEN_OFFSET(h) (9 + h)

typedef uint8_t u_int8_t;
typedef int8_t s_int8_t;

struct ndpi_detection_module_struct;

struct ndpi_packet_struct {
    const uint8_t *payload;
    uint16_t payload_packet_len;
    struct {
        uint16_t source;
        uint16_t dest;
    } *udp;
    void *tcp;
};

struct ndpi_flow_struct {
    struct ndpi_packet_struct packet;
    uint32_t num_processed_pkts;
    uint8_t ovpn_counter;
    uint8_t ovpn_session_id[8];
};

#define NDPI_PROTOCOL_OPENVPN 1
#define NDPI_PROTOCOL_UNKNOWN 0

#define NDPI_LOG_INFO(a, b)
#define NDPI_LOG_DBG2(a, b, ...)
#define NDPI_EXCLUDE_PROTO(a, b)

void ndpi_set_detected_protocol(struct ndpi_detection_module_struct *ndpi_struct, 
                               struct ndpi_flow_struct *flow,
                               uint16_t proto1, uint16_t proto2);

int8_t check_pkid_and_detect_hmac_size(const uint8_t *payload);