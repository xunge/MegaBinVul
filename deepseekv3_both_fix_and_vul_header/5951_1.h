struct net_device;

struct napi_struct {
    struct net_device *dev;
    void *skb;
};

struct sk_buff {
    unsigned int len;
    void *head;
    void *data;
    void *tail;
    void *end;
    unsigned short vlan_tci;
    struct net_device *dev;
    int skb_iif;
    unsigned int headroom;
};

#define NET_IP_ALIGN 2

static inline void __skb_pull(struct sk_buff *skb, unsigned int len) {}
static inline void skb_reserve(struct sk_buff *skb, int len) {}
static inline unsigned int skb_headlen(const struct sk_buff *skb) { return 0; }
static inline unsigned int skb_headroom(const struct sk_buff *skb) { return 0; }