#include <stddef.h>
#include <net/if.h>
#include <sys/types.h>

#define IFF_TX_SKB_SHARING 0x10000
#define HZ 100

#define ISDN_NET_ENCAP_RAWIP 1
#define ISDN_NET_MAGIC 0x4944534E
#define ISDN_PROTO_L2_X75I 1
#define ISDN_PROTO_L3_TRANS 2
#define ISDN_INHUP 1
#define ISDN_NET_CBHUP 0x01
#define ISDN_NET_DM_MANUAL 0x02

struct net_device {
    unsigned int flags;
    unsigned int priv_flags;
    void *header_ops;
    const struct net_device_ops *netdev_ops;
    unsigned int tx_queue_len;
};

struct sk_buff_head {
    int dummy;
};

struct net_device_ops;
extern const struct net_device_ops isdn_netdev_ops;

typedef struct isdn_net_local {
    int p_encap;
    unsigned long magic;
    struct isdn_net_local *last;
    struct isdn_net_local *next;
    int isdn_device;
    int isdn_channel;
    int pre_device;
    int pre_channel;
    int exclusive;
    int ppp_slot;
    int pppbind;
    struct sk_buff_head super_tx_queue;
    int l2_proto;
    int l3_proto;
    int triggercps;
    unsigned long slavedelay;
    int hupflags;
    int onhtime;
    int dialmax;
    unsigned int flags;
    int cbdelay;
    int dialtimeout;
    unsigned long dialwait;
    int dialstarted;
    unsigned long dialwait_timer;
} isdn_net_local;

static inline isdn_net_local *netdev_priv(struct net_device *dev) { return (isdn_net_local *)0; }
static inline void ether_setup(struct net_device *dev) {}
static inline void skb_queue_head_init(struct sk_buff_head *list) {}