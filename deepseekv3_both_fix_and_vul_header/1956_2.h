#include <stdint.h>
#include <unistd.h>

typedef uint16_t u16;
typedef int32_t s32;
typedef uint64_t dma_addr_t;

struct b43_dmaring {
    const struct b43_dma_ops *ops;
    struct b43_wldev *dev;
    u16 rx_buffersize;
    u16 frameoffset;
};

struct b43_dma_ops {
    struct b43_dmadesc_generic* (*idx2desc)(struct b43_dmaring*, int, struct b43_dmadesc_meta**);
};

struct b43_dmadesc_meta {
    dma_addr_t dmaaddr;
    struct sk_buff *skb;
};

struct b43_rxhdr_fw4 {
    u16 frame_len;
};

struct sk_buff {
    void *data;
};

struct b43_wldev {
    void *wl;
};

#define GFP_ATOMIC 0
#define unlikely(x) (x)

static inline u16 le16_to_cpu(u16 val) { return val; }
static inline void barrier(void) { __asm__ __volatile__("": : :"memory"); }
static inline void udelay(unsigned long usecs) { usleep(usecs); }

static void sync_descbuffer_for_cpu(struct b43_dmaring *ring, dma_addr_t addr, u16 size) {}
static void sync_descbuffer_for_device(struct b43_dmaring *ring, dma_addr_t addr, u16 size) {}
static int b43_rx_buffer_is_poisoned(struct b43_dmaring *ring, struct sk_buff *skb) { return 0; }
static void b43dbg(void *wl, const char *fmt, ...) {}
static void b43err(void *wl, const char *fmt, ...) {}
static void b43_poison_rx_buffer(struct b43_dmaring *ring, struct sk_buff *skb) {}
static int next_slot(struct b43_dmaring *ring, int slot) { return 0; }
static int setup_rx_descbuffer(struct b43_dmaring *ring, struct b43_dmadesc_generic *desc,
                              struct b43_dmadesc_meta *meta, int gfp) { return 0; }
static void unmap_descbuffer(struct b43_dmaring *ring, dma_addr_t addr, u16 size, int direction) {}
static void *skb_put(struct sk_buff *skb, unsigned int len) { return NULL; }
static void *skb_pull(struct sk_buff *skb, unsigned int len) { return NULL; }
static void b43_rx(struct b43_wldev *dev, struct sk_buff *skb, struct b43_rxhdr_fw4 *rxhdr) {}