#include <string.h>

#define SSL3_RT_HANDSHAKE 22
#define SSL3_MT_FINISHED 20
#define DTLS1_HM_FRAGMENT_RETRY -1

struct hm_header_st {
    unsigned char type;
    unsigned long msg_len;
    unsigned short seq;
    unsigned long frag_off;
    unsigned long frag_len;
};

typedef struct hm_fragment_st {
    struct hm_header_st msg_header;
    unsigned char *fragment;
} hm_fragment;

typedef struct pitem_st {
    unsigned char seq[8];
    hm_fragment *frag;
    struct pitem_st *next;
} pitem;

typedef struct pqueue_st {
    pitem *head;
} pqueue;

typedef struct ssl_method_st {
    int (*ssl_read_bytes)(void *, int, void *, int, int);
} SSL_METHOD;

typedef struct dtls1_state_st {
    pqueue *buffered_messages;
    unsigned short handshake_read_seq;
} DTLS1_STATE;

typedef struct ssl_st {
    SSL_METHOD *method;
    DTLS1_STATE *d1;
} SSL;

static inline void OPENSSL_assert(int condition) { (void)condition; }