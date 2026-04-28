#include <stdint.h>

struct can_frame {
    uint32_t can_id;
    uint8_t can_dlc;
    uint8_t __pad;
    uint8_t __res0;
    uint8_t __res1;
    uint8_t data[8];
};

struct bcm_op {
    struct can_frame *last_frames;
};

#define RX_THR 0x80

void bcm_rx_changed(struct bcm_op *op, struct can_frame *frame);