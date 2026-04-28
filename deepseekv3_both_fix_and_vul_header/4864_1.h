#include <string.h>
#include <stdlib.h>

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
    unsigned char *reassembly;
} hm_fragment;

typedef struct pitem_st {
    void *data;
} pitem;

typedef struct ssl_st {
    struct {
        void *buffered_messages;
    } *d1;
    unsigned long max_cert_list;
    struct {
        int (*ssl_read_bytes)(void *, int, void *, int, int);
    } *method;
} SSL;

#define DTLS1_HM_HEADER_LENGTH 12
#define SSL3_RT_MAX_ENCRYPTED_LENGTH 16384
#define SSL3_RT_HANDSHAKE 22
#define DTLS1_HM_FRAGMENT_RETRY 0

#define RSMBLY_BITMASK_MARK(a, b, c) 
#define RSMBLY_BITMASK_IS_COMPLETE(a, b, c) 

void *pqueue_find(void *queue, unsigned char *seq);
void *pitem_new(unsigned char *seq, void *data);
void pqueue_insert(void *queue, void *item);
void dtls1_hm_fragment_free(void *frag);
void *dtls1_hm_fragment_new(unsigned long len, int alloc);
void OPENSSL_free(void *ptr);