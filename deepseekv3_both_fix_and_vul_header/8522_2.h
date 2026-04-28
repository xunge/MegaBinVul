#include <limits.h>
#include <stddef.h>

#define SSL3_RT_HANDSHAKE 22
#define SSL3_RT_CHANGE_CIPHER_SPEC 20
#define SSL3_MT_CCS 1
#define SSL3_MT_CHANGE_CIPHER_SPEC 1
#define SSL3_MT_HELLO_REQUEST 0
#define SSL3_HM_HEADER_LENGTH 4
#define SSL_AD_UNEXPECTED_MESSAGE 10
#define SSL_AD_ILLEGAL_PARAMETER 47
#define SSL3_AL_FATAL 2
#define SSL_F_TLS_GET_MESSAGE_HEADER 0
#define SSL_R_BAD_CHANGE_CIPHER_SPEC 0
#define SSL_R_CCS_RECEIVED_EARLY 0
#define SSL_R_EXCESSIVE_MESSAGE_SIZE 0
#define ERR_R_BUF_LIB 0
#define SSL_READING 1

typedef struct ssl_method_st {
    int (*ssl_read_bytes)(void*, int, int*, unsigned char*, int, int);
} SSL_METHOD;

typedef struct buf_mem_st {
    char *data;
} BUF_MEM;

typedef struct ssl3_state_st {
    struct {
        int message_type;
        unsigned long message_size;
    } tmp;
} SSL3_STATE;

typedef struct record_layer_st {
    int dummy;
} RECORD_LAYER;

typedef struct ssl_st {
    int init_num;
    BUF_MEM *init_buf;
    char *init_msg;
    int rwstate;
    const SSL_METHOD *method;
    SSL3_STATE *s3;
    RECORD_LAYER rlayer;
    int server;
    void (*msg_callback)(int, int, int, const void*, size_t, void*, void*);
    void *msg_callback_arg;
    int version;
} SSL;

static inline int RECORD_LAYER_is_sslv2_record(RECORD_LAYER *rl) { return 0; }
static inline unsigned long RECORD_LAYER_get_rrec_length(RECORD_LAYER *rl) { return 0; }
static inline int BUF_MEM_grow_clean(BUF_MEM *buf, int len) { return 1; }
static inline void n2l3(unsigned char *p, unsigned long *l) {
    *l = (p[0] << 16) | (p[1] << 8) | p[2];
}
static inline void SSLerr(int f, int r) {}
static inline void ssl3_send_alert(SSL *s, int level, int desc) {}