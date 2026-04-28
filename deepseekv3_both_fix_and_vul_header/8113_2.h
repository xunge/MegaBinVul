#include <stddef.h>
#include <time.h>

#define AS_INVALID_OPTIONS 0
#define KDC_ERR_BADOPTION 0
#define KRB_ERR_GENERIC 0
#define KDC_ERR_NAME_EXP 0
#define KDC_ERR_KEY_EXP 0
#define KDC_ERR_SERVICE_EXP 0
#define KDC_ERR_CANNOT_POSTDATE 0
#define KDC_ERR_POLICY 0
#define KDC_ERR_CLIENT_REVOKED 0
#define KDC_ERR_S_PRINCIPAL_UNKNOWN 0
#define KDC_ERR_MUST_USE_USER2USER 0
#define KRB5_PLUGIN_OP_NOTSUPP 0

#define KRB5_KDB_PWCHANGE_SERVICE 0
#define KRB5_KDB_REQUIRES_PWCHANGE 0
#define KRB5_KDB_DISALLOW_POSTDATED 0
#define KRB5_KDB_DISALLOW_PROXIABLE 0
#define KRB5_KDB_DISALLOW_ALL_TIX 0
#define KRB5_KDB_DISALLOW_SVR 0

#define KDC_OPT_ALLOW_POSTDATE 0x00000001
#define KDC_OPT_POSTDATED 0x00000002
#define KDC_OPT_PROXIABLE 0x00000010

extern int vague_errors;
extern void* kdc_context;

typedef struct kdc_realm_t kdc_realm_t;
typedef struct krb5_kdc_req {
    unsigned int kdc_options;
    void* client;
    void* server;
} krb5_kdc_req;
typedef struct krb5_db_entry {
    time_t expiration;
    time_t pw_expiration;
    int attributes;
    void* princ;
} krb5_db_entry;
typedef struct krb5_pa_data krb5_pa_data;
typedef time_t krb5_timestamp;
typedef int krb5_error_code;

static inline int isflagset(int flags, int flag) {
    return (flags & flag) != 0;
}

static int check_anon(kdc_realm_t *realm, void* client, void* server) {
    return 0;
}

static int against_local_policy_as(krb5_kdc_req *request, krb5_db_entry client,
                                 krb5_db_entry server, krb5_timestamp kdc_time,
                                 const char **status, krb5_pa_data ***e_data) {
    return 0;
}

static int errcode_to_protocol(krb5_error_code code) {
    return code;
}

static int krb5_db_check_policy_as(void* context, krb5_kdc_req *request,
                                  krb5_db_entry *client, krb5_db_entry *server,
                                  krb5_timestamp kdc_time, const char **status,
                                  krb5_pa_data ***e_data) {
    return 0;
}