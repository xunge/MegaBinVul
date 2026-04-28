#include <stdbool.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

typedef struct {
    int lock;
} spinlock_t;

struct blk_mq_ctx {
    int cpu;
};

struct request {
    struct request_queue *q;
    struct blk_mq_ctx *mq_ctx;
    int tag;
    struct list_head flush;
};

struct request_queue {
    struct blk_mq_ops *mq_ops;
};

struct blk_flush_queue {
    spinlock_t mq_flush_lock;
    struct list_head flush_queue[2];
    int flush_running_idx;
    int flush_pending_idx;
    int flush_queue_delayed;
    struct request *orig_rq;
};

struct blk_mq_hw_ctx;
struct blk_mq_ops {
    struct blk_mq_hw_ctx *(*map_queue)(struct request_queue *q, int cpu);
};

enum {
    REQ_FSEQ_PREFLUSH,
    REQ_FSEQ_POSTFLUSH,
};

#define BUG_ON(cond) do { if (cond) {} } while (0)
#define WARN_ON(cond) do { if (cond) {} } while (0)

static inline void spin_lock_irqsave(spinlock_t *lock, unsigned long flags) { (void)lock; (void)flags; }
static inline void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags) { (void)lock; (void)flags; }

static inline unsigned int blk_flush_cur_seq(struct request *rq) { (void)rq; return 0; }
static inline bool blk_flush_complete_seq(struct request *rq, struct blk_flush_queue *fq, unsigned int seq, int error) { (void)rq; (void)fq; (void)seq; (void)error; return false; }
static inline void blk_run_queue_async(struct request_queue *q) { (void)q; }
static inline void elv_completed_request(struct request_queue *q, struct request *rq) { (void)q; (void)rq; }
static inline struct blk_flush_queue *blk_get_flush_queue(struct request_queue *q, struct blk_mq_ctx *ctx) { (void)q; (void)ctx; return NULL; }
static inline void blk_mq_tag_set_rq(struct blk_mq_hw_ctx *hctx, int tag, struct request *rq) { (void)hctx; (void)tag; (void)rq; }

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != (void *)(head); )