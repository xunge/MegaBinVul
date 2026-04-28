#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <errno.h>

#define PAGE_SIZE 4096
#define PAGE_SHIFT 12
#define MAX_SKB_FRAGS 16

#define SOCK_ASYNC_NOSPACE 0
#define SOCK_NOSPACE 1
#define SEND_SHUTDOWN 1

#define __GFP_WAIT 0
#define __GFP_REPEAT 0

typedef unsigned int gfp_t;

struct sock {
    gfp_t sk_allocation;
    int sk_shutdown;
    int sk_sndbuf;
    int sk_wmem_alloc;
    struct {
        unsigned long flags;
    } *sk_socket;
};

struct skb_shared_info {
    int nr_frags;
};

struct sk_buff {
    unsigned int truesize;
    struct skb_shared_info *shinfo;
};

struct page {};

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return skb->shinfo;
}

static inline struct sk_buff *alloc_skb(unsigned long size, gfp_t priority) { return NULL; }
static inline struct page *alloc_pages(gfp_t gfp_mask, int order) { return NULL; }
static inline void __skb_fill_page_desc(struct sk_buff *skb, int i, struct page *page, int offset, int size) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void skb_set_owner_w(struct sk_buff *skb, struct sock *sk) {}

static inline int sock_error(struct sock *sk) { return 0; }
static inline long sock_sndtimeo(struct sock *sk, int noblock) { return 0; }
static inline long sock_wait_for_wmem(struct sock *sk, long timeo) { return 0; }
static inline int sock_intr_errno(long timeo) { return 0; }
static inline int signal_pending(void *current) { return 0; }

static inline int atomic_read(int *v) { return *v; }
static inline void set_bit(int nr, unsigned long *addr) {}

#define EMSGSIZE 90
#define EPIPE 32
#define ENOBUFS 105
#define EAGAIN 11

void *current = NULL;