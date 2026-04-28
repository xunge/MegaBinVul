#define NET_RX_DROP 0
#define PACKET_HOST 0
#define IFF_UP 0x1

struct net_device {
    unsigned int flags;
    unsigned int mtu;
    unsigned int hard_header_len;
};

struct sk_buff {
    unsigned int len;
    struct {
        long long tv64;
    } tstamp;
    unsigned char pkt_type;
    unsigned short protocol;
    struct net_device *dev;
};

int skb_orphan(struct sk_buff *skb);
void skb_set_dev(struct sk_buff *skb, struct net_device *dev);
unsigned short eth_type_trans(struct sk_buff *skb, struct net_device *dev);
int netif_rx(struct sk_buff *skb);