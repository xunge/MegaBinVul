#include <stdlib.h>
#include <string.h>

typedef struct SSL3_BUFFER_st {
    unsigned char *buf;
    size_t len;
    size_t offset;
    size_t capacity;
    size_t left;
} SSL3_BUFFER;

typedef struct SSL3_RECORD_st {
    int type;
    unsigned int length;
    unsigned char *data;
    unsigned int off;
    unsigned char *input;
    unsigned int epoch;
    unsigned char seq_num[8];
} SSL3_RECORD;

typedef struct SSL3_STATE_st {
    SSL3_BUFFER rbuf;
    SSL3_RECORD rrec;
} SSL3_STATE;

typedef struct SSL_st {
    unsigned char *packet;
    unsigned int packet_length;
    SSL3_STATE *s3;
    int state;
} SSL;

typedef struct DTLS1_RECORD_DATA_st {
    unsigned char *packet;
    unsigned int packet_length;
    SSL3_BUFFER rbuf;
    SSL3_RECORD rrec;
    void *recordinfo;
} DTLS1_RECORD_DATA;

typedef struct pqueue_st pqueue;
typedef struct pitem_st {
    unsigned char *priority;
    void *data;
    struct pitem_st *next;
} pitem;

typedef struct record_pqueue_st {
    pqueue *q;
} record_pqueue;

#define OPENSSL_malloc malloc
#define OPENSSL_free free
#define SSLerr(a,b)
#define SSL_F_DTLS1_BUFFER_RECORD 0
#define ERR_R_INTERNAL_ERROR 0
#define OPENSSL_NO_SCTP
#define BIO_dgram_is_sctp(a) 0
#define SSL_get_rbio(a) NULL
#define BIO_CTRL_DGRAM_SCTP_GET_RCVINFO 0
#define BIO_ctrl(a,b,c,d) 0

pitem *pitem_new(unsigned char *priority, void *data);
void pitem_free(pitem *item);
int pqueue_size(pqueue *q);
int pqueue_insert(pqueue *q, pitem *item);
int ssl3_setup_buffers(SSL *s);