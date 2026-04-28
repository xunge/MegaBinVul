struct blk_mq_tags {
    struct request **rqs;
};

struct request {
    void *q;
    void *mq_ctx;
};

struct blk_flush_queue {
    struct request *flush_rq;
};

struct blk_flush_queue *blk_get_flush_queue(void *q, void *mq_ctx);
int is_flush_request(struct request *rq, struct blk_flush_queue *fq, unsigned int tag);