#include <stddef.h>
#include <limits.h>

#define WARN_ON_ONCE(condition) ((void)0)
#define ENOMEM 12
#define GFP_KERNEL 0
#define QUEUE_FLAG_DEFAULT 0
#define NUMA_NO_NODE (-1)

struct request_list {
    int dummy;
};

struct work_struct {
    int dummy;
};

struct request_queue {
    void *mq_ops;
    struct blk_flush_queue *fq;
    int cmd_size;
    int (*init_rq_fn)(struct request_queue *, void *, int);
    struct request_list root_rl;
    struct work_struct timeout_work;
    unsigned int queue_flags;
    int sg_reserved_size;
    void (*exit_rq_fn)(struct request_queue *, void *);
};

struct blk_flush_queue {
    void *flush_rq;
};

struct bio;

extern struct blk_flush_queue *blk_alloc_flush_queue(struct request_queue *q, int node, int cmd_size);
extern void blk_free_flush_queue(struct blk_flush_queue *fq);
extern int blk_init_rl(struct request_list *rl, struct request_queue *q, int gfp_mask);
extern void blk_queue_make_request(struct request_queue *q, void (*make_request_fn)(struct request_queue *q, struct bio *bio));
extern int elevator_init(struct request_queue *q);
extern void blk_timeout_work(struct work_struct *work);
extern void blk_queue_bio(struct request_queue *q, struct bio *bio);

#define INIT_WORK(work, func) ((void)0)