#include <string.h>

typedef struct pqueue_st pqueue;
typedef struct pitem_st pitem;
typedef struct ssl_st SSL;
typedef struct ssl3_state_st SSL3_STATE;

#define SSL3_RT_HANDSHAKE 0
#define SSL3_MT_FINISHED 0
#define DTLS1_HM_FRAGMENT_RETRY 0

struct hm_header_st {
    unsigned char type;
    unsigned long msg_len;
    unsigned short seq;
    unsigned long frag_off;
    unsigned long frag_len;
};

struct hm_fragment_st {
    struct hm_header_st msg_header;
    unsigned char fragment[];
};

typedef struct hm_fragment_st hm_fragment;

struct ssl_st {
    SSL3_STATE *d1;
    struct {
        int (*ssl_read_bytes)(SSL *, int, unsigned char *, int, int);
    } *method;
};

struct ssl3_state_st {
    pqueue *buffered_messages;
    unsigned short handshake_read_seq;
};

pitem *pqueue_find(pqueue *pq, unsigned char *seq);
pitem *pitem_new(unsigned char *seq, hm_fragment *frag);
void pqueue_insert(pqueue *pq, pitem *item);
hm_fragment *dtls1_hm_fragment_new(unsigned long len, int alloc);
void dtls1_hm_fragment_free(hm_fragment *frag);
int dtls1_reassemble_fragment(SSL *s, struct hm_header_st *msg_hdr, int *ok);