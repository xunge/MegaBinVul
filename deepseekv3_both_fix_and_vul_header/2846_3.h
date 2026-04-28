#include <string.h>

typedef int krb5_error_code;
typedef int krb5_boolean;
typedef unsigned int krb5_flags;
typedef unsigned int krb5_timestamp;

struct krb5_pa_data;
struct krb5_principal_data;
struct krb5_keyblock {
    int dummy;
};

typedef struct krb5_db_entry {
    krb5_flags attributes;
    krb5_timestamp pw_expiration;
} krb5_db_entry;

typedef struct krb5_kdc_req {
    struct krb5_pa_data **padata;
    struct krb5_principal_data *server;
    int kdc_options;
} krb5_kdc_req;

typedef struct krb5_pa_s4u_x509_user {
    struct {
        struct krb5_principal_data *user;
    } user_id;
} krb5_pa_s4u_x509_user;

typedef struct kdc_realm_t kdc_realm_t;
typedef void* krb5_context;
typedef struct krb5_principal_data* krb5_principal;
typedef const struct krb5_principal_data* krb5_const_principal;
typedef struct krb5_pa_data krb5_pa_data;
typedef struct krb5_keyblock krb5_keyblock;

extern krb5_context kdc_context;

#define KRB5_PADATA_S4U_X509_USER 129
#define KRB5_PADATA_FOR_USER 130
#define KRB5KDC_ERR_C_PRINCIPAL_UNKNOWN 6
#define KRB5KDC_ERR_S_PRINCIPAL_UNKNOWN 7
#define KRB5KDC_ERR_BADOPTION 8
#define KRB5KDC_ERR_POLICY 9
#define KRB5_KDB_NOENTRY (-1765328243)
#define KRB5_KDB_FLAG_INCLUDE_PAC (1 << 0)
#define KRB5_KDB_REQUIRES_PWCHANGE (1 << 0)
#define KRB5_NT_SRV_HST 5
#define KRB5_NT_ENTERPRISE_PRINCIPAL 10
#define KRB5_PRINCIPAL_COMPARE_IGNORE_REALM (1 << 0)
#define KRB5_PRINCIPAL_COMPARE_ENTERPRISE (1 << 1)
#define AS_INVALID_OPTIONS (0x3F)

static inline void clear(krb5_flags *attributes, krb5_flags flag) {
    *attributes &= ~flag;
}

krb5_error_code krb5int_find_pa_data(krb5_context, krb5_pa_data **, int);
krb5_error_code kdc_process_s4u_x509_user(krb5_context, krb5_kdc_req *,
                                         krb5_pa_data *, krb5_keyblock *,
                                         krb5_keyblock *,
                                         krb5_pa_s4u_x509_user **,
                                         const char **);
krb5_error_code kdc_process_for_user(kdc_realm_t *, krb5_pa_data *,
                                    krb5_keyblock *, krb5_pa_s4u_x509_user **,
                                    const char **);
krb5_error_code krb5_db_get_principal(krb5_context, krb5_const_principal,
                                      int, krb5_db_entry **);
void krb5_db_free_principal(krb5_context, krb5_db_entry *);
void krb5_free_pa_data(krb5_context, krb5_pa_data **);
krb5_error_code validate_as_request(kdc_realm_t *, krb5_kdc_req *,
                                   krb5_db_entry, krb5_db_entry,
                                   krb5_timestamp, const char **,
                                   krb5_pa_data ***);
int krb5_princ_type(krb5_context, krb5_const_principal);
int krb5_princ_size(krb5_context, krb5_const_principal);
krb5_boolean krb5_principal_compare_flags(krb5_context, krb5_const_principal,
                                         krb5_const_principal, int);
krb5_boolean is_cross_tgs_principal(krb5_const_principal);
krb5_boolean is_local_principal(kdc_realm_t *, krb5_const_principal);