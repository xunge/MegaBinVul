#include <stdint.h>
#include <stddef.h>

struct mg_str {
  char *ptr;
  size_t len;
};

struct mg_mqtt_prop {
  uint8_t id;
  union {
    uint32_t iv;
    struct mg_str val;
    struct {
      struct mg_str key;
      struct mg_str val2;
    };
  };
};

struct mg_mqtt_message {
  struct mg_str dgram;
  size_t props_start;
  size_t props_size;
};

enum mqtt_prop_type {
  MQTT_PROP_TYPE_BYTE,
  MQTT_PROP_TYPE_SHORT,
  MQTT_PROP_TYPE_INT,
  MQTT_PROP_TYPE_STRING,
  MQTT_PROP_TYPE_BINARY_DATA,
  MQTT_PROP_TYPE_STRING_PAIR,
  MQTT_PROP_TYPE_VARIABLE_INT
};

enum mqtt_prop_type mqtt_prop_type_by_id(uint8_t id);
uint32_t decode_variable_length(char *buf, uint32_t *bytes_consumed);