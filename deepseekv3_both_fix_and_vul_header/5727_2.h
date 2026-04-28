#include <stdlib.h>

typedef struct pitem_st {
    struct pitem_st *next;
    void *data;
} pitem;

typedef struct pqueue_st {
    pitem *q;
} pqueue;

typedef struct hm_fragment_st {
    unsigned char *fragment;
} hm_fragment;

typedef struct DTLS1_RECORD_DATA_st {
    struct {
        unsigned char *buf;
    } rbuf;
} DTLS1_RECORD_DATA;

typedef struct dtls1_state_st {
    struct {
        pqueue *q;
    } unprocessed_rcds;
    struct {
        pqueue *q;
    } processed_rcds;
    pqueue *buffered_messages;
    pqueue *sent_messages;
    struct {
        pqueue *q;
    } buffered_app_data;
} DTLS1_STATE;

typedef struct ssl_st {
    DTLS1_STATE *d1;
} SSL;

void OPENSSL_free(void *ptr);
pitem *pqueue_pop(pqueue *pq);
void pitem_free(pitem *item);