#include <stdlib.h>

#define X509_V_FLAG_ALLOW_PROXY_CERTS 0x10
#define X509_V_FLAG_IGNORE_CRITICAL 0x1
#define X509_V_FLAG_X509_STRICT 0x20

#define X509_PURPOSE_CRL_SIGN 6

#define EXFLAG_CRITICAL 0x1000
#define EXFLAG_PROXY 0x400
#define EXFLAG_CA 0x10
#define EXFLAG_SI 0x20

#define X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION 1
#define X509_V_ERR_PROXY_CERTIFICATES_NOT_ALLOWED 2
#define X509_V_ERR_INVALID_CA 3
#define X509_V_ERR_INVALID_NON_CA 4
#define X509_V_ERR_UNSPECIFIED 5
#define X509_V_ERR_EC_KEY_EXPLICIT_PARAMS 6
#define X509_V_ERR_INVALID_EXTENSION 7
#define X509_V_ERR_PATH_LENGTH_EXCEEDED 8
#define X509_V_ERR_PROXY_PATH_LENGTH_EXCEEDED 9
#define X509_V_OK 0

typedef struct X509_STORE_CTX X509_STORE_CTX;
typedef struct X509 X509;
typedef struct stack_st_X509 STACK_OF_X509;

struct X509_STORE_CTX {
    STACK_OF_X509 *chain;
    struct X509_STORE_CTX *parent;
    struct {
        unsigned long flags;
        int purpose;
    } *param;
    int error;
};

struct X509 {
    int ex_flags;
    int ex_pathlen;
    int ex_pcpathlen;
};

struct stack_st_X509 {
    int dummy;
};

static int sk_X509_num(STACK_OF_X509 *sk) { return 0; }
static X509 *sk_X509_value(STACK_OF_X509 *sk, int i) { return NULL; }
static int X509_check_ca(X509 *x) { return 0; }
static int verify_cb_cert(X509_STORE_CTX *ctx, X509 *x, int i, int err) { return 0; }
static int check_purpose(X509_STORE_CTX *ctx, X509 *x, int purpose, int i, int must_be_ca) { return 0; }
static int check_curve(X509 *x) { return 0; }