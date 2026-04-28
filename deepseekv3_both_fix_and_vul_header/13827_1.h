#include <stdlib.h>

typedef void* gss_cred_id_t;
typedef int krb5_error_code;
typedef struct krb5_context_data *krb5_context;

typedef struct iakerb_ctx_t {
    gss_cred_id_t defcred;
    krb5_context k5c;
    int magic;
    int state;
    int count;
    int initiate;
    int established;
} *iakerb_ctx_id_t;

#define GSS_C_NO_CREDENTIAL NULL
#define KG_IAKERB_CONTEXT 0
#define IAKERB_AS_REQ 0

static void *k5alloc(size_t size, krb5_error_code *code);
static void iakerb_release_context(iakerb_ctx_id_t ctx);