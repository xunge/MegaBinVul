#include <stddef.h>
#include <stdbool.h>

struct page {
    // Minimal page structure definition
};

struct sk_buff {
    // Minimal sk_buff structure definition
    struct skb_shared_info *shinfo;
};

struct skb_shared_info {
    unsigned int nr_frags;
    struct {
        // Minimal frag definition
    } frags[16]; // Assuming maximum 16 fragments
};

struct mt76_dev {
    struct {
        void (*rx_skb)(struct mt76_dev *, int, struct sk_buff *);
    } *drv;
    struct mt76_queue *q_rx;
};

struct mt76_queue {
    struct sk_buff *rx_head;
    int buf_offset;
    unsigned int buf_size;
};

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static inline struct page *virt_to_head_page(void *data) {
    return (struct page *)0; // Dummy implementation
}

static inline void *page_address(struct page *page) {
    return (void *)0; // Dummy implementation
}

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return skb->shinfo; // Dummy implementation
}

static inline void skb_add_rx_frag(struct sk_buff *skb, int i, struct page *page,
                                  int offset, int len, unsigned int buf_size) {
    // Dummy implementation
}