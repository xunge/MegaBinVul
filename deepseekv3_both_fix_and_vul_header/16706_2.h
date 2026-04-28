#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define BD_LENGTH_MASK 0xFFFF
#define RXBD_LAST 0x01
#define RXBUF_ALIGNMENT 2
#define GFAR_RXB_TRUESIZE 2048

struct page {
    // minimal page struct definition
    unsigned long flags;
};

struct sk_buff {
    unsigned int len;
    // other minimal sk_buff fields
};

struct skb_shared_info {
    unsigned short nr_frags;
    // other minimal skb_shared_info fields
};

struct gfar_rx_buff {
    struct page *page;
    uint32_t page_offset;
};

typedef uint32_t u32;

#define BD_LFLAG(x) (x)
#define likely(x) (x)
#define unlikely(x) (x)

static inline void skb_put(struct sk_buff *skb, int len) { skb->len += len; }
static inline struct skb_shared_info *skb_shinfo(const struct sk_buff *skb) { return (struct skb_shared_info *)(skb + 1); }
static inline void skb_add_rx_frag(struct sk_buff *skb, int i, struct page *page, int off, int size, int truesize) {}
static inline int page_count(struct page *page) { return 1; }
static inline bool page_is_pfmemalloc(struct page *page) { return false; }
static inline void page_ref_inc(struct page *page) {}