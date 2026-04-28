#include <stdlib.h>
#include <string.h>

#define TLS1_RT_HEARTBEAT 24
#define TLS1_HB_REQUEST 1
#define TLS1_HB_RESPONSE 2
#define SSL3_RT_MAX_PLAIN_LENGTH 16384

#define n2s(c,s) (s = ((unsigned int)((c)[0]) << 8) | (unsigned int)((c)[1]), (c) += 2)
#define s2n(s,c) ((c)[0] = (unsigned char)(((s) >> 8) & 0xff), (c)[1] = (unsigned char)((s) & 0xff), (c) += 2)

typedef struct SSL3_RECORD {
    unsigned char *data;
    unsigned int length;
} SSL3_RECORD;

typedef struct SSL3_STATE {
    SSL3_RECORD rrec;
} SSL3_STATE;

typedef struct SSL {
    SSL3_STATE *s3;
    void (*msg_callback)(int, int, int, const void*, size_t, void*, void*);
    void *msg_callback_arg;
    int version;
    unsigned int tlsext_hb_seq;
    int tlsext_hb_pending;
} SSL;

void *OPENSSL_malloc(size_t size) { return malloc(size); }
void OPENSSL_free(void *ptr) { free(ptr); }
int RAND_pseudo_bytes(unsigned char *buf, int num) { return 0; }
int dtls1_write_bytes(SSL *s, int type, const void *buf, int len) { return 0; }
void dtls1_stop_timer(SSL *s) {}