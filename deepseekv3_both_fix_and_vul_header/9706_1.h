#include <stdint.h>

#define RX_RECV 0x80
#define BCM_CAN_DLC_MASK 0x0F
#define RX_CHECK_DLC 0x01

struct can_frame {
    uint32_t can_id;
    uint8_t can_dlc;
    uint8_t data[8];
};

struct bcm_op {
    struct can_frame *last_frames;
    struct can_frame *frames;
    int flags;
};

#define GET_U64(p) (*(uint64_t *)(p))

static void bcm_rx_update_and_send(struct bcm_op *op, struct can_frame *last_frame, const struct can_frame *rxdata);