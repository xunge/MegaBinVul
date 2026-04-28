#include <stdint.h>
#include <string.h>

#define LOG_WARN(fmt, ...)
#define BLE_L2CAP_NODE_MTU 128

typedef struct {
    uint16_t sdu_length;
    uint16_t current_index;
    uint8_t sdu[BLE_L2CAP_NODE_MTU];
} l2cap_rx_buffer_t;

typedef struct {
    l2cap_rx_buffer_t rx_buffer;
} l2cap_channel_t;

typedef struct {
    void (*input)(void);
} netstack_network_t;

extern netstack_network_t NETSTACK_NETWORK;

void *packetbuf_dataptr(void);
void packetbuf_set_datalen(uint16_t len);