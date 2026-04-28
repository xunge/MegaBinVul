#include <string.h>

#define DTLS1_RT_HEADER_LENGTH 13
#define SSL3_RT_MAX_ENCRYPTED_LENGTH 16384
#define SSL3_RT_HEADER 0
#define SSL3_RT_HANDSHAKE 22
#define SSL3_MT_CLIENT_HELLO 1
#define SSL_ST_READ_BODY 1
#define SSL_ST_READ_HEADER 2

typedef struct ssl3_record_st {
    unsigned char type;
    unsigned short epoch;
    unsigned short length;
    unsigned char seq_num[8];
} SSL3_RECORD;

typedef struct dtls1_bitmap_st {
    unsigned long map;
    unsigned long max_seq_num;
} DTLS1_BITMAP;

typedef struct dtls1_state_st {
    int listen;
    void *unprocessed_rcds;
} DTLS1_STATE;

typedef struct ssl3_state_st {
    SSL3_RECORD rrec;
    struct {
        int len;
    } rbuf;
    unsigned char read_sequence[8];
} SSL3_STATE;

typedef struct ssl_st {
    SSL3_STATE *s3;
    int rstate;
    unsigned int packet_length;
    unsigned char *packet;
    void (*msg_callback)(int, int, int, const void*, size_t, void*, void*);
    void *msg_callback_arg;
    int first_packet;
    unsigned short version;
    DTLS1_STATE *d1;
    int in_handshake;
    void *rbio;
} SSL;

#define n2s(c,s) (s = ((unsigned int)(c[0]) << 8) | (unsigned int)(c[1]), c += 2)

int dtls1_process_buffered_records(SSL *s);
int dtls1_get_processed_record(SSL *s);
int ssl3_read_n(SSL *s, int n, int max, int extend);
DTLS1_BITMAP *dtls1_get_bitmap(SSL *s, SSL3_RECORD *rr, unsigned int *is_next_epoch);
int dtls1_record_replay_check(SSL *s, DTLS1_BITMAP *bitmap);
int dtls1_buffer_record(SSL *s, void *queue, unsigned char *seq_num);
void dtls1_record_bitmap_update(SSL *s, DTLS1_BITMAP *bitmap);
int dtls1_process_record(SSL *s);
int SSL_in_init(SSL *s);
int BIO_dgram_is_sctp(void *bio);
void *SSL_get_rbio(SSL *s);