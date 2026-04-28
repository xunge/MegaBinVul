#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define CRSF_HEADER 0x00
#define PACKET_SIZE_TYPE_SIZE 2
#define HEADER_SIZE 1
#define CRC_SIZE 1
#define PACKET_SIZE_SIZE 1
#define CRSF_MAX_PACKET_LEN 64

enum CRSF_PACKET_TYPE {
    CRSF_PACKET_TYPE_UNKNOWN = 0
};

typedef struct {
    uint8_t packet_size;
    bool (*processor)(const uint8_t *data, uint32_t length, void *packet);
} CrsfPacketDescriptor_t;

typedef struct {
    uint32_t disposed_bytes;
    uint32_t invalid_known_packet_sizes;
    uint32_t invalid_unknown_packet_sizes;
    uint32_t crcs_valid_known_packets;
    uint32_t crcs_valid_unknown_packets;
    uint32_t crcs_invalid;
} CrsfParserStatistics_t;

typedef struct {
    // Add packet fields as needed
} CrsfPacket_t;

typedef struct {
    // Add queue buffer fields as needed
} QueueBuffer_t;

extern QueueBuffer_t rx_queue;
extern CrsfPacketDescriptor_t *FindCrsfDescriptor(enum CRSF_PACKET_TYPE type);
extern uint8_t Crc8Calc(const uint8_t *data, uint32_t length);
extern uint32_t QueueBuffer_Count(QueueBuffer_t *queue);
extern bool QueueBuffer_Get(QueueBuffer_t *queue, uint8_t *byte);
extern bool QueueBuffer_Peek(QueueBuffer_t *queue, uint32_t index, uint8_t *byte);
extern bool QueueBuffer_PeekBuffer(QueueBuffer_t *queue, uint32_t index, uint8_t *buffer, uint32_t length);
extern void QueueBuffer_Dequeue(QueueBuffer_t *queue, uint32_t length);

static uint32_t working_index = 0;
static uint32_t working_segment_size = HEADER_SIZE;
static CrsfPacketDescriptor_t *working_descriptor = NULL;
static uint8_t process_buffer[CRSF_MAX_PACKET_LEN];
static enum {
    PARSER_STATE_HEADER,
    PARSER_STATE_SIZE_TYPE,
    PARSER_STATE_PAYLOAD,
    PARSER_STATE_CRC
} parser_state = PARSER_STATE_HEADER;