#include <stddef.h>
#include <errno.h>

#define MAX_SKB_FRAGS 32
#define ETH_MAX_MTU 65536
#define NET_SKB_PAD 32
#define NET_IP_ALIGN 2
#define PAGE_SIZE 4096

#define ERR_PTR(err) ((void *)(long)(err))
#define EMSGSIZE 90
#define ENOMEM 12
#define EINVAL 22

struct sk_buff {
    unsigned int len;
    unsigned int data_len;
    unsigned int truesize;
};

struct napi_struct {
    int dummy;
};

struct tun_file {
    struct napi_struct napi;
};

struct iov_iter {
    int nr_segs;
    struct iovec *iov;
};

struct iovec {
    size_t iov_len;
};

struct page {
    char dummy;
};

static inline void local_bh_disable(void) {}
static inline void local_bh_enable(void) {}
static inline struct sk_buff *napi_get_frags(struct napi_struct *napi) { return (struct sk_buff *)0; }
static inline void napi_free_frags(struct napi_struct *napi) {}
static inline size_t iov_iter_single_seg_count(const struct iov_iter *it) { return 0; }
static inline int __skb_grow(struct sk_buff *skb, size_t len) { return 0; }
static inline void *netdev_alloc_frag(size_t fragsz) { return (void *)0; }
static inline struct page *virt_to_head_page(const void *x) { return (struct page *)0; }
static inline void *page_address(const struct page *page) { return (void *)0; }
static inline void skb_fill_page_desc(struct sk_buff *skb, int i, struct page *page, void *frag, size_t fragsz) {}