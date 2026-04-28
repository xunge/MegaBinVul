#include <string.h>

typedef struct ssl3_record_st {
    unsigned char type;
    unsigned short epoch;
    unsigned short length;
    unsigned char seq_num[8];
} SSL3_RECORD;

typedef struct ssl3_buffer_st {
    size_t len;
} SSL3_BUFFER;

typedef struct ssl3_state_st {
    SSL3_RECORD rrec;
    SSL3_BUFFER rbuf;
    unsigned char read_sequence[8];
} SSL3_STATE;

typedef struct dtls1_state_st {
    int listen;
    void *unprocessed_rcds;
} DTLS1_STATE;

typedef struct ssl_st {
    int rstate;
    size_t packet_length;
    unsigned char *packet;
    SSL3_STATE *s3;
    DTLS1_STATE *d1;
    int first_packet;
    unsigned short version;
    void (*msg_callback)(int, int, int, const void*, size_t, void*, void*);
    void *msg_callback_arg;
    int in_handshake;
} SSL;

typedef struct dtls1_bitmap_st {
    unsigned long map;
} DTLS1_BITMAP;

#define SSL_ST_READ_BODY 1
#define SSL_ST_READ_HEADER 2
#define DTLS1_RT_HEADER_LENGTH 13
#define SSL3_RT_MAX_ENCRYPTED_LENGTH 16384
#define SSL3_RT_HEADER 0
#define SSL3_RT_HANDSHAKE 1
#define SSL3_MT_CLIENT_HELLO 1

#define n2s(c,s) ((s=(((unsigned int)(c[0]))<<8)|(((unsigned int)(c[1])))),c+=2)

int dtls1_process_buffered_records(SSL *s);
int dtls1_get_processed_record(SSL *s);
int ssl3_read_n(SSL *s, int n, int max, int extend);
DTLS1_BITMAP *dtls1_get_bitmap(SSL *s, SSL3_RECORD *rr, unsigned int *is_next_epoch);
int BIO_dgram_is_sctp(void *bio);
void *SSL_get_rbio(SSL *s);
int dtls1_record_replay_check(SSL *s, DTLS1_BITMAP *bitmap);
int SSL_in_init(SSL *s);
void dtls1_buffer_record(SSL *s, void *queue, unsigned char *seq_num);
int dtls1_process_record(SSL *s);