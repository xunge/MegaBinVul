#include <stdint.h>
#include <string.h>

#define NUM_RX_DESC 256
#define DescOwn (1 << 31)
#define RxRES (1 << 15)
#define RxRWT (1 << 14)
#define RxRUNT (1 << 13)
#define RxCRC (1 << 5)
#define RxFOVF (1 << 4)
#define RTL_GIGA_MAC_VER_05 5
#define KERN_INFO ""
#define KERN_EMERG ""
#define unlikely(x) (x)
#define PCI_DMA_FROMDEVICE 2

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint64_t dma_addr_t;

struct net_device {
    char name[16];
    struct {
        unsigned long rx_errors;
        unsigned long rx_length_errors;
        unsigned long rx_crc_errors;
        unsigned long rx_fifo_errors;
        unsigned long rx_dropped;
        unsigned long rx_bytes;
        unsigned long rx_packets;
    } stats;
    unsigned long last_rx;
};

struct pci_dev;
struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned int protocol;
};

struct rtl8169_private {
    unsigned int cur_rx;
    unsigned int dirty_rx;
    unsigned int rx_buf_sz;
    struct RxDesc *RxDescArray;
    struct sk_buff **Rx_skbuff;
    struct pci_dev *pci_dev;
    int mac_version;
};

struct RxDesc {
    u32 opts1;
    u32 opts2;
    u64 addr;
};

static inline u32 le32_to_cpu(u32 val) { return val; }
static inline u64 le64_to_cpu(u64 val) { return val; }
static inline u32 cpu_to_le32(u32 val) { return val; }

static void rmb(void) {}
static int netif_msg_rx_err(struct rtl8169_private *tp) { return 0; }
static int netif_msg_intr(struct rtl8169_private *tp) { return 0; }
static void rtl8169_schedule_work(struct net_device *dev, void *task) {}
static void rtl8169_mark_to_asic(struct RxDesc *desc, unsigned int size) {}
static int rtl8169_fragmented_frame(u32 status) { return 0; }
static void rtl8169_rx_csum(struct sk_buff *skb, struct RxDesc *desc) {}
static int rtl8169_try_rx_copy(struct sk_buff **skb, struct rtl8169_private *tp, int size, dma_addr_t addr) { return 0; }
static int rtl8169_rx_vlan_skb(struct rtl8169_private *tp, struct RxDesc *desc, struct sk_buff *skb) { return 0; }
static unsigned int rtl8169_rx_fill(struct rtl8169_private *tp, struct net_device *dev, unsigned int dirty_rx, unsigned int cur_rx) { return 0; }
static unsigned long jiffies;
static void *rtl8169_reset_task;
static void pci_dma_sync_single_for_device(struct pci_dev *pdev, dma_addr_t addr, int size, int dir) {}
static void pci_unmap_single(struct pci_dev *pdev, dma_addr_t addr, int size, int dir) {}
static void netif_receive_skb(struct sk_buff *skb) {}
static unsigned int eth_type_trans(struct sk_buff *skb, struct net_device *dev) { return 0; }
static void skb_put(struct sk_buff *skb, unsigned int len) {}
static int printk(const char *fmt, ...) { return 0; }

#define __iomem