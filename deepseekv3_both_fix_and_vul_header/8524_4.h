#include <stdlib.h>

typedef struct X509 X509;
typedef struct X509_CRL X509_CRL;
typedef struct X509_STORE_CTX X509_STORE_CTX;

struct X509_STORE_CTX {
    X509 *current_cert;
};

struct X509_CRL {
    int references;
    void *lastUpdate;
};

struct stack_st_X509_CRL {
    int dummy;
};
#define STACK_OF(type) struct stack_st_##type
#define sk_X509_CRL_num(st) ((st) ? 0 : 0)
#define sk_X509_CRL_value(st, i) NULL
#define CRYPTO_LOCK_X509_CRL 0
#define CRL_SCORE_VALID 0

static int ASN1_TIME_diff(int *day, int *sec, void *from, void *to) { return 0; }
static void *X509_CRL_get_lastUpdate(X509_CRL *crl) { return NULL; }
static int get_crl_score(X509_STORE_CTX *ctx, X509 **issuer, unsigned int *reasons, X509_CRL *crl, X509 *x) { return 0; }
static void get_delta_sk(X509_STORE_CTX *ctx, X509_CRL **pdcrl, int *pscore, X509_CRL *best_crl, STACK_OF(X509_CRL) *crls) {}
void X509_CRL_free(X509_CRL *crl) {}
void CRYPTO_add(int *ref, int amount, int type) {}