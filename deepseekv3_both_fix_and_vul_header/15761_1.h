#include <stdlib.h>
#include <stdbool.h>

struct net_device;

struct efx_rx_queue {
    int core_index;
};

struct efx_tx_queue {
    unsigned int queue;
    unsigned int label;
};

struct efx_channel {
    unsigned int channel;
    struct efx_rx_queue rx_queue;
};

struct efx_nic {
    unsigned int n_channels;
    unsigned int n_tx_channels;
    unsigned int n_rx_channels;
    unsigned int tx_channel_offset;
    unsigned int xdp_tx_queue_count;
    struct efx_tx_queue **xdp_tx_queues;
    struct net_device *net_dev;
};

#define EFX_WARN_ON_PARANOID(cond) 
#define GFP_KERNEL 0
#define ENOMEM 12
#define drv 0
#define EFX_MAX_TXQ_PER_CHANNEL 4

extern bool efx_separate_tx_channels;

static inline void netif_dbg(const struct efx_nic *efx, int type, const struct net_device *dev, const char *fmt, ...) {}

static inline bool efx_channel_is_xdp_tx(struct efx_channel *channel) { return false; }

#define efx_for_each_channel(channel, efx) \
    for ((channel) = NULL; (channel) != (struct efx_channel *)((efx)->n_channels); (channel)++)

#define efx_for_each_channel_tx_queue(tx_queue, channel) \
    for ((tx_queue) = NULL; (tx_queue) != (struct efx_tx_queue *)(EFX_MAX_TXQ_PER_CHANNEL); (tx_queue)++)

int netif_set_real_num_tx_queues(struct net_device *dev, unsigned int num);
int netif_set_real_num_rx_queues(struct net_device *dev, unsigned int num);