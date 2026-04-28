#include <stddef.h>
#include <stdbool.h>

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); \
})

enum hrtimer_restart {
    HRTIMER_NORESTART,
    HRTIMER_RESTART
};

struct hrtimer {
    // Minimal definition for compilation
};

struct bcm_op {
    struct hrtimer timer;
    unsigned long kt_ival1;
    unsigned long kt_ival2;
    unsigned int count;
    unsigned int flags;
    unsigned int ival1;
    unsigned int ival2;
    unsigned int can_id;
};

struct bcm_msg_head {
    unsigned int opcode;
    unsigned int flags;
    unsigned int count;
    unsigned int ival1;
    unsigned int ival2;
    unsigned int can_id;
    unsigned int nframes;
};

#define TX_COUNTEVT (1 << 0)
#define TX_EXPIRED 1

void bcm_send_to_user(struct bcm_op *op, struct bcm_msg_head *msg_head, void *data, int size);
void bcm_can_tx(struct bcm_op *op);
bool bcm_tx_set_expiry(struct bcm_op *op, struct hrtimer *timer);