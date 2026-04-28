#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define CMD_CONNECT 1
#define PROTOCOL_ERROR 1
#define MQTT_PROTOCOL_VERSION_v5 5
#define SUCCESS 0
#define PAYLOAD_FORMAT_INVALID 2
#define ASSIGNED_CLIENT_IDENTIFIER 1

typedef struct {
    char *body;
    int len;
} str_buf;

typedef struct conn_param {
    str_buf pro_name;
    uint8_t pro_ver;
    uint8_t con_flag;
    uint8_t clean_start;
    uint8_t will_flag;
    uint8_t will_qos;
    uint8_t will_retain;
    uint16_t keepalive_mqtt;
    void *properties;
    size_t prop_len;
    str_buf clientid;
    bool assignedid;
    void *will_properties;
    size_t will_prop_len;
    str_buf will_topic;
    str_buf will_msg;
    uint8_t payload_format_indicator;
    str_buf username;
    str_buf password;
} conn_param;

typedef struct property {
    // property structure definition
} property;

extern uint32_t get_var_integer(uint8_t *packet, int *len_of_var);
extern char *copyn_utf8_str(uint8_t *packet, uint32_t *pos, int *len_of_str, size_t max);
extern char *copyn_str(uint8_t *packet, uint32_t *pos, int *len_of_str, size_t max);
extern void log_trace(const char *format, ...);
extern void log_error(const char *format, ...);
extern char *nng_strdup(const char *str);
extern uint32_t nni_random();
extern void *decode_buf_properties(uint8_t *packet, uint32_t len, uint32_t *pos, size_t *prop_len, bool flag);
extern void conn_param_set_property(conn_param *cparam, void *properties);
extern int check_properties(void *properties);
extern property *property_set_value_str(int type, char *body, int len, bool flag);
extern void *property_alloc();
extern void property_append(void *properties, property *prop);
extern void conn_param_set_will_property(conn_param *cparam, void *properties);

#define NNI_GET16(p, v) \
    do { \
        v = ((uint16_t)((p)[0]) << 8) | (p)[1]; \
    } while (0)