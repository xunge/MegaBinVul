#include <stdint.h>

typedef uint16_t u16;

struct net_device {
    unsigned int real_num_tx_queues;
};

struct sk_buff {
    u16 queue_mapping;
};

static inline int skb_rx_queue_recorded(const struct sk_buff *skb) { return 0; }
static inline u16 skb_get_rx_queue(const struct sk_buff *skb) { return 0; }
#define unlikely(x) (x)