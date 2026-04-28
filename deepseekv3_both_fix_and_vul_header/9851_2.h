#include <stddef.h>
#include <errno.h>

#define READ 0
#define REQ_COPY_USER (1 << 0)
#define BIO_USER_MAPPED (1 << 0)

typedef unsigned int gfp_t;

struct bio {
    unsigned int bi_size;
    unsigned long bi_flags;
};

struct request_queue {
    unsigned long dma_pad_mask;
    unsigned long (*queue_dma_alignment)(struct request_queue *);
};

struct request {
    unsigned int cmd_flags;
    void *buffer;
};

struct rq_map_data;
struct sg_iovec {
    void *iov_base;
    size_t iov_len;
};

static inline int rq_data_dir(struct request *rq) { return 0; }
static inline unsigned long queue_dma_alignment(struct request_queue *q) { return 0; }

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

struct bio *bio_copy_user_iov(struct request_queue *q, struct rq_map_data *map_data,
                            struct sg_iovec *iov, int iov_count, int read, gfp_t gfp_mask);
struct bio *bio_map_user_iov(struct request_queue *q, void *null, struct sg_iovec *iov,
                           int iov_count, int read, gfp_t gfp_mask);
void bio_get(struct bio *bio);
void bio_endio(struct bio *bio, int status);
void __blk_rq_unmap_user(struct bio *bio);
int bio_flagged(struct bio *bio, int flag);
void blk_queue_bounce(struct request_queue *q, struct bio **bio);
void blk_rq_bio_prep(struct request_queue *q, struct request *rq, struct bio *bio);