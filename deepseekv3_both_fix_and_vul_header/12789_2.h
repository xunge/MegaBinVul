#include <stddef.h>
#include <string.h>

struct hrtimer {
    // Minimal stub definition
    int dummy;
};

struct bcm_op {
    struct hrtimer timer;
    int flags;
    void *last_frames;
    unsigned int nframes;
    unsigned int cfsiz;
    int count;
    int ival1;
    int ival2;
    int can_id;
};

struct bcm_msg_head {
    int opcode;
    int flags;
    int count;
    int ival1;
    int ival2;
    int can_id;
    int nframes;
};

#define RX_ANNOUNCE_RESUME 0x01
#define RX_TIMEOUT 0x02

enum hrtimer_restart {
    HRTIMER_NORESTART,
    HRTIMER_RESTART
};

void bcm_send_to_user(struct bcm_op *op, struct bcm_msg_head *msg_head, void *data, int size);

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))