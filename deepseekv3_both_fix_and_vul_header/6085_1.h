#include <stdlib.h>
#include <stdbool.h>

struct hso_device;
struct hso_net;

#define MUX_BULK_RX_BUF_COUNT 4

struct hso_net {
    void *net;
    struct hso_device *parent;
    void *mux_bulk_rx_urb_pool[MUX_BULK_RX_BUF_COUNT];
    unsigned char *mux_bulk_rx_buf_pool[MUX_BULK_RX_BUF_COUNT];
    void *mux_bulk_tx_urb;
    unsigned char *mux_bulk_tx_buf;
};

static inline struct hso_net *dev2net(struct hso_device *hso_dev)
{
    return (struct hso_net *)hso_dev;
}