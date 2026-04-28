#include <stdlib.h>
#include <string.h>

typedef int krb5_error_code;
typedef int krb5_int32;

#define KRB5KDC_ERR_S_PRINCIPAL_UNKNOWN 0
#define ENOMEM 12

typedef struct krb5_data {
    int length;
    char *data;
} krb5_data;

typedef struct krb5_principal {
    krb5_data realm;
} krb5_principal;

typedef struct krb5_kdc_req {
    krb5_principal *server;
} krb5_kdc_req;

typedef struct kdc_realm_t {
    // placeholder structure
} kdc_realm_t;

extern void *kdc_context;

static int is_referral_req(kdc_realm_t *kdc_active_realm, krb5_kdc_req *request);
static char *data2string(void *component);
static void *krb5_princ_component(void *context, krb5_principal *princ, int n);
static int krb5_get_host_realm(void *context, char *hostname, char ***realms);
static void kdc_err(void *context, int retval, const char *msg);
static int data_eq_string(krb5_data d, const char *s);
static int krb5_build_principal(void *context, krb5_principal **princ, int len, char *data, const char *s1, const char *s2, char *null);
static void krb5_free_host_realm(void *context, char **realms);