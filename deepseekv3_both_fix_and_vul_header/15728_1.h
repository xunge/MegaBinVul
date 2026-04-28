#include <stdint.h>

struct device;
struct pci_dev;
struct net_device;

struct ixgbe_adapter {
    struct net_device *netdev;
    struct {
        void *hw_addr;
    } hw;
    unsigned long state;
    void *io_addr;
};

#define __IXGBE_DISABLED 0
#define IXGBE_WUS 0

typedef uint32_t u32;

#define __maybe_unused
#define smp_mb__before_atomic()
#define clear_bit(bit, addr) (*(addr) &= ~(1UL << (bit)))
#define pci_set_master(pdev) 
#define device_wakeup_disable(dev) 
#define rtnl_lock() 
#define rtnl_unlock() 
#define netif_running(dev) 0
#define netif_device_attach(dev) 

static inline struct pci_dev *to_pci_dev(struct device *dev) { return (struct pci_dev *)dev; }
static inline void *pci_get_drvdata(struct pci_dev *pdev) { return 0; }
static inline int ixgbe_reset(struct ixgbe_adapter *adapter) { return 0; }
static inline void IXGBE_WRITE_REG(void *hw, int reg, u32 value) {}
static inline int ixgbe_init_interrupt_scheme(struct ixgbe_adapter *adapter) { return 0; }
static inline int ixgbe_open(struct net_device *netdev) { return 0; }