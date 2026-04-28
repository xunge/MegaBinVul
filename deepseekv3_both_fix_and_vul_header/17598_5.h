#include <stddef.h>

enum hrtimer_restart {
    HRTIMER_NORESTART,
    HRTIMER_RESTART
};

struct hrtimer {
    int dummy;
};

struct bfq_data {
    struct hrtimer idle_slice_timer;
    struct bfq_queue *in_service_queue;
};

struct bfq_queue;

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

enum hrtimer_restart bfq_idle_slice_timer_body_dual(struct bfq_data *bfqd, struct bfq_queue *bfqq);
enum hrtimer_restart bfq_idle_slice_timer_body_single(struct bfq_queue *bfqq);