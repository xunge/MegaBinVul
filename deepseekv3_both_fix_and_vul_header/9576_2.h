#include <string.h>

#define n2s(c,s)  ((s=(((unsigned int)(c[0]))<< 8)| \
                    (((unsigned int)(c[1]))    )),c+=2)

#define SSL_ST_READ_HEADER 0x01
#define SSL_ST_READ_BODY   0x02
#define DTLS1_RT_HEADER_LENGTH 13
#define SSL3_RT_HEADER 0x1001
#define SSL3_RT_HANDSHAKE 0x16
#define SSL3_MT_CLIENT_HELLO 1
#define SSL3_RT_MAX_ENCRYPTED_LENGTH 16384

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

typedef struct ssl_st {
    int rstate;
    int packet_length;
    unsigned char *packet;
    struct ssl3_state_st *s3;
    struct dtls1_state_st *d1;
    int first_packet;
    unsigned short version;
    void (*msg_callback)(int, int, int, const void *, size_t, void *, void *);
    void *msg_callback_arg;
    int in_handshake;
    void *rbio;
} SSL;

typedef struct ssl3_state_st {
    SSL3_RECORD rrec;
    struct {
        int len;
    } rbuf;
    unsigned char read_sequence[8];
} ssl3_state_st;

typedef struct dtls1_state_st {
    int listen;
    struct dtls1_record_data_st *unprocessed_rcds;
} dtls1_state_st;

int dtls1_process_buffered_records(SSL *s);
int dtls1_get_processed_record(SSL *s);
int ssl3_read_n(SSL *s, int n, int max, int extend);
DTLS1_BITMAP *dtls1_get_bitmap(SSL *s, SSL3_RECORD *rr, unsigned int *is_next_epoch);
int BIO_dgram_is_sctp(void *rbio);
void *SSL_get_rbio(SSL *s);
int dtls1_record_replay_check(SSL *s, DTLS1_BITMAP *bitmap);
int SSL_in_init(SSL *s);
void dtls1_buffer_record(SSL *s, void *unprocessed_rcds, unsigned char *seq_num);
int dtls1_process_record(SSL *s);