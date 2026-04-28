#include <string.h>

typedef struct ssl3_buffer_st {
    unsigned char *buf;
    size_t len;
    int offset;
    int left;
} SSL3_BUFFER;

typedef struct ssl3_state_st {
    SSL3_BUFFER rbuf;
} SSL3_STATE;

typedef struct bio_st BIO;

typedef struct ssl_st {
    SSL3_STATE *s3;
    unsigned char *packet;
    unsigned int packet_length;
    int read_ahead;
    BIO *rbio;
    int rwstate;
    int mode;
} SSL;

#define SSL_F_SSL3_READ_N 0
#define SSL_R_READ_BIO_NOT_SET 0
#define ERR_R_INTERNAL_ERROR 0
#define SSL_IS_DTLS(s) 0
#define SSL3_RT_HEADER_LENGTH 0
#define SSL3_RT_APPLICATION_DATA 0
#define SSL3_ALIGN_PAYLOAD 0
#define SSL_MODE_RELEASE_BUFFERS 0
#define SSL_READING 1
#define SSL_NOTHING 0

void SSLerr(int f, int r);
int BIO_read(BIO *bio, void *buf, int len);
int ssl3_setup_read_buffer(SSL *s);
void ssl3_release_read_buffer(SSL *s);
void clear_sys_error(void);