#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct sk_buff {
    unsigned int len;
    int protocol;
    int qindex;
};

struct net_device {
    int dummy;
};

struct napi_struct {
    int dummy;
};

struct gfar_priv_rx_q {
    struct net_device *ndev;
    struct sk_buff *skb;
    struct rxbd8 *rx_bd_base;
    int next_to_clean;
    int rx_ring_size;
    int qindex;
    struct {
        unsigned long rx_packets;
        unsigned long rx_bytes;
        unsigned long rx_dropped;
    } stats;
    struct gfar_group *grp;
    void *rfbptr;
};

struct gfar_private {
    int tx_actual_en;
};

struct rxbd8 {
    u32 lstatus;
};

struct gfar_group {
    struct napi_struct napi_rx;
};

#define GFAR_RX_BUFF_ALLOC 256
#define BD_LFLAG(flag) (1 << (flag))
#define RXBD_EMPTY 0
#define RXBD_FIRST 1
#define RXBD_LAST 2
#define RXBD_ERR 3
#define likely(x) (x)
#define unlikely(x) (x)

static inline u32 be32_to_cpu(u32 x) { return x; }
static inline void rmb(void) {}
static inline void dev_kfree_skb(struct sk_buff *skb) {}
static inline void skb_record_rx_queue(struct sk_buff *skb, int qindex) {}
static inline int eth_type_trans(struct sk_buff *skb, struct net_device *ndev) { return 0; }
static inline void napi_gro_receive(struct napi_struct *napi, struct sk_buff *skb) {}

static inline int gfar_rxbd_unused(struct gfar_priv_rx_q *rx_queue) { return 0; }
static inline void gfar_alloc_rx_buffs(struct gfar_priv_rx_q *rx_queue, int cnt) {}
static inline void gfar_write(void *reg, u32 val) {}
static inline u32 gfar_rxbd_dma_lastfree(struct gfar_priv_rx_q *rx_queue) { return 0; }
static inline void count_errors(u32 lstatus, struct net_device *ndev) {}
static inline void gfar_process_frame(struct net_device *ndev, struct sk_buff *skb) {}
static inline struct sk_buff *gfar_get_next_rxbuff(struct gfar_priv_rx_q *rx_queue, u32 lstatus, struct sk_buff *skb) { return skb; }
static inline struct gfar_private *netdev_priv(struct net_device *dev) { return (struct gfar_private *)dev; }