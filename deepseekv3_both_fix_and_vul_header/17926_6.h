#include <linux/netdevice.h>
#include <linux/if_arp.h>
#include <linux/if_ether.h>
#include <linux/ethtool.h>
#include <linux/wireless.h>

#define HZ 1000
#define TX_TIMEOUT (2 * HZ)
#define ARPHRD_IEEE80211 801
#define IFF_TX_SKB_SHARING (1 << 16)

struct net_device {
    unsigned int priv_flags;
    void *wireless_data;
    const struct iw_handler_def *wireless_handlers;
    unsigned int watchdog_timeo;
    unsigned int tx_queue_len;
    const struct net_device_ops *netdev_ops;
    unsigned short type;
    const struct header_ops *header_ops;
    unsigned int mtu;
};

struct wireless_data {
    struct iw_spy_data *spy_data;
    void *other_data;
};

struct iw_spy_data {
    int dummy;
};

struct net_device_ops {
    void *ndo_init;
    void *ndo_uninit;
    void *ndo_open;
    void *ndo_stop;
};

struct header_ops {
    void *create;
    void *parse;
    void *cache;
};

struct iw_handler_def {
    void *num_standard;
    void *num_private;
};

struct ethtool_ops {
    void *get_settings;
    void *set_settings;
    void *get_drvinfo;
};

struct hostap_interface {
    struct wireless_data wireless_data;
    struct iw_spy_data spy_data;
};

typedef struct {
    int mtu;
} local_info_t;

extern const struct net_device_ops hostap_mgmt_netdev_ops;
extern const struct net_device_ops hostap_master_ops;
extern const struct net_device_ops hostap_netdev_ops;
extern const struct header_ops hostap_80211_ops;
extern const struct iw_handler_def hostap_iw_handler_def;
extern const struct ethtool_ops prism2_ethtool_ops;

enum {
    HOSTAP_INTERFACE_AP,
    HOSTAP_INTERFACE_MASTER
};