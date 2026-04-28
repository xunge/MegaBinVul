#include <stdlib.h>

typedef struct pitem_st {
    void *data;
    struct pitem_st *next;
} pitem;

typedef struct pqueue_st {
    pitem *head;
} pqueue;

typedef struct hm_fragment_st {
    // Add necessary fields here
} hm_fragment;

typedef struct dtls1_state_st {
    pqueue *buffered_messages;
    pqueue *sent_messages;
} dtls1_state_st;

typedef struct ssl_st {
    struct dtls1_state_st *d1;
} SSL;

void dtls1_hm_fragment_free(hm_fragment *frag);
pitem *pqueue_pop(pqueue *queue);
void pitem_free(pitem *item);