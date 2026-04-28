struct sk_buff {
    unsigned char *head;
    unsigned char *data;
    unsigned char *tail;
    unsigned char *end;
    unsigned int len;
    unsigned int data_len;
    unsigned short vlan_tci;
    void *dev;
};

struct napi_struct {
    void *dev;
    struct sk_buff *skb;
};

#define NET_IP_ALIGN 2

static inline void __skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->len -= len;
    skb->data += len;
}

static inline unsigned int skb_headlen(const struct sk_buff *skb) {
    return skb->len - skb->data_len;
}

static inline void skb_reserve(struct sk_buff *skb, int len) {
    skb->data += len;
    skb->tail += len;
}

static inline unsigned int skb_headroom(const struct sk_buff *skb) {
    return skb->data - skb->head;
}