#include <stddef.h>

typedef enum WORK_STATE {
    WORK_ERROR,
    WORK_FINISHED_CONTINUE
} WORK_STATE;

typedef struct OSSL_STATEM {
    int hand_state;
    int use_timer;
} OSSL_STATEM;

typedef struct SSL_SESSION {
    void *cipher;
} SSL_SESSION;

typedef struct SSL3_STATE {
    struct {
        void *new_cipher;
    } tmp;
} SSL3_STATE;

typedef struct SSL3_ENC_METHOD {
    int (*setup_key_block)(void *s);
} SSL3_ENC_METHOD;

typedef struct SSL_METHOD {
    SSL3_ENC_METHOD *ssl3_enc;
} SSL_METHOD;

typedef struct SSL {
    OSSL_STATEM statem;
    int shutdown;
    SSL_SESSION *session;
    SSL3_STATE *s3;
    SSL_METHOD *method;
} SSL;

int SSL_IS_DTLS(const SSL *s);
void dtls1_clear_record_buffer(SSL *s);
void *SSL_get_wbio(const SSL *s);
int BIO_dgram_is_sctp(void *bio);
WORK_STATE dtls_wait_for_dry(SSL *s);
void ossl_statem_set_error(SSL *s);
WORK_STATE tls_finish_handshake(SSL *s, WORK_STATE wst);

#define TLS_ST_SW_HELLO_REQ 0
#define DTLS_ST_SW_HELLO_VERIFY_REQUEST 1
#define TLS_ST_SW_SRVR_HELLO 2
#define TLS_ST_SW_SRVR_DONE 3
#define TLS_ST_SW_SESSION_TICKET 4
#define TLS_ST_SW_CHANGE 5
#define TLS_ST_OK 6