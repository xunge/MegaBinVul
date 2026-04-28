#include <stdint.h>
#include <stddef.h>

typedef uint16_t u16;

struct xen_netif_tx_request {
    unsigned int offset;
    unsigned int size;
};

struct xen_netbk {
    struct {
        struct xen_netif_tx_request req;
    } *pending_tx_info;
    struct page **mmap_pages;
};

struct sk_buff {
    unsigned int len;
    unsigned int data_len;
    unsigned int truesize;
};

struct page;

typedef struct {
    unsigned long page;
    unsigned int offset;
    unsigned int size;
} skb_frag_t;

struct skb_shared_info {
    int nr_frags;
    skb_frag_t *frags;
};

#define XEN_NETIF_RSP_OKAY 0

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) { return NULL; }
static inline void *idx_to_kaddr(struct xen_netbk *netbk, u16 pending_idx) { return NULL; }
static inline u16 frag_get_pending_idx(skb_frag_t *frag) { return 0; }
static inline void xen_netbk_idx_release(struct xen_netbk *netbk, u16 pending_idx, ...) {}
static inline void __skb_fill_page_desc(struct sk_buff *skb, int i, struct page *page, unsigned int offset, unsigned int size) {}
static inline void get_page(struct page *page) {}
static inline struct page *virt_to_page(void *addr) { return NULL; }