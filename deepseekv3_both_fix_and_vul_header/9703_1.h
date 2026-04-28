#include <stdint.h>

struct sk_buff {
    void *data;
    uint64_t tstamp;
    struct {
        int ifindex;
    } *dev;
};

struct can_frame {
    uint32_t can_id;
};

struct bcm_op {
    struct {
        int dummy;
    } timer;
    uint32_t can_id;
    uint64_t rx_stamp;
    int rx_ifindex;
    unsigned int frames_abs;
    unsigned int flags;
    unsigned int nframes;
    struct can_frame *frames;
    struct can_frame *last_frames;
};

#define RX_RTR_FRAME 0x01
#define RX_FILTER_ID 0x02

#define GET_U64(p) (*(uint64_t*)(p))

void hrtimer_cancel(struct {int dummy;} *timer);
void bcm_can_tx(struct bcm_op *op);
void bcm_rx_update_and_send(struct bcm_op *op, struct can_frame *last, const struct can_frame *rx);
void bcm_rx_cmp_to_index(struct bcm_op *op, int index, const struct can_frame *rx);
void bcm_rx_starttimer(struct bcm_op *op);