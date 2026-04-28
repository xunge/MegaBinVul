#include <limits.h>
#include <sys/time.h>
#include <linux/can.h>

struct bcm_msg_head {
    unsigned int opcode;
    unsigned int flags;
    unsigned int count;
    struct timeval ival1;
    struct timeval ival2;
    canid_t can_id;
    unsigned int nframes;
};

struct bcm_op {
    unsigned long frames_filtered;
    unsigned long frames_abs;
    unsigned int flags;
    unsigned int count;
    struct timeval ival1;
    struct timeval ival2;
    canid_t can_id;
};

#define BCM_CAN_FLAGS_MASK 0x3F
#define RX_RECV 0x40
#define RX_CHANGED 0x01

void bcm_send_to_user(struct bcm_op *op, struct bcm_msg_head *head, struct canfd_frame *data, int nframes);