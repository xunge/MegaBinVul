#include <linux/netdevice.h>
#include <linux/wireless.h>
#include <linux/errno.h>

struct hermes_t {
    int dummy;
};

struct orinoco_private {
    struct hermes_t hw;
    int key_mgmt;
    int tkip_cm_active;
    int wep_restrict;
    int has_wpa;
    int wpa_enabled;
};

struct net_device;
struct iw_request_info;
union iwreq_data;

static inline struct orinoco_private *ndev_priv(struct net_device *dev)
{
    extern void *netdev_priv(const struct net_device *dev);
    return (struct orinoco_private *)netdev_priv(dev);
}

static inline int orinoco_lock(struct orinoco_private *priv, unsigned long *flags)
{
    return 0;
}

static inline void orinoco_unlock(struct orinoco_private *priv, unsigned long *flags)
{
}

static inline int hermes_enable_port(struct hermes_t *hw, int port)
{
    return 0;
}

static inline int hermes_disable_port(struct hermes_t *hw, int port)
{
    return 0;
}

typedef struct hermes_t hermes_t;