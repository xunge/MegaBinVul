#include <stdbool.h>

struct bfq_queue {
    struct bfq_data *bfqd;
    int queued[2];
};

struct bfq_data {
    int lock;
    struct bfq_queue *in_service_queue;
};

enum bfqq_expiration {
    BFQQE_BUDGET_TIMEOUT,
    BFQQE_TOO_IDLE
};

void bfq_clear_bfqq_wait_request(struct bfq_queue *bfqq);
bool bfq_bfqq_budget_timeout(struct bfq_queue *bfqq);
void bfq_bfqq_expire(struct bfq_data *bfqd, struct bfq_queue *bfqq, bool flag, enum bfqq_expiration reason);
void bfq_schedule_dispatch(struct bfq_data *bfqd);

#define spin_lock_irqsave(lock, flags) ((void)(flags))
#define spin_unlock_irqrestore(lock, flags) ((void)(flags))