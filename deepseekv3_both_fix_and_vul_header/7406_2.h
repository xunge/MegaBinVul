#include <stdint.h>
#include <stdlib.h>

#define SR_RX_OVERHEAD 4
#define ETH_FRAME_LEN 1514

struct usbnet {
    void *net;
};

struct sk_buff {
    unsigned int len;
    unsigned char *data;
    unsigned int truesize;
};

#define unlikely(x) (x)
#define GFP_ATOMIC 0
#define netdev_err(dev, format, ...) 

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
    skb->len -= len;
}

static inline void skb_set_tail_pointer(struct sk_buff *skb, int len) {}

static inline struct sk_buff *skb_clone(struct sk_buff *skb, int priority) {
    struct sk_buff *new_skb = malloc(sizeof(struct sk_buff));
    if (!new_skb) return NULL;
    *new_skb = *skb;
    return new_skb;
}

static inline void usbnet_skb_return(struct usbnet *dev, struct sk_buff *skb) {
    free(skb);
}