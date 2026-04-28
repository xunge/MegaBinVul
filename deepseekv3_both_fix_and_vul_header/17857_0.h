#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define NDPI_MAX_PARSE_LINES_PER_PACKET 16
#define NDPI_STATICSTRING_LEN(s) (sizeof(s)-1)

struct ndpi_packet_struct {
    uint8_t *payload;
    uint16_t payload_packet_len;
    uint8_t packet_lines_parsed_complete;
    unsigned int parsed_lines;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } line[NDPI_MAX_PARSE_LINES_PER_PACKET];
    struct {
        uint8_t *ptr;
        uint16_t len;
    } http_response;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } server_line;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } host_line;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } forwarded_line;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } content_line;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } accept_line;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } referer_line;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } user_agent_line;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } http_encoding;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } http_transfer_encoding;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } http_contentlen;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } content_disposition_line;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } http_cookie;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } http_origin;
    struct {
        uint8_t *ptr;
        uint16_t len;
    } http_x_session_type;
    uint16_t http_num_headers;
    uint32_t empty_line_position;
    uint8_t empty_line_position_set;
};

struct ndpi_flow_struct {
    struct ndpi_packet_struct packet;
    struct {
        uint16_t response_status_code;
    } http;
    uint8_t initial_binary_bytes[8];
    uint16_t initial_binary_bytes_len;
};

struct ndpi_detection_module_struct {
    // Placeholder for detection module structure
};

static inline uint16_t get_u_int16_t(const uint8_t *p, uint32_t idx) {
    return ntohs(*(uint16_t*)&p[idx]);
}

static inline int ndpi_min(int a, int b) {
    return a < b ? a : b;
}

void ndpi_reset_packet_line_info(struct ndpi_packet_struct *packet);