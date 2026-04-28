#include <stddef.h>
#include <string.h>

typedef struct ssl_st SSL;
typedef struct ssl3_state_st SSL3_STATE;

#define TLSEXT_TYPE_server_name 0
#define TLS1_2_VERSION 0x0303

#define n2s(c,s) ((s)=((unsigned int)((c)[0])<<8)|(unsigned int)((c)[1]),(c)+=2)

struct ssl_st {
    SSL3_STATE *s3;
};

struct ssl3_state_st {
    int is_probably_safari;
};

unsigned int TLS1_get_client_version(const SSL *s);