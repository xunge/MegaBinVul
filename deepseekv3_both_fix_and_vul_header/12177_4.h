#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/errno.h>

struct wait_queue_head;

struct TCP_Server_Info {
    struct wait_queue_head *response_q;
};

struct mid_q_entry {
    int mid_state;
};

#define MID_REQUEST_SUBMITTED 0
#define MID_RESPONSE_RECEIVED 1
#define ERESTARTSYS 512
#define TASK_KILLABLE 1
#define TASK_FREEZABLE_UNSAFE 2

int wait_event_state(struct wait_queue_head *q, int condition, int state);