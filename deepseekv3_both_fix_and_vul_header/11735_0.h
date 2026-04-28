#include <stdint.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define DBG(fmt, ...)

struct mqtt_packet {
    uint32_t byte_counter;
    uint16_t topic_len;
    uint8_t topic_len_received;
    uint8_t topic_received;
    uint16_t topic_pos;
    uint32_t remaining_length;
};

struct mqtt_publish_msg {
    char topic[256];
    uint32_t payload_length;
    uint32_t payload_left;
    uint8_t first_chunk;
};

struct mqtt_connection {
    struct mqtt_packet in_packet;
    struct mqtt_publish_msg in_publish_msg;
};