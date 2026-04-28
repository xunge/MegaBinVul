#include <stddef.h>
#include <limits.h>
#include <errno.h>

#define MAX_SKB_FRAGS 32
#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PAGE_SHIFT 12
#define EFAULT 14

#define min_t(type, x, y) ({ \
    type __min1 = (x); \
    type __min2 = (y); \
    __min1 < __min2 ? __min1 : __min2; \
})

struct sk_buff {
    void *data;
    unsigned int len;
    unsigned int data_len;
    unsigned int truesize;
    struct skb_shared_info *shinfo;
    struct sock *sk;
};

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct sock {
    int sk_wmem_alloc;
};

struct page;

struct skb_shared_info {
    int nr_frags;
};

static inline int iov_length(const struct iovec *iov, int count) {
    return 0;
}

static inline int skb_headlen(const struct sk_buff *skb) {
    return 0;
}

static inline int copy_from_user(void *to, const void *from, unsigned long n) {
    return 0;
}

static inline int get_user_pages_fast(unsigned long start, int nr_pages, int write, struct page **pages) {
    return 0;
}

static inline void put_page(struct page *page) {
}

static inline void __skb_fill_page_desc(struct sk_buff *skb, int i, struct page *page, int off, int size) {
}

static inline void atomic_add(int i, int *v) {
}

static inline struct skb_shared_info *skb_shinfo(const struct sk_buff *skb) {
    return skb->shinfo;
}