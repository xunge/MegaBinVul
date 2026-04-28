#include <stdint.h>
#include <errno.h>

#define MQTT_MAX_LENGTH_BYTES 4
#define MQTT_LENGTH_VALUE_MASK 0x7F
#define MQTT_LENGTH_SHIFT 7
#define MQTT_LENGTH_CONTINUATION_BIT 0x80
#define MQTT_MAX_PAYLOAD_SIZE 0xFFFFFFF
#define MQTT_TRC(fmt, ...)

struct buf_ctx {
    uint8_t *cur;
    uint8_t *end;
};

typedef uint8_t u8_t;
typedef uint32_t u32_t;