#include <stdint.h>
#include <stddef.h>

#define MG_INTERNAL
#define MG_MQTT_ERROR_INCOMPLETE_MSG 1
#define MG_MQTT_ERROR_MALFORMED_MSG 2
#define MG_MQTT_GET_QOS(h) (((h) &0x06) >> 1)

#define MG_MQTT_CMD_CONNECT 1
#define MG_MQTT_CMD_CONNACK 2
#define MG_MQTT_CMD_PUBLISH 3
#define MG_MQTT_CMD_PUBACK 4
#define MG_MQTT_CMD_PUBREC 5
#define MG_MQTT_CMD_PUBREL 6
#define MG_MQTT_CMD_PUBCOMP 7
#define MG_MQTT_CMD_SUBSCRIBE 8
#define MG_MQTT_CMD_SUBACK 9
#define MG_MQTT_CMD_UNSUBSCRIBE 10
#define MG_MQTT_CMD_UNSUBACK 11
#define MG_MQTT_CMD_PINGREQ 12
#define MG_MQTT_CMD_PINGRESP 13
#define MG_MQTT_CMD_DISCONNECT 14

#define MG_MQTT_HAS_WILL 0x04
#define MG_MQTT_HAS_USER_NAME 0x80
#define MG_MQTT_HAS_PASSWORD 0x40

#define LL_DEBUG 0
#define LOG(level, fmt)

struct mbuf {
    char *buf;
    size_t len;
};

struct mg_str {
    const char *p;
    size_t len;
};

struct mg_mqtt_message {
    int cmd;
    int qos;
    struct mg_str protocol_name;
    uint8_t protocol_version;
    uint8_t connect_flags;
    uint16_t keep_alive_timer;
    struct mg_str client_id;
    struct mg_str will_topic;
    struct mg_str will_message;
    struct mg_str user_name;
    struct mg_str password;
    uint8_t connack_ret_code;
    uint16_t message_id;
    struct mg_str topic;
    struct mg_str payload;
    size_t len;
};

static inline uint16_t getu16(const void *p) {
    const uint8_t *pp = (const uint8_t *) p;
    return (uint16_t) (((uint16_t) pp[0] << 8) | pp[1]);
}

static const char *scanto(const char *p, struct mg_str *s) {
    uint16_t len = getu16(p);
    s->len = len;
    s->p = p + 2;
    return p + 2 + len;
}