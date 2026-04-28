#include <string.h>
#include <stdlib.h>

#define DTLS1_HM_FRAGMENT_RETRY 0
#define SSL3_RT_HANDSHAKE 20
#define RSMBLY_BITMASK_MARK(a, b, c)
#define RSMBLY_BITMASK_IS_COMPLETE(a, b, c)

typedef struct hm_header_st {
    unsigned long frag_len;
    unsigned long msg_len;
    unsigned long frag_off;
    unsigned short seq;
} hm_header_st;

typedef struct hm_fragment {
    struct hm_header_st msg_header;
    unsigned char *fragment;
    unsigned char *reassembly;
} hm_fragment;

typedef struct pitem {
    void *data;
} pitem;

typedef struct pqueue {
} pqueue;

typedef struct ssl_method_st {
    int (*ssl_read_bytes)(void *, int, void *, int, int);
} ssl_method_st;

typedef struct dtls1_state_st {
    pqueue *buffered_messages;
} dtls1_state_st;

typedef struct ssl_st {
    const ssl_method_st *method;
    dtls1_state_st *d1;
} SSL;

void OPENSSL_free(void *ptr);
void OPENSSL_assert(int expr);
hm_fragment *dtls1_hm_fragment_new(unsigned long len, int alloc);
void dtls1_hm_fragment_free(hm_fragment *frag);
pitem *pqueue_find(pqueue *pq, unsigned char *seq64be);
pitem *pitem_new(unsigned char *seq64be, hm_fragment *frag);
pitem *pqueue_insert(pqueue *pq, pitem *item);
unsigned long dtls1_max_handshake_message_len(SSL *s);