#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define L1_CACHE_BYTES 64
#define ESP_SKB_FRAG_MAXSIZE 65536
#define MAX_SKB_FRAGS 16
#define GFP_ATOMIC 0

typedef uint8_t u8;

typedef struct {
    int locked;
} spinlock_t;

struct page_frag {
    void *page;
    unsigned int offset;
};

struct xfrm_state {
    void *encap;
    spinlock_t lock;
    struct page_frag xfrag;
};

struct sk_buff {
    unsigned int data_len;
    unsigned int len;
    unsigned int truesize;
    void *sk;
    unsigned char *transport_header;
};

struct esp_info {
    int tailen;
    int tfclen;
    int plen;
    int proto;
    bool inplace;
    void *esph;
};

struct ip_esp_hdr {};
struct sock {
    int sk_wmem_alloc;
};
struct page {};

typedef struct {
    int nr_frags;
} skb_shared_info;

static inline skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return (skb_shared_info *)(skb + 1);
}

static inline bool skb_cloned(struct sk_buff *skb) { return false; }
static inline bool skb_has_frag_list(struct sk_buff *skb) { return false; }
static inline void *skb_tail_pointer(struct sk_buff *skb) { return NULL; }
static inline int skb_tailroom(struct sk_buff *skb) { return 0; }
static inline bool sk_fullsock(void *sk) { return false; }
static inline void spin_lock_bh(spinlock_t *lock) { lock->locked = 1; }
static inline void spin_unlock_bh(spinlock_t *lock) { lock->locked = 0; }
static inline bool skb_page_frag_refill(unsigned int size, struct page_frag *pfrag, int gfp) { return false; }
static inline void *page_address(struct page *page) { return NULL; }
static inline void get_page(struct page *page) {}
static inline void esp_output_fill_trailer(void *tail, int tfclen, int plen, int proto) {}
static inline void __skb_fill_page_desc(struct sk_buff *skb, int i, struct page *page, int offset, int size) {}
static inline int skb_cow_data(struct sk_buff *skb, int tailen, struct sk_buff **trailer) { return 0; }
static inline unsigned char *skb_transport_header(struct sk_buff *skb) { return skb->transport_header; }
static inline void pskb_put(struct sk_buff *skb, struct sk_buff *trailer, int len) {}
static inline int esp_output_encap(struct xfrm_state *x, struct sk_buff *skb, struct esp_info *esp) { return 0; }

#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))
#define unlikely(x) (x)
#define refcount_add(i, count) (*(count) += (i))