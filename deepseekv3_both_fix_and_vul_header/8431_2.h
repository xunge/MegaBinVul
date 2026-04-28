#include <stddef.h>

typedef struct pitem_st {
    void *data;
    struct pitem_st *next;
} pitem;

typedef struct pqueue_st {
    pitem *head;
} pqueue;

typedef struct ssl3_buffer_st {
    int left;
} SSL3_BUFFER;

typedef struct ssl3_record_st {
    unsigned char seq_num[8];
    int length;
} SSL3_RECORD;

typedef struct dtls1_bitmap_st {
    unsigned long map;
} DTLS1_BITMAP;

typedef struct record_layer_data_st {
    struct {
        pqueue *q;
        int epoch;
    } unprocessed_rcds;
    struct {
        int epoch;
    } processed_rcds;
    SSL3_RECORD *rrec;
    int r_epoch;
    SSL3_BUFFER *rbuf;
} RECORD_LAYER_DATA;

typedef struct record_layer_st {
    RECORD_LAYER_DATA *d;
    SSL3_RECORD *rrec;
} RECORD_LAYER;

typedef struct ssl_st {
    RECORD_LAYER rlayer;
} SSL;

#define SSL_F_DTLS1_PROCESS_BUFFERED_RECORDS 0
#define ERR_R_INTERNAL_ERROR 0

pitem *pqueue_peek(pqueue *q);
int SSL3_BUFFER_get_left(SSL3_BUFFER *rb);
SSL3_BUFFER *RECORD_LAYER_get_rbuf(RECORD_LAYER *rl);
SSL3_RECORD *RECORD_LAYER_get_rrec(RECORD_LAYER *rl);
unsigned char *SSL3_RECORD_get_seq_num(SSL3_RECORD *rr);
int dtls1_get_unprocessed_record(SSL *s);
int dtls1_process_record(SSL *s, ...);
int dtls1_buffer_record(SSL *s, void *processed_rcds, unsigned char *seq_num);
DTLS1_BITMAP *dtls1_get_bitmap(SSL *s, SSL3_RECORD *rr, unsigned int *is_next_epoch);
int dtls1_record_replay_check(SSL *s, DTLS1_BITMAP *bitmap);
void SSLerr(int func, int reason);
int BIO_dgram_is_sctp(void *bio);
void *SSL_get_rbio(SSL *s);
void RECORD_LAYER_reset_packet_length(RECORD_LAYER *rl);