#include <string.h>
#include <errno.h>

typedef int krb5_error_code;
typedef void* krb5_context;
typedef struct krb5_creds krb5_creds;
typedef struct krb5_data krb5_data;
typedef struct krb5_principal *krb5_principal;
typedef int krb5_preauthtype;
typedef struct krb5_get_init_creds_opt krb5_get_init_creds_opt;
typedef struct krb5_principal krb5_principal_data;

#define KRB5_PADATA_S4U_X509_USER 0
#define KRB5_NT_ENTERPRISE_PRINCIPAL 0
#define KV5M_PRINCIPAL 0
#define KRB5_PREAUTH_FAILED 0
#define KRB5KDC_ERR_KEY_EXP 0

struct krb5_data {
    void *data;
    size_t length;
};

struct krb5_principal {
    int magic;
    void *realm;
    void *data;
    size_t length;
    int type;
};

struct krb5_creds {
    struct krb5_principal *client;
    struct krb5_principal *server;
};

struct krb5_s4u_userid {
    struct krb5_data subject_cert;
    krb5_principal user;
};

int krb5_principal_compare(krb5_context, krb5_principal, krb5_principal);
krb5_principal krb5_anonymous_principal(void);
krb5_error_code krb5_copy_principal(krb5_context, krb5_principal, krb5_principal*);
krb5_error_code krb5_get_init_creds_opt_alloc(krb5_context, krb5_get_init_creds_opt**);
void krb5_get_init_creds_opt_set_tkt_life(krb5_get_init_creds_opt*, int);
void krb5_get_init_creds_opt_set_renew_life(krb5_get_init_creds_opt*, int);
void krb5_get_init_creds_opt_set_forwardable(krb5_get_init_creds_opt*, int);
void krb5_get_init_creds_opt_set_proxiable(krb5_get_init_creds_opt*, int);
void krb5_get_init_creds_opt_set_canonicalize(krb5_get_init_creds_opt*, int);
void krb5_get_init_creds_opt_set_preauth_list(krb5_get_init_creds_opt*, krb5_preauthtype*, int);
krb5_error_code k5_get_init_creds(krb5_context, krb5_creds*, struct krb5_principal*, void*, void*, int, void*, krb5_get_init_creds_opt*, void*, struct krb5_s4u_userid*, int*, void*);
void krb5_free_cred_contents(krb5_context, krb5_creds*);
void krb5_get_init_creds_opt_free(krb5_context, krb5_get_init_creds_opt*);
void krb5_free_principal(krb5_context, krb5_principal);
void* krb5_get_as_key_noop;

typedef struct krb5_s4u_userid krb5_s4u_userid;