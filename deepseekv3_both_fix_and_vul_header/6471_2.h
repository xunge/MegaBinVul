#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DN_BUF_LEN 1024
#define ENOMEM 12  /* Value from errno.h */

typedef int krb5_error_code;
typedef void *krb5_context;
typedef void *krb5_principal;

typedef struct pkinit_cert_matching_data {
    char *subject_dn;
    char *issuer_dn;
    krb5_principal *sans;
    unsigned int ku_bits;
    unsigned int eku_bits;
} pkinit_cert_matching_data;

typedef struct pkinit_plg_crypto_context *pkinit_plg_crypto_context;
typedef struct pkinit_req_crypto_context *pkinit_req_crypto_context;
typedef struct X509 X509;
typedef struct X509_NAME X509_NAME;

#define XN_FLAG_SEP_COMMA_PLUS 0

extern X509_NAME *X509_get_subject_name(X509 *cert);
extern X509_NAME *X509_get_issuer_name(X509 *cert);
extern int X509_NAME_oneline_ex(X509_NAME *name, char *buf, unsigned int *size, int flags);

extern krb5_error_code crypto_retrieve_X509_sans(krb5_context, pkinit_plg_crypto_context, pkinit_req_crypto_context, X509 *, krb5_principal **, krb5_principal **, void **);
extern krb5_error_code crypto_retrieve_X509_key_usage(krb5_context, pkinit_plg_crypto_context, pkinit_req_crypto_context, X509 *, unsigned int *, unsigned int *);
extern void crypto_cert_free_matching_data(krb5_context, pkinit_cert_matching_data *);