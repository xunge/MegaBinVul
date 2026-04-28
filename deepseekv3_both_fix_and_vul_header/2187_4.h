#include <linux/types.h>
#include <linux/netdevice.h>
#include <linux/ethtool.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <stddef.h>

typedef __u32 u32;

#define EFX_MAX_DMAQ_SIZE 0
#define EFX_RXQ_MIN_ENT 0
#define EFX_TXQ_MIN_ENT(x) 0
#define EFX_MIN_RING_SIZE 0

struct efx_nic {
    struct net_device *net_dev;
};

enum {
    drv
};

static inline struct efx_nic *netdev_priv(struct net_device *dev) { return NULL; }
static inline void netif_err(const struct efx_nic *efx, int level, const struct net_device *dev, const char *fmt, ...) {}
static inline void netif_warn(const struct efx_nic *efx, int level, const struct net_device *dev, const char *fmt, ...) {}
static inline int efx_realloc_channels(struct efx_nic *efx, unsigned int rx_pending, unsigned int tx_pending) { return 0; }