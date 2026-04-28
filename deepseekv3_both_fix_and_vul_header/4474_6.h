#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define DMA_BIT_MASK(n) (((n) == 64) ? ~0ULL : ((1ULL<<(n))-1))
#define ETH_ALEN 6
#define NETIF_F_SG 0x00000001
#define NETIF_F_HW_VLAN_CTAG_RX 0x00000080
#define NETIF_F_HW_VLAN_CTAG_TX 0x00000100
#define HZ 100
#define ENOMEM 12
#define EIO 5
#define KERN_ERR ""

typedef uint32_t u32;
typedef uint8_t u8;

struct pci_dev;
struct pci_device_id;

struct net_device {
    const struct net_device_ops *netdev_ops;
    const struct ethtool_ops *ethtool_ops;
    char name[16];
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned int watchdog_timeo;
    unsigned char dev_addr[ETH_ALEN];
    unsigned char addr_len;
    unsigned int hw_features;
    unsigned int features;
};

struct net_device_ops {
};

struct ethtool_ops {
};

struct atl2_adapter;
struct atl2_hw {
    struct atl2_adapter *back;
    void *hw_addr;
    u32 mem_rang;
    u8 mac_addr[ETH_ALEN];
};

struct timer_list {
    unsigned long data;
    void (*function)(unsigned long);
};

struct work_struct {
    void (*func)(struct work_struct *work);
};

struct atl2_adapter {
    struct net_device *netdev;
    struct pci_dev *pdev;
    struct atl2_hw hw;
    int bd_number;
    bool pci_using_64;
    struct timer_list watchdog_timer;
    struct timer_list phy_config_timer;
    struct work_struct reset_task;
    struct work_struct link_chg_task;
};

static const struct net_device_ops atl2_netdev_ops = {};
static const struct ethtool_ops atl2_ethtool_ops = {};
static char atl2_driver_name[] = "atl2";

static inline int printk(const char *fmt, ...) { return 0; }
static inline void *ioremap(unsigned long phys_addr, unsigned long size) { return NULL; }
static inline void iounmap(void *addr) {}
static inline int pci_enable_device(struct pci_dev *dev) { return 0; }
static inline int pci_set_dma_mask(struct pci_dev *dev, uint64_t mask) { return 0; }
static inline int pci_set_consistent_dma_mask(struct pci_dev *dev, uint64_t mask) { return 0; }
static inline int pci_request_regions(struct pci_dev *dev, const char *name) { return 0; }
static inline void pci_set_master(struct pci_dev *dev) {}
static inline void pci_set_drvdata(struct pci_dev *pdev, void *data) {}
static inline void *pci_get_drvdata(struct pci_dev *pdev) { return NULL; }
static inline void pci_release_regions(struct pci_dev *dev) {}
static inline void pci_disable_device(struct pci_dev *dev) {}
static inline unsigned long pci_resource_start(struct pci_dev *dev, int bar) { return 0; }
static inline unsigned long pci_resource_len(struct pci_dev *dev, int bar) { return 0; }
static inline const char *pci_name(const struct pci_dev *pdev) { return ""; }

static inline struct net_device *alloc_etherdev(int size) { return NULL; }
static inline void free_netdev(struct net_device *dev) {}
static inline void *netdev_priv(const struct net_device *dev) { return NULL; }
static inline int register_netdev(struct net_device *dev) { return 0; }
static inline void netif_carrier_off(struct net_device *dev) {}
static inline void netif_stop_queue(struct net_device *dev) {}
static inline int is_valid_ether_addr(const void *addr) { return 1; }

static inline void setup_timer(struct timer_list *timer,
                             void (*function)(unsigned long),
                             unsigned long data)
{
    timer->function = function;
    timer->data = data;
}

#define INIT_WORK(_work, _func) \
    do { \
        (_work)->func = _func; \
    } while (0)

#define SET_NETDEV_DEV(netdev, pdev) do {} while (0)

static void atl2_setup_pcicmd(struct pci_dev *pdev) {}
static int atl2_sw_init(struct atl2_adapter *adapter) { return 0; }
static void atl2_phy_init(struct atl2_hw *hw) {}
static int atl2_reset_hw(struct atl2_hw *hw) { return 0; }
static void atl2_read_mac_addr(struct atl2_hw *hw) {}
static void atl2_check_options(struct atl2_adapter *adapter) {}
static void atl2_watchdog(unsigned long data) {}
static void atl2_phy_config(unsigned long data) {}
static void atl2_reset_task(struct work_struct *work) {}
static void atl2_link_chg_task(struct work_struct *work) {}