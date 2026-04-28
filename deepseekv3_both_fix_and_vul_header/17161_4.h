#include <stdbool.h>
#include <stddef.h>

struct request {
    struct request_queue *q;
};

struct request_queue;

struct blk_mq_hw_ctx {
    struct blk_mq_tags *tags;
    struct request_queue *queue;
};

struct blk_mq_tags {
    struct request **rqs;
};

struct blk_align_bitmap {
    unsigned long word;
    int depth;
};

struct blk_mq_bitmap_tags {
    int map_nr;
    int bits_per_word;
    struct blk_align_bitmap *map;
};

typedef void busy_iter_fn(struct blk_mq_hw_ctx *, struct request *, void *, bool);

static inline unsigned long find_first_bit(const unsigned long *addr, unsigned long size) {
    unsigned long idx = 0;
    while (idx < size && !(addr[idx / (8 * sizeof(long))] & (1UL << (idx % (8 * sizeof(long))))))
        idx++;
    return idx;
}

static inline unsigned long find_next_bit(const unsigned long *addr, unsigned long size, unsigned long offset) {
    unsigned long idx = offset;
    while (idx < size && !(addr[idx / (8 * sizeof(long))] & (1UL << (idx % (8 * sizeof(long))))))
        idx++;
    return idx;
}

static inline struct request *blk_mq_tag_to_rq(struct blk_mq_tags *tags, unsigned int tag) {
    return tags->rqs[tag];
}