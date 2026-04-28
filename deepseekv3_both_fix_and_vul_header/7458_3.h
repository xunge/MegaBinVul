#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;

struct page_frag {
    struct page *page;
    unsigned int offset;
};

struct page {
    char dummy;
};

struct xfrm_state {
    int encap;
    int lock;
    struct page_frag xfrag;
};

struct sk_buff {
    unsigned int data_len;
    unsigned int len;
    unsigned int truesize;
    void *sk;
    struct skb_shared_info *shinfo;
    unsigned char *transport_header;
    unsigned char *tail;
};

struct skb_shared_info {
    unsigned int nr_frags;
};

struct sock {
    int sk_wmem_alloc;
};

struct ip_esp_hdr {
};

struct esp_info {
    int tailen;
    int tfclen;
    int plen;
    int proto;
    bool inplace;
    struct ip_esp_hdr *esph;
};

#define L1_CACHE_BYTES 64
#define ESP_SKB_FRAG_MAXSIZE 65536
#define MAX_SKB_FRAGS 18
#define GFP_ATOMIC 0

#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))
#define unlikely(x) (x)

static inline void spin_lock_bh(int *lock) {}
static inline void spin_unlock_bh(int *lock) {}
static inline bool skb_cloned(struct sk_buff *skb) { return false; }
static inline unsigned int skb_tailroom(struct sk_buff *skb) { return 0; }
static inline u8 *skb_tail_pointer(struct sk_buff *skb) { return NULL; }
static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) { return NULL; }
static inline bool skb_has_frag_list(struct sk_buff *skb) { return false; }
static inline bool skb_page_frag_refill(unsigned int size, struct page_frag *pfrag, int gfp) { return false; }
static inline void *page_address(struct page *page) { return NULL; }
static inline void get_page(struct page *page) {}
static inline void __skb_fill_page_desc(struct sk_buff *skb, int i, struct page *page, int off, int size) {}
static inline unsigned char *skb_transport_header(struct sk_buff *skb) { return NULL; }
static inline int skb_cow_data(struct sk_buff *skb, int tailen, struct sk_buff **trailer) { return 0; }
static inline void pskb_put(struct sk_buff *skb, struct sk_buff *trailer, int len) {}
static inline void refcount_add(int i, int *r) {}
static inline bool sk_fullsock(struct sock *sk) { return false; }
static inline void esp_output_fill_trailer(u8 *tail, int tfclen, int plen, int proto) {}
static inline int esp6_output_encap(struct xfrm_state *x, struct sk_buff *skb, struct esp_info *esp) { return 0; }