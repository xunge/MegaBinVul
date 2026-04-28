#include <stdint.h>
#include <string.h>

#define MQTT_INCOMPLETE 0
#define MQTT_MALFORMED 1
#define MQTT_OK 2

#define MQTT_CMD_CONNACK 2
#define MQTT_CMD_PUBACK 4
#define MQTT_CMD_PUBREC 5
#define MQTT_CMD_PUBREL 6
#define MQTT_CMD_PUBCOMP 7
#define MQTT_CMD_SUBSCRIBE 8
#define MQTT_CMD_SUBACK 9
#define MQTT_CMD_UNSUBSCRIBE 10
#define MQTT_CMD_UNSUBACK 11
#define MQTT_CMD_PUBLISH 3

struct mg_str {
  char *ptr;
  size_t len;
};

struct mg_mqtt_message {
  struct mg_str dgram;
  uint8_t cmd;
  uint8_t qos;
  uint16_t id;
  uint8_t ack;
  struct mg_str topic;
  struct mg_str data;
  size_t props_size;
  size_t props_start;
};