#include <stddef.h>

#define DTLS1_HM_HEADER_LENGTH 12
#define SSL3_RT_HANDSHAKE 22
#define SSL3_MT_HELLO_REQUEST 0
#define SSL_AD_UNEXPECTED_MESSAGE 10
#define SSL3_AD_ILLEGAL_PARAMETER 47
#define SSL3_AL_FATAL 2
#define SSL_READING 1
#define SSL_F_DTLS1_GET_MESSAGE_FRAGMENT 1
#define SSL_R_UNEXPECTED_MESSAGE 1

struct hm_header_st {
    unsigned char type;
    unsigned long msg_len;
    unsigned short seq;
    unsigned long frag_off;
    unsigned long frag_len;
};

struct ssl_method_st {
    int (*ssl_read_bytes)(void*, int, unsigned char*, int, int);
};

struct ssl_buffer_st {
    void *data;
};

struct dtls1_state_st {
    unsigned short handshake_read_seq;
    int listen;
    struct hm_header_st r_msg_hdr;
};

typedef struct ssl_st {
    struct ssl_method_st *method;
    int rwstate;
    int init_num;
    struct ssl_buffer_st *init_buf;
    int state;
    int server;
    struct dtls1_state_st *d1;
    long version;
    void *msg_callback_arg;
    void (*msg_callback)(int, long, int, const void*, size_t, void*, void*);
} SSL;

void SSLerr(int f, int r);
void ssl3_send_alert(SSL *s, int level, int desc);
long dtls1_retrieve_buffered_fragment(SSL *s, long max, int *ok);
void dtls1_get_message_header(const unsigned char *wire, struct hm_header_st *msg_hdr);
long dtls1_process_out_of_seq_message(SSL *s, struct hm_header_st *msg_hdr, int *ok);
long dtls1_reassemble_fragment(SSL *s, struct hm_header_st *msg_hdr, int *ok);
int dtls1_preprocess_fragment(SSL *s, struct hm_header_st *msg_hdr, long max);