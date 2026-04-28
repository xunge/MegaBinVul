#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CMD_CONNECT 0x10
#define PROTOCOL_ERROR -1
#define SUCCESS 0
#define PAYLOAD_FORMAT_INVALID -2
#define MQTT_PROTOCOL_VERSION_v5 5
#define ASSIGNED_CLIENT_IDENTIFIER 18

typedef struct {
    char *body;
    int len;
} utf8_str;

typedef struct property property;

typedef struct {
    utf8_str pro_name;
    uint8_t pro_ver;
    uint8_t con_flag;
    uint8_t clean_start;
    uint8_t will_flag;
    uint8_t will_qos;
    uint8_t will_retain;
    uint16_t keepalive_mqtt;
    uint32_t prop_len;
    property *properties;
    utf8_str clientid;
    bool assignedid;
    property *will_properties;
    uint32_t will_prop_len;
    utf8_str will_topic;
    utf8_str will_msg;
    uint8_t payload_format_indicator;
    utf8_str username;
    utf8_str password;
} conn_param;

extern uint32_t get_var_integer(uint8_t *packet, size_t *len_of_var);
extern char *copyn_utf8_str(uint8_t *packet, uint32_t *pos, int *len_of_str, size_t max);
extern char *copyn_str(uint8_t *packet, uint32_t *pos, int *len_of_str, size_t max);
extern void NNI_GET16(uint8_t *packet, uint32_t *tmp);
extern property *decode_buf_properties(uint8_t *packet, uint32_t len, uint32_t *pos, uint32_t *prop_len, bool b);
extern void conn_param_set_property(conn_param *cparam, property *properties);
extern int check_properties(property *properties);
extern property *property_set_value_str(int type, char *body, int len, bool b);
extern property *property_alloc();
extern void property_append(property *properties, property *assigned_cid);
extern void conn_param_set_will_property(conn_param *cparam, property *will_properties);
extern uint32_t nni_random();
extern char *nng_strdup(char *str);
extern void log_trace(const char *fmt, ...);
extern void log_debug(const char *fmt, ...);
extern void log_warn(const char *fmt, ...);
extern void log_error(const char *fmt, ...);