#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct pitem_st {
    void *data;
    struct pitem_st *next;
} pitem;

typedef struct pqueue_st {
    pitem *head;
    pitem *tail;
    int count;
} pqueue;

typedef struct dtls1_record_data_st {
    unsigned char *packet;
    unsigned int packet_length;
    void *rrec;
    void *recordinfo;
} DTLS1_RECORD_DATA;

typedef struct hm_header_st {
    unsigned char type;
    unsigned long msg_len;
    unsigned short seq;
    unsigned long frag_off;
    unsigned long frag_len;
} hm_header;

typedef struct ccs_header_st {
    unsigned char type;
    unsigned short seq;
    unsigned char epoch;
} ccs_header;

typedef struct ssl3_record_st {
    unsigned char type;
    unsigned char *data;
    unsigned int off;
    unsigned int length;
    unsigned int seq_num;
    unsigned char epoch;
} SSL3_RECORD;

struct ssl_st;

typedef struct ssl3_state_st {
    SSL3_RECORD rrec;
    int change_cipher_spec;
    int in_read_app_data;
    unsigned long flags;
    int renegotiate;
    int fatal_alert;
    int warn_alert;
    struct {
        unsigned char *buf;
        unsigned int left;
    } rbuf;
    int total_renegotiations;
} SSL3_STATE;

typedef struct dtls1_state_st {
    unsigned char handshake_fragment[12];
    unsigned int handshake_fragment_len;
    unsigned char alert_fragment[7];
    unsigned int alert_fragment_len;
    int change_cipher_spec_ok;
    int listen;
    int handshake_read_seq;
    int shutdown_received;
    unsigned char r_epoch;
    struct {
        pqueue *q;
    } buffered_app_data;
} DTLS1_STATE;

typedef struct ssl_session_st {
    void *cipher;
} SSL_SESSION;

typedef struct ssl_ctx_st {
    void (*info_callback)(const struct ssl_st *, int, int);
} SSL_CTX;

typedef struct ssl_st {
    struct ssl3_state_st *s3;
    struct dtls1_state_st *d1;
    int state;
    int rstate;
    int rwstate;
    int shutdown;
    int in_handshake;
    int server;
    int version;
    int mode;
    struct ssl_session_st *session;
    struct ssl_ctx_st *ctx;
    int (*handshake_func)(struct ssl_st *);
    void (*msg_callback)(int, int, int, const void *, size_t, struct ssl_st *, void *);
    void *msg_callback_arg;
    void (*info_callback)(const struct ssl_st *, int, int);
    int new_session;
    int renegotiate;
    void *enc_read_ctx;
} SSL;

typedef struct bio_st BIO;

#define SSL_F_DTLS1_READ_BYTES 0
#define ERR_R_INTERNAL_ERROR 0
#define SSL_R_SSL_HANDSHAKE_FAILURE 0
#define SSL_R_APP_DATA_IN_HANDSHAKE 0
#define SSL_R_UNEXPECTED_RECORD 0
#define SSL_AD_UNEXPECTED_MESSAGE 0
#define SSL_AD_DECODE_ERROR 0
#define SSL_AD_ILLEGAL_PARAMETER 0
#define SSL_AD_REASON_OFFSET 0
#define SSL_R_BAD_HELLO_REQUEST 0
#define SSL_R_BAD_CHANGE_CIPHER_SPEC 0
#define SSL_R_UNKNOWN_ALERT_TYPE 0

#define SSL3_RT_APPLICATION_DATA 0x17
#define SSL3_RT_HANDSHAKE 0x16
#define SSL3_RT_CHANGE_CIPHER_SPEC 0x14
#define SSL3_RT_ALERT 0x15
#define TLS1_RT_HEARTBEAT 0x18
#define SSL3_MT_CCS 1
#define SSL3_MT_HELLO_REQUEST 0
#define SSL3_MT_FINISHED 20
#define SSL_AD_CLOSE_NOTIFY 0
#define SSL3_AL_FATAL 2

#define DTLS1_HM_HEADER_LENGTH 12
#define DTLS1_AL_HEADER_LENGTH 2
#define DTLS1_CCS_HEADER_LENGTH 1

#define SSL_ST_OK 0x03
#define SSL_ST_READ_HEADER 0x10
#define SSL_ST_READ_BODY 0x11
#define SSL_ST_BEFORE 0x20
#define SSL_ST_ACCEPT 0x21
#define SSL_ST_CONNECT 0x22
#define SSL_ST_MASK 0x0F

#define SSL_NOTHING 1
#define SSL_READING 2

#define SSL_CB_READ_ALERT 0x1000

#define DTLS1_SCTP_ST_SR_READ_SOCK 0
#define DTLS1_SCTP_ST_CR_READ_SOCK 0

#define DTLS1_BAD_VER 0
#define TLS1_VERSION 0x0301

#define SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS 0x0001
#define SSL_MODE_AUTO_RETRY 0x0004

#define BIO_CTRL_DGRAM_SCTP_SET_RCVINFO 0
#define BIO_CTRL_DGRAM_SCTP_AUTH_CCS_RCVD 0

#define SSL_RECEIVED_SHUTDOWN 1
#define SSL_SENT_SHUTDOWN 2
#define SSL3_CC_READ 1

#define SSL3_ST_CW_CLNT_HELLO_A 0x210
#define SSL3_ST_CR_SRVR_HELLO_A 0x220
#define SSL3_ST_SW_HELLO_REQ_A 0x230
#define SSL3_ST_SR_CLNT_HELLO_A 0x240

#define OPENSSL_NO_SCTP
#define OPENSSL_NO_HEARTBEATS
#define OPENSSL_NO_TLS

void SSLerr(int f, int r);
int SSL_in_init(SSL *s);
int BIO_dgram_is_sctp(BIO *bio);
int BIO_dgram_sctp_msg_waiting(BIO *bio);
BIO *SSL_get_rbio(SSL *s);
BIO *SSL_get_wbio(SSL *s);
void BIO_clear_retry_flags(BIO *bio);
void BIO_set_retry_read(BIO *bio);
int BIO_ctrl(BIO *bp, int cmd, long larg, void *parg);
void *OPENSSL_free(void *ptr);
int ssl3_setup_buffers(SSL *s);
int have_handshake_fragment(SSL *s, int type, unsigned char *buf, int len, int peek);
int dtls1_handle_timeout(SSL *s);
int dtls1_get_record(SSL *s);
int dtls1_read_failed(SSL *s, int ret);
void dtls1_copy_record(SSL *s, pitem *item);
void pitem_free(pitem *item);
pitem *pqueue_pop(pqueue *pq);
int dtls1_buffer_record(SSL *s, void *queue, unsigned int seq_num);
int SSL_is_init_finished(SSL *s);
int ssl3_renegotiate(SSL *s);
int ssl3_renegotiate_check(SSL *s);
void dtls1_reset_seq_numbers(SSL *s, int direction);
int dtls1_check_timeout_num(SSL *s);
void dtls1_retransmit_buffered_messages(SSL *s);
void dtls1_get_message_header(unsigned char *data, hm_header *msg_hdr);
void dtls1_get_ccs_header(unsigned char *data, ccs_header *ccs_hdr);
int ssl3_do_change_cipher_spec(SSL *s);
void ssl3_send_alert(SSL *s, int level, int desc);
int BIO_snprintf(char *buf, size_t n, const char *format, ...);
void ERR_add_error_data(int num, ...);
void SSL_CTX_remove_session(SSL_CTX *ctx, SSL_SESSION *session);
void dtls1_process_heartbeat(SSL *s);