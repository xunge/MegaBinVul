#include <stddef.h>

struct request_queue {
    struct blk_mq_tag_set *tag_set;
    struct blk_mq_hw_ctx **queue_hw_ctx;
    unsigned int nr_hw_queues;
};

struct blk_mq_hw_ctx {
    struct blk_mq_tags *sched_tags;
};

struct blk_mq_tag_set;
struct blk_mq_tags;

#define queue_for_each_hw_ctx(q, hctx, i) \
    for ((i) = 0, (hctx) = (q)->queue_hw_ctx[(i)]; \
         (i) < (q)->nr_hw_queues; \
         (i)++, (hctx) = (q)->queue_hw_ctx[(i)])

extern void blk_mq_free_rq_map(struct blk_mq_tags *tags);
extern void blk_mq_sched_free_tags(struct blk_mq_tag_set *set, struct blk_mq_hw_ctx *hctx, int i);