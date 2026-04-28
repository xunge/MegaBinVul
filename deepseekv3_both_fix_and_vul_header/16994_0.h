#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum mqtt_property {
    MQTT_PROP_CONTENT_TYPE,
    MQTT_PROP_CORRELATION_DATA,
    MQTT_PROP_PAYLOAD_FORMAT_INDICATOR,
    MQTT_PROP_RESPONSE_TOPIC,
    MQTT_PROP_USER_PROPERTY,
    MQTT_PROP_TOPIC_ALIAS,
    MQTT_PROP_MESSAGE_EXPIRY_INTERVAL,
    MQTT_PROP_SUBSCRIPTION_IDENTIFIER
};

enum mosquitto_client_state {
    mosq_cs_active
};

enum mosquitto_protocol {
    mosq_p_mqtt5
};

enum mosquitto_msg_direction {
    mosq_md_in
};

enum mosquitto_msg_origin {
    mosq_mo_client
};

enum mqtt_reason_code {
    MQTT_RC_PACKET_TOO_LARGE,
    MQTT_RC_NOT_AUTHORIZED,
    MQTT_RC_IMPLEMENTATION_SPECIFIC,
    MQTT_RC_QUOTA_EXCEEDED,
    MQTT_RC_NO_MATCHING_SUBSCRIBERS
};

enum mosquitto_acl_access {
    MOSQ_ACL_WRITE
};

enum mosquitto_cmd {
    CMD_PUBLISH
};

enum mosquitto_log_level {
    MOSQ_LOG_INFO,
    MOSQ_LOG_DEBUG,
    MOSQ_LOG_WARNING
};

struct mosquitto_packet {
    uint8_t command;
    uint32_t remaining_length;
    size_t pos;
};

struct mosquitto_listener {
    char *mount_point;
    uint16_t max_topic_alias;
};

struct mosquitto_property {
    enum mqtt_property identifier;
    union {
        int16_t i16;
        int32_t i32;
    } value;
    struct mosquitto_property *next;
};

struct mosquitto_msg_store {
    char *topic;
    void *payload;
    size_t payloadlen;
    int qos;
    bool retain;
    uint16_t source_mid;
    struct mosquitto_property *properties;
};

struct mosquitto_client_msg {
    struct mosquitto_msg_store *store;
    uint8_t dup;
};

struct mosquitto {
    struct mosquitto_packet in_packet;
    enum mosquitto_client_state state;
    char *id;
    int max_qos;
    enum mosquitto_protocol protocol;
    struct mosquitto_listener *listener;
    void *msgs_in;
    size_t out_packet_count;
};

#define MOSQ_ERR_SUCCESS 0
#define MOSQ_ERR_PROTOCOL 1
#define MOSQ_ERR_NOMEM 2
#define MOSQ_ERR_MALFORMED_PACKET 3
#define MOSQ_ERR_QOS_NOT_SUPPORTED 4
#define MOSQ_ERR_RETAIN_NOT_SUPPORTED 5
#define MOSQ_ERR_TOPIC_ALIAS_INVALID 6
#define MOSQ_ERR_ACL_DENIED 7
#define MOSQ_ERR_NO_SUBSCRIBERS 8

#define G_PUB_BYTES_RECEIVED_INC(x)
#define WITH_BRIDGE
#define WITH_CONTROL

struct {
    struct {
        bool retain_available;
        size_t message_size_limit;
        size_t max_queued_messages;
    } *config;
} db;

typedef struct mosquitto_property mosquitto_property;

void *mosquitto__calloc(size_t nmemb, size_t size);
void *mosquitto__malloc(size_t size);
void mosquitto__free(void *ptr);
void db__msg_store_free(struct mosquitto_msg_store *msg);
int db__message_store(struct mosquitto *context, struct mosquitto_msg_store *msg, uint32_t message_expiry_interval, int store_dup, enum mosquitto_msg_origin origin);
void db__message_remove_incoming(struct mosquitto *context, uint16_t mid);
int db__message_store_find(struct mosquitto *context, uint16_t mid, struct mosquitto_msg_store **stored);
int db__ready_for_flight(struct mosquitto *context, enum mosquitto_msg_direction direction, int qos);
int db__ready_for_queue(struct mosquitto *context, int qos, void *queue);
int db__message_insert(struct mosquitto *context, uint16_t mid, enum mosquitto_msg_direction direction, int qos, bool retain, struct mosquitto_msg_store *store, mosquitto_property *properties, bool update);
void db__message_write_queued_in(struct mosquitto *context);
int packet__read_string(struct mosquitto_packet *packet, char **str, uint16_t *len);
int packet__read_uint16(struct mosquitto_packet *packet, uint16_t *word);
int packet__read_bytes(struct mosquitto_packet *packet, void *bytes, uint32_t count);
int property__read_all(enum mosquitto_cmd command, struct mosquitto_packet *packet, mosquitto_property **properties);
void mosquitto_property_free_all(mosquitto_property **properties);
int alias__add(struct mosquitto *context, const char *topic, uint16_t alias);
int alias__find(struct mosquitto *context, char **topic, uint16_t alias);
int bridge__remap_topic_in(struct mosquitto *context, char **topic);
int control__process(struct mosquitto *context, struct mosquitto_msg_store *msg);
int plugin__handle_message(struct mosquitto *context, struct mosquitto_msg_store *msg);
int sub__messages_queue(const char *id, const char *topic, int qos, bool retain, struct mosquitto_msg_store **store);
void util__decrement_receive_quota(struct mosquitto *context);
int send__puback(struct mosquitto *context, uint16_t mid, uint8_t reason_code, mosquitto_property *properties);
int send__pubrec(struct mosquitto *context, uint16_t mid, uint8_t reason_code, mosquitto_property *properties);
void log__printf(void *log_context, int level, const char *fmt, ...);
int mosquitto_pub_topic_check(const char *topic);
int mosquitto_acl_check(struct mosquitto *context, const char *topic, size_t payloadlen, void *payload, int qos, bool retain, enum mosquitto_acl_access access);