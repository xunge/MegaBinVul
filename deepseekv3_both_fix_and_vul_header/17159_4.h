#include <stdbool.h>
#include <stddef.h>

#define FLUSH_PENDING_TIMEOUT 0
#define REQ_TYPE_FS 1
#define WRITE_FLUSH (1 << 0)
#define REQ_FLUSH_SEQ (1 << 1)

struct list_head {
    struct list_head *next, *prev;
};

struct blk_mq_ctx {
    int cpu;
};

struct blk_mq_hw_ctx {
    // minimal definition
};

struct blk_mq_ops {
    struct blk_mq_hw_ctx* (*map_queue)(struct request_queue*, int);
};

struct request {
    struct {
        struct list_head list;
    } flush;
    struct request_queue *q;
    struct blk_mq_ctx *mq_ctx;
    int tag;
    unsigned int cmd_type;
    unsigned int cmd_flags;
    void *rq_disk;
    void (*end_io)(struct request *, int);
};

struct request_queue {
    struct blk_mq_ops *mq_ops;
};

struct blk_flush_queue {
    struct list_head flush_queue[2];
    struct list_head flush_data_in_flight;
    int flush_pending_idx;
    int flush_running_idx;
    unsigned long flush_pending_since;
    struct request *flush_rq;
    struct request *orig_rq;
};

extern unsigned long jiffies;

#define list_first_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static inline bool list_empty(const struct list_head *head)
{
    return head->next == head;
}

static inline bool time_before(unsigned long a, unsigned long b)
{
    return a < b;
}

extern void blk_rq_init(struct request_queue *q, struct request *rq);
extern bool blk_flush_queue_rq(struct request *rq, bool force);
extern void blk_mq_tag_set_rq(struct blk_mq_hw_ctx *hctx, unsigned int tag, struct request *rq);
extern void flush_end_io(struct request *rq, int error);