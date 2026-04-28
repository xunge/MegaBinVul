#include <stdint.h>

#define MQTT_NEW 0x01
#define MQTT_NEXT 0x02
#define MQTT_MORE 1
#define MQTT_ERROR -1
#define MQTT_HANGUP -2
#define MQTT_CONNECT 1
#define MQTT_PUBLISH 3
#define MQTT_PINGREQ 12
#define MQTT_DISCONNECT 14

#define BUF_AVAIL() (conn->buf_len - conn->buf_pos)
#define BUFC() (conn->buf[conn->buf_pos])
#define __FILENAME__ __FILE__

struct mqtt_conn {
    uint8_t *buf;
    int buf_len;
    int buf_pos;
    int buf_frame_end;
    int status;
    int packet_type;
    int packet_length;
    struct {
        int fd;
    } event;
};

void flb_trace(const char *fmt, ...);
void mqtt_handle_connect(struct mqtt_conn *conn);
void mqtt_handle_publish(struct mqtt_conn *conn);
void mqtt_handle_ping(struct mqtt_conn *conn);
void mqtt_packet_drop(struct mqtt_conn *conn);