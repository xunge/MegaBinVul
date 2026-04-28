#include <string.h>

typedef struct SSL_st SSL;
typedef struct pqueue_st pqueue;
typedef struct pitem_st pitem;
typedef struct hm_fragment_st hm_fragment;
typedef struct hm_header_st hm_header;

#define SSL3_RT_HANDSHAKE 22
#define SSL3_MT_FINISHED 20
#define DTLS1_HM_FRAGMENT_RETRY 0

struct hm_header_st {
    unsigned char type;
    unsigned long msg_len;
    unsigned short seq;
    unsigned long frag_off;
    unsigned long frag_len;
};

struct hm_fragment_st {
    hm_header msg_header;
    unsigned char *fragment;
};

struct ssl_method_st {
    int (*ssl_read_bytes)(SSL *s, int type, unsigned char *buf, int len, int peek);
};

struct dtls1_state_st {
    pqueue *buffered_messages;
    unsigned short handshake_read_seq;
};

struct SSL_st {
    struct ssl_method_st *method;
    struct dtls1_state_st *d1;
};

pitem *pqueue_find(pqueue *pq, unsigned char *seq);
pitem *pitem_new(unsigned char *seq, void *data);
void pqueue_insert(pqueue *pq, pitem *item);
void dtls1_hm_fragment_free(hm_fragment *frag);
int dtls1_reassemble_fragment(SSL *s, hm_header *msg_hdr, int *ok);
hm_fragment *dtls1_hm_fragment_new(unsigned long frag_len, int reassembly);
void OPENSSL_free(void *ptr);