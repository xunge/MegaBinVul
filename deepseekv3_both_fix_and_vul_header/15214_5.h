#include <stdint.h>
#include <stdio.h>

#define NUM_TX_DESC 256
#define MAX_SKB_FRAGS 18
#define ETH_ZLEN 60
#define NPQ 0x40
#define RingEnd (1 << 15)
#define FirstFrag (1 << 29)
#define LastFrag (1 << 30)
#define DescOwn (1 << 31)
#define PCI_DMA_TODEVICE 1
#define TxPoll 0x38

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint64_t dma_addr_t;

struct sk_buff {
    unsigned int len;
    void *data;
    struct skb_shared_info *shinfo;
};

struct skb_shared_info {
    unsigned int nr_frags;
};

struct net_device {
    char *name;
    unsigned long trans_start;
    struct {
        unsigned int tx_dropped;
    } stats;
    void *priv;
};

struct pci_dev {
    // PCI device structure placeholder
};

struct TxDesc {
    u32 opts1;
    u32 opts2;
    u64 addr;
};

struct rtl8169_private {
    struct pci_dev *pci_dev;
    volatile void *mmio_addr;
    struct TxDesc *TxDescArray;
    unsigned int cur_tx;
    struct {
        struct sk_buff *skb;
        unsigned int len;
    } tx_skb[NUM_TX_DESC];
};

#define TX_BUFFS_AVAIL(tp) (NUM_TX_DESC - (tp->cur_tx % NUM_TX_DESC))
#define netdev_priv(dev) ((struct rtl8169_private *)dev->priv)
#define RTL_W8(reg, val8) (*(volatile uint8_t *)((tp)->mmio_addr + (reg)) = (val8))
#define unlikely(x) (x)
#define smp_wmb() __asm__ __volatile__("" ::: "memory")
#define smp_rmb() __asm__ __volatile__("" ::: "memory")
#define wmb() __asm__ __volatile__("" ::: "memory")

#define NETDEV_TX_OK 0
#define NETDEV_TX_BUSY 1
#define KERN_ERR ""

static inline u32 le32_to_cpu(u32 x) { return x; }
static inline u32 cpu_to_le32(u32 x) { return x; }
static inline u64 cpu_to_le64(u64 x) { return x; }

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) { return skb->shinfo; }
static inline unsigned int skb_headlen(struct sk_buff *skb) { return skb->len; }
static inline int skb_padto(struct sk_buff *skb, unsigned int len) { return 0; }
static inline dma_addr_t pci_map_single(struct pci_dev *dev, void *ptr, unsigned int len, int direction) { return 0; }

static inline int netif_msg_drv(struct rtl8169_private *tp) { return 1; }
static inline void netif_stop_queue(struct net_device *dev) {}
static inline void netif_wake_queue(struct net_device *dev) {}

static inline u32 rtl8169_tso_csum(struct sk_buff *skb, struct net_device *dev) { return 0; }
static inline unsigned int rtl8169_xmit_frags(struct rtl8169_private *tp, struct sk_buff *skb, u32 opts1) { return 0; }
static inline u32 rtl8169_tx_vlan_tag(struct rtl8169_private *tp, struct sk_buff *skb) { return 0; }

extern unsigned long jiffies;

#define __iomem volatile
#define printk printf