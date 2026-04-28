typedef int krb5_error_code;

#define NON_TGT_OPTION 0
#define KDC_OPT_ENC_TKT_IN_SKEY 0
#define KRB5KDC_ERR_BADOPTION 0
#define KRB5KDC_ERR_SERVER_NOMATCH 0
#define TKT_FLG_FORWARDABLE 0
#define KRB5_TKT_NOT_FORWARDABLE 0

typedef struct krb5_db_entry {
    void *princ;
} krb5_db_entry;

typedef struct krb5_enc_tkt_part {
    int flags;
    void *client;
} krb5_enc_tkt_part;

typedef struct krb5_kdc_req {
    int kdc_options;
} krb5_kdc_req;

typedef void *krb5_const_principal;
typedef struct kdc_realm_t kdc_realm_t;
typedef struct krb5_context krb5_context;

extern krb5_context *kdc_context;

int krb5_principal_compare(void *, void *, void *);
int isflagset(int, int);
krb5_error_code check_allowed_to_delegate_to(void *, void *, void *, void *);