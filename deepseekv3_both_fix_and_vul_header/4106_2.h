#include <stdio.h>
#include <stdlib.h>

typedef struct bio_st BIO;
typedef struct ssl_st SSL;

typedef struct SRP_user_pwd_st {
    char *info;
    char *N;
    char *g;
    char *s;
    char *v;
} SRP_user_pwd;

typedef struct srpsrvparm_st {
    char *login;
    SRP_user_pwd *user;
} srpsrvparm;

#define MS_CALLBACK
#define SSL3_AL_FATAL 0
#define SSL_AD_INTERNAL_ERROR 0
#define SSL_ERROR_NONE 0

extern BIO *bio_err;

char *SSL_get_srp_username(SSL *s);
int SSL_set_srp_server_param(SSL *ssl, char *N, char *g, char *salt, char *v, char *info);
int BIO_printf(BIO *bio, const char *format, ...);