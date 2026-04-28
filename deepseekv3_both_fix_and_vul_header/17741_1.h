#include <stdint.h>
#include <stddef.h>

#define MQTT_HEADER_DUP_MASK 0x08
#define MQTT_HEADER_RETAIN_MASK 0x01
#define MQTT_HEADER_QOS_MASK 0x06
#define MQTT_QOS_0_AT_MOST_ONCE 0
#define EINVAL 22

typedef uint8_t u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;

struct buf_ctx {
    // Placeholder for buffer context
};

struct mqtt_topic {
    uint8_t qos;
    struct {
        const char *topic;
        size_t size;
    } topic;
};

struct mqtt_payload {
    void *data;
    size_t len;
};

struct mqtt_message {
    struct mqtt_topic topic;
    struct mqtt_payload payload;
};

struct mqtt_publish_param {
    uint8_t dup_flag;
    uint8_t retain_flag;
    uint16_t message_id;
    struct mqtt_message message;
};

int unpack_utf8_str(struct buf_ctx *buf, const char **topic);
int unpack_uint16(struct buf_ctx *buf, uint16_t *message_id);