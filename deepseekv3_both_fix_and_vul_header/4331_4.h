#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct ssl_session_st {
    long time;
} SSL_SESSION;

typedef struct ssl_st {
    SSL_SESSION *session;
} SSL;

typedef struct x509_st {
    // dummy X509 structure
} X509;

typedef struct server {
    void *server_session;
    SSL *ssl;
    char *hostname;
    int accept_invalid_cert;
} server;

struct cert_info {
    char *subject_word[32];
    char *issuer_word[32];
    char *algorithm;
    int algorithm_bits;
    char *sign_algorithm;
    char *notbefore;
    char *notafter;
};

struct chiper_info {
    char *version;
    char *chiper;
    unsigned int chiper_bits;
};

struct prefs {
    int hex_net_auto_reconnectonfail;
};

extern struct prefs prefs;
extern void *g_sess;

#define SSLTMOUT 300
#define XP_TE_CONNFAIL 0
#define XP_TE_SSLMESSAGE 1
#define SSL_R_WRONG_VERSION_NUMBER 0
#define X509_V_OK 0
#define X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY 1
#define X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE 2
#define X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT 3
#define X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN 4
#define X509_V_ERR_CERT_HAS_EXPIRED 5

#define EMIT_SIGNAL(signal, session, buf, a, b, c, d)
#define PrintText(session, text)
#define _SSL_get_cert_info(cert_info, ssl) 0
#define _SSL_get_cipher_info(ssl) NULL
#define _SSL_check_hostname(cert, hostname) 0
#define SSL_connect(ssl) 0
#define ERR_get_error() 0
#define ERR_error_string(err, buf)
#define ERR_GET_REASON(err) 0
#define SSL_is_init_finished(ssl) 0
#define SSL_get_verify_result(ssl) 0
#define X509_verify_cert_error_string(err) ""
#define SSL_get_peer_certificate(ssl) NULL
#define server_cleanup(serv)
#define auto_reconnect(serv, b, i)
#define server_stopconnecting(serv)
#define server_connected(serv)