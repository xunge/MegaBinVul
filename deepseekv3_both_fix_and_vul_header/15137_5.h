#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

struct e1000_hw {
    // Hardware specific members
};

struct e1000_rx_desc {
    u32 status;
    u16 length;
    u16 csum;
    u32 errors;
    u16 special;
};

struct e1000_rx_ring {
    unsigned int count;
    unsigned int next_to_clean;
    struct e1000_buffer *buffer_info;
    struct e1000_rx_desc *desc;
};

struct e1000_adapter {
    struct e1000_hw hw;
    struct net_device *netdev;
    struct pci_dev *pdev;
    unsigned long stats_lock;
    struct {
        unsigned long rx_bytes;
        unsigned long rx_packets;
    } net_stats;
    unsigned long total_rx_bytes;
    unsigned long total_rx_packets;
    void (*alloc_rx_buf)(struct e1000_adapter *, struct e1000_rx_ring *, int);
    void *vlgrp;
    void *stats;
};

struct e1000_buffer {
    struct sk_buff *skb;
    uint64_t dma;
    unsigned int length;
};

struct net_device {
    char name[16];
};

struct pci_dev {
    // PCI device members
};

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned char protocol;
};

#define E1000_RXD_STAT_DD      0x01
#define E1000_RXD_STAT_EOP     0x02
#define E1000_RXD_STAT_VP      0x08
#define E1000_RXD_ERR_FRAME_ERR_MASK 0x0002
#define E1000_RX_BUFFER_WRITE 16
#define E1000_DESC_UNUSED(R) 0
#define E1000_RX_DESC(R, i) ((R).desc + (i))
#define E1000_DBG(fmt, ...) 
#define NET_IP_ALIGN 2
#define PCI_DMA_FROMDEVICE 2
#define unlikely(x) (x)

static int copybreak;

static inline bool TBI_ACCEPT(struct e1000_hw *hw, u8 status, u32 errors, u32 length, u8 last_byte) {
    return false;
}

static inline void e1000_tbi_adjust_stats(struct e1000_hw *hw, void *stats, u32 length, u8 *data) {
}

static inline void e1000_rx_checksum(struct e1000_adapter *adapter, u32 status, u16 csum, struct sk_buff *skb) {
}

static inline u16 le16_to_cpu(u16 val) {
    return val;
}

static inline void prefetch(const void *x) {}

static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}

static inline struct sk_buff *netdev_alloc_skb(struct net_device *dev, unsigned int length) { return NULL; }
static inline void skb_reserve(struct sk_buff *skb, int len) {}
static inline void skb_copy_to_linear_data_offset(struct sk_buff *skb, int offset, const void *from, unsigned int len) {}
static inline void skb_put(struct sk_buff *skb, unsigned int len) {}
static inline unsigned char eth_type_trans(struct sk_buff *skb, struct net_device *dev) { return 0; }
static inline void vlan_hwaccel_receive_skb(struct sk_buff *skb, void *vlgrp, u16 vlan_tag) {}
static inline void netif_receive_skb(struct sk_buff *skb) {}
static inline void pci_unmap_single(struct pci_dev *pdev, uint64_t dma, unsigned int length, int direction) {}