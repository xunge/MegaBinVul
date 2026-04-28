#include <string.h>

typedef struct pitem_st {
    void *data;
    struct pitem_st *next;
} pitem;

typedef struct hm_fragment_st {
    struct {
        unsigned long seq;
        unsigned long frag_len;
        unsigned long frag_off;
    } msg_header;
    unsigned char *fragment;
    void *reassembly;
} hm_fragment;

typedef struct pqueue_st {
    pitem *head;
} pqueue;

typedef struct ssl_buffer_st {
    unsigned char *data;
} ssl_buffer;

typedef struct dtls1_state_st {
    pqueue *buffered_messages;
    unsigned long handshake_read_seq;
} dtls1_state_st;

typedef struct ssl_st {
    dtls1_state_st *d1;
    ssl_buffer *init_buf;
    int init_num;
} SSL;

#define DTLS1_HM_HEADER_LENGTH 12
#define SSL3_AL_FATAL 2

int dtls1_preprocess_fragment(SSL *s, void *msg_header);
void dtls1_hm_fragment_free(hm_fragment *frag);
void pitem_free(pitem *item);
void ssl3_send_alert(SSL *s, int level, int description);
pitem *pqueue_peek(pqueue *pq);
void pqueue_pop(pqueue *pq);