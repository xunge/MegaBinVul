#include <errno.h>
#include <stddef.h>

typedef int krb5_error_code;
typedef unsigned int krb5_ui_4;

typedef struct {
    char *data;
    int length;
} krb5_data;

typedef struct krb5_principal {
    krb5_data realm;
} *krb5_principal;

typedef struct kdc_realm_t kdc_realm_t;

extern kdc_realm_t *kdc_realmlist[];
extern kdc_realm_t *kdc_active_realm;
extern int kdc_numrealms;

kdc_realm_t *find_realm_data(char *data, krb5_ui_4 length);