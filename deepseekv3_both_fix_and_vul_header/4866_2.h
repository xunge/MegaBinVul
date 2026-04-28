#include <string.h>
#include <stdlib.h>

typedef struct hm_header_st {
    unsigned char type;
    unsigned long msg_len;
    unsigned short seq;
    unsigned long frag_off;
    unsigned long frag_len;
} hm_header;

typedef struct hm_fragment_st {
    hm_header msg_header;
    unsigned char *fragment;
    unsigned char *reassembly;
} hm_fragment;

typedef struct pitem_st {
    unsigned char *priority;
    void *data;
    struct pitem_st *next;
} pitem;

typedef struct pqueue_st {
    pitem *items;
} pqueue;

typedef struct dtls1_state_st {
    pqueue *buffered_messages;
} DTLS1_STATE;

typedef struct ssl_method_st {
    int (*ssl_read_bytes)(void *s, int type, unsigned char *buf, int len, int peek);
} SSL_METHOD;

typedef struct ssl_st {
    SSL_METHOD *method;
    DTLS1_STATE *d1;
    unsigned long max_cert_list;
} SSL;

#define DTLS1_HM_HEADER_LENGTH 12
#define SSL3_RT_MAX_ENCRYPTED_LENGTH 16384
#define DTLS1_HM_FRAGMENT_RETRY 2
#define SSL3_RT_HANDSHAKE 22

#define RSMBLY_BITMASK_MARK(a, b, c) 
#define RSMBLY_BITMASK_IS_COMPLETE(a, b, c) 

static inline void OPENSSL_free(void *ptr) { free(ptr); }

pitem *pqueue_find(pqueue *pq, unsigned char *seq);
pitem *pitem_new(unsigned char *seq, void *data);
void pqueue_insert(pqueue *pq, pitem *item);
hm_fragment *dtls1_hm_fragment_new(unsigned long len, int alloc);
void dtls1_hm_fragment_free(hm_fragment *frag);