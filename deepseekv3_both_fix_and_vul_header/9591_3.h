typedef struct ssl_st SSL;
typedef struct pitem_st pitem;
typedef struct pqueue_st {
    pitem *head;
} pqueue;

struct dtls1_state_st {
    struct {
        pqueue *q;
        unsigned int epoch;
    } unprocessed_rcds;
    struct {
        unsigned int epoch;
    } processed_rcds;
    unsigned int r_epoch;
};

struct ssl3_state_st {
    struct {
        unsigned long seq_num;
    } rrec;
};

struct ssl_st {
    struct dtls1_state_st *d1;
    struct ssl3_state_st *s3;
};

pitem *pqueue_peek(pqueue *pq);
int dtls1_get_unprocessed_record(SSL *s);
int dtls1_process_record(SSL *s);
int dtls1_buffer_record(SSL *s, void *processed_rcds, unsigned long seq_num);