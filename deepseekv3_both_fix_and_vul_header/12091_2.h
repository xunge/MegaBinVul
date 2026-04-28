#include <stdint.h>

#define PAGE_SIZE 4096
#define IGB_MAX_FRAME_BUILD_SKB 2048
#define E1000_RCTL 0x0100
#define E1000_RCTL_SBP (1 << 1)
#define IGB_FLAG_RX_LEGACY (1 << 0)

struct e1000_hw {
    /* dummy structure definition */
    int dummy;
};

struct igb_adapter {
    struct e1000_hw hw;
    unsigned int flags;
    unsigned int max_frame_size;
};

struct igb_ring {
    /* dummy structure definition */
    int dummy;
};

void clear_ring_build_skb_enabled(struct igb_ring *ring);
void clear_ring_uses_large_buffer(struct igb_ring *ring);
void set_ring_build_skb_enabled(struct igb_ring *ring);
void set_ring_uses_large_buffer(struct igb_ring *ring);
uint32_t rd32(uint32_t reg);