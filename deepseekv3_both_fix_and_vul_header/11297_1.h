#include <stdlib.h>
#include <errno.h>

typedef int krb5_error_code;
typedef void *krb5_context;
typedef void *krb5_principal;
typedef const void *krb5_const_principal;

typedef struct pkinit_kdc_context {
    void *cryptoctx;
    void *idctx;
    struct {
        int allow_upn;
    } *opts;
} *pkinit_kdc_context;

typedef struct pkinit_kdc_req_context {
    void *cryptoctx;
} *pkinit_kdc_req_context;

typedef struct krb5_kdcpreauth_callbacks {
    int (*match_client)(krb5_context, void *, krb5_principal);
} *krb5_kdcpreauth_callbacks;

typedef void *krb5_kdcpreauth_rock;

#define TRACE_PKINIT_SERVER_NO_SAN(ctx)
#define TRACE_PKINIT_SERVER_MATCHING_SAN_FOUND(ctx)
#define TRACE_PKINIT_SERVER_MATCHING_UPN_FOUND(ctx)

#define pkiDebug(fmt, ...)

#define KRB5KDC_ERR_CLIENT_NAME_MISMATCH 1
#define ENOENT 2

static krb5_error_code crypto_retrieve_cert_sans(krb5_context context,
    void *cryptoctx1, void *cryptoctx2, void *idctx,
    krb5_principal **princs, krb5_principal **upns, void *unused);