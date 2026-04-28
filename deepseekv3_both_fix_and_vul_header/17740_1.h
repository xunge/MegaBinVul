#include <stdint.h>
#include <errno.h>
#include <stddef.h>
#include <stdbool.h>

struct mqtt_client;
struct buf_ctx;

struct mqtt_client_internal {
    size_t rx_buf_datalen;
};

struct mqtt_client {
    uint8_t *rx_buf;
    size_t rx_buf_size;
    struct mqtt_client_internal internal;
};

struct buf_ctx {
    uint8_t *cur;
    uint8_t *end;
};

#define MQTT_ERR(fmt, ...)
#define MQTT_TRC(fmt, ...)

typedef uint32_t u32_t;
int mqtt_transport_read(struct mqtt_client *client, uint8_t *buf, size_t len, bool flag);