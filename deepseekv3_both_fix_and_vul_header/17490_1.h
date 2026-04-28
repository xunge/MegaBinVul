#include <stdint.h>

#define ENOMEM 12
#define EINVAL 22
#define GFP_ATOMIC 0
#define CHECKSUM_NONE 0

struct sk_buff {
    unsigned int data_len;
    unsigned int len;
    uint8_t *data;
    uint8_t ip_summed;
    uint8_t *head;
    uint8_t *end;
    uint8_t *tail;
};

struct nf_queue_entry {
    struct sk_buff *skb;
};

static int pskb_trim(struct sk_buff *skb, unsigned int len) { return 0; }
static unsigned int skb_tailroom(const struct sk_buff *skb) { return 0; }
static unsigned int skb_headroom(const struct sk_buff *skb) { return 0; }
static struct sk_buff *skb_copy_expand(const struct sk_buff *skb, int newheadroom, int newtailroom, int gfp_mask) { return 0; }
static void kfree_skb(struct sk_buff *skb) {}
static void skb_put(struct sk_buff *skb, unsigned int len) {}
static int skb_ensure_writable(struct sk_buff *skb, unsigned int len) { return 0; }
static void skb_copy_to_linear_data(struct sk_buff *skb, const void *from, unsigned int len) {}