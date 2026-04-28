#include <stddef.h>

#define BLKDEV_MAX_RQ 128

struct kobject {
    // minimal kobject definition
};

struct blk_mq_tag_set {
    unsigned int queue_depth;
};

struct request_queue {
    struct elevator_queue *elevator;
    unsigned int nr_requests;
    struct blk_mq_tag_set *tag_set;
};

struct blk_mq_hw_ctx {
    // minimal hw context definition
};

struct elevator_type_ops {
    int (*init_sched)(struct request_queue *, struct elevator_type *);
    int (*init_hctx)(struct blk_mq_hw_ctx *, unsigned int);
};

struct elevator_type {
    struct elevator_type_ops ops;
};

struct elevator_queue {
    struct kobject kobj;
};

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

#define queue_for_each_hw_ctx(q, hctx, i) \
    for (i = 0, hctx = NULL; i < 1; i++)

int blk_mq_sched_alloc_tags(struct request_queue *q, struct blk_mq_hw_ctx *hctx, unsigned int i);
void blk_mq_debugfs_register_sched(struct request_queue *q);
void blk_mq_exit_sched(struct request_queue *q, struct elevator_queue *eq);
void kobject_put(struct kobject *kobj);
void blk_mq_debugfs_register_sched_hctx(struct request_queue *q, struct blk_mq_hw_ctx *hctx);
void blk_mq_sched_tags_teardown(struct request_queue *q);