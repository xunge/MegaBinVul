#include <linux/sched.h>
#include <linux/wait.h>

struct mid_q_entry {
    int mid_state;
    void *callback_data;
};

#define MID_RESPONSE_RECEIVED 0
#define MID_RESPONSE_READY 0