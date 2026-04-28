#include <string.h>
#include <stdlib.h>

#define SSL2_ST_GET_CLIENT_HELLO_A 0
#define SSL2_ST_GET_CLIENT_HELLO_B 1
#define SSL2_ST_GET_CLIENT_HELLO_C 2
#define SSL2_MT_CLIENT_HELLO 1
#define SSL2_MT_ERROR 0
#define SSL2_PE_UNDEFINED_ERROR 0
#define SSL2_PE_NO_CERTIFICATE 2
#define SSL2_PE_NO_CIPHER 1
#define SSL_F_GET_CLIENT_HELLO 0
#define SSL_MAX_SSL_SESSION_ID_LENGTH 32
#define SSL2_MIN_CHALLENGE_LENGTH 16
#define SSL2_MAX_CHALLENGE_LENGTH 32
#define SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER 16777215
#define SSL2_SSL_SESSION_ID_LENGTH 16
#define SSL_OP_CIPHER_SERVER_PREFERENCE 0x00000001L
#define SSL_SSLV2 0x00000002L

#define SSL_R_READ_WRONG_PACKET_TYPE 100
#define SSL_R_PEER_ERROR 101
#define SSL_R_LENGTH_MISMATCH 102
#define SSL_R_INVALID_CHALLENGE_LENGTH 103
#define SSL_R_MESSAGE_TOO_LONG 104
#define SSL_R_BAD_SSL_SESSION_ID_LENGTH 105
#define SSL_R_NO_CERTIFICATE_SET 106
#define SSL_R_NO_CIPHER_MATCH 107
#define ERR_R_INTERNAL_ERROR 108
#define ERR_R_MALLOC_FAILURE 109

typedef struct SSL_CIPHER {
    unsigned long algorithm_ssl;
} SSL_CIPHER;

typedef struct STACK_OF_SSL_CIPHER {
    SSL_CIPHER **data;
    int num;
} STACK_OF_SSL_CIPHER;
#define STACK_OF(type) struct STACK_OF_##type
#define sk_SSL_CIPHER_num(st) ((st) ? (st)->num : 0)
#define sk_SSL_CIPHER_value(st, i) ((st)->data[i])
#define sk_SSL_CIPHER_find(st, val) (-1)
#define sk_SSL_CIPHER_delete(st, i) ((st)->num--, 1)
#define sk_SSL_CIPHER_dup(st) ((st) ? (STACK_OF_SSL_CIPHER*)memcpy(malloc(sizeof(STACK_OF_SSL_CIPHER)), (st), sizeof(STACK_OF_SSL_CIPHER)) : NULL)
#define sk_SSL_CIPHER_free(st) free(st)

typedef struct ssl2_state_st {
    unsigned char challenge[32];
    unsigned int challenge_length;
    struct {
        unsigned int cipher_spec_length;
        unsigned int session_id_length;
    } tmp;
} ssl2_state_st;

typedef struct ssl_session_st {
    STACK_OF_SSL_CIPHER *ciphers;
} ssl_session_st;

typedef struct ssl_st {
    int state;
    int first_packet;
    int version;
    int init_num;
    int hit;
    int options;
    struct {
        unsigned char *data;
    } *init_buf;
    ssl2_state_st *s2;
    ssl_session_st *session;
    void *cert;
    void (*msg_callback)(int, int, int, const void*, size_t, struct ssl_st*, void*);
    void *msg_callback_arg;
} SSL;

void SSLerr(int f, int r);
int ssl2_read(SSL *s, char *buf, int len);
int ssl2_part_read(SSL *s, int f, int i);
void ssl2_return_error(SSL *s, int code);
int ssl_get_new_session(SSL *s, int flag);
int ssl_get_prev_session(SSL *s, unsigned char *data, int len, void *arg);
STACK_OF_SSL_CIPHER *ssl_bytes_to_cipher_list(SSL *s, unsigned char *p, int len, STACK_OF_SSL_CIPHER **sk);
STACK_OF_SSL_CIPHER *SSL_get_ciphers(SSL *s);
void n2s(unsigned char **p, unsigned int *n);