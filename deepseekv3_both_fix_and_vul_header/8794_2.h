#include <stdbool.h>
#include <stddef.h>

struct request_queue {
    unsigned long dma_pad_mask;
};

struct request {
    struct bio *bio;
    int cmd_flags;
};

struct rq_map_data {
    // placeholder structure
};

struct iov_iter {
    // placeholder structure
};

struct bio {
    // placeholder structure
};

#define REQ_COPY_USER 0
#define BIO_USER_MAPPED 0
#define EINVAL 1

typedef unsigned int gfp_t;

unsigned long queue_dma_alignment(struct request_queue *q);
unsigned long iov_iter_alignment(const struct iov_iter *i);
unsigned long queue_virt_boundary(struct request_queue *q);
unsigned long iov_iter_gap_alignment(const struct iov_iter *i);
size_t iov_iter_count(const struct iov_iter *i);
int __blk_rq_map_user_iov(struct request *rq, struct rq_map_data *map_data,
                         struct iov_iter *iter, gfp_t gfp_mask, bool copy);
void __blk_rq_unmap_user(struct bio *bio);
bool bio_flagged(struct bio *bio, int flag);