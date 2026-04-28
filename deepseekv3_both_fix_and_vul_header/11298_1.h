#include <stdint.h>
#include <stdlib.h>

typedef int krb5_error_code;
typedef void *krb5_context;
typedef void *krb5_certauth_moddata;
typedef void *krb5_const_principal;

struct _krb5_db_entry_new;
struct certauth_req_opts {
    void *plgctx;
    void *reqctx;
};

#define KRB5KDC_ERR_INCONSISTENT_KEY_PURPOSE 0
#define KRB5_PLUGIN_NO_HANDLE 0
#define TRACE_PKINIT_SERVER_EKU_REJECT(ctx)

krb5_error_code verify_client_eku(krb5_context context, void *plgctx, void *reqctx, int *valid_eku);