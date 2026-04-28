#include <stdlib.h>
#include <string.h>

typedef unsigned int OM_uint32;
typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gss_buffer_desc;
typedef struct gss_OID_desc_struct *gss_OID;
typedef void *gss_name_t;
typedef void *gss_ctx_id_t;
typedef void *gss_cred_id_t;
#define GSS_C_NO_NAME ((gss_name_t) 0)
#define GSS_C_NO_CHANNEL_BINDINGS ((void *) 0)
#define GSS_C_NULL_OID_SET ((void *) 0)
#define GSS_C_ACCEPT 1
#define GSS_C_QOP_DEFAULT 0
#define GSS_S_COMPLETE 0
#define GSS_S_CONTINUE_NEEDED 1
#define GSS_C_NT_HOSTBASED_SERVICE ((void *) 0)
#define GSS_ERROR(x) ((x) != 0)

typedef struct _Gsasl_gssapi_server_state {
    int step;
    gss_cred_id_t cred;
    gss_ctx_id_t context;
    gss_name_t client;
} _Gsasl_gssapi_server_state;

typedef struct Gsasl_session Gsasl_session;

#define GSASL_NEEDS_MORE 1
#define GSASL_NO_SERVICE 2
#define GSASL_NO_HOSTNAME 3
#define GSASL_MALLOC_ERROR 4
#define GSASL_GSSAPI_IMPORT_NAME_ERROR 5
#define GSASL_GSSAPI_ACQUIRE_CRED_ERROR 6
#define GSASL_GSSAPI_ACCEPT_SEC_CONTEXT_ERROR 7
#define GSASL_GSSAPI_RELEASE_BUFFER_ERROR 8
#define GSASL_GSSAPI_WRAP_ERROR 9
#define GSASL_GSSAPI_UNWRAP_ERROR 10
#define GSASL_AUTHENTICATION_ERROR 11
#define GSASL_GSSAPI_UNSUPPORTED_PROTECTION_ERROR 12
#define GSASL_GSSAPI_DISPLAY_NAME_ERROR 13
#define GSASL_MECHANISM_CALLED_TOO_MANY_TIMES 14

#define GSASL_SERVICE 1
#define GSASL_HOSTNAME 2
#define GSASL_AUTHZID 3
#define GSASL_GSSAPI_DISPLAY_NAME 4
#define GSASL_VALIDATE_GSSAPI 5
#define GSASL_QOP_AUTH 1

const char *gsasl_property_get(Gsasl_session *sctx, int prop);
void gsasl_property_set_raw(Gsasl_session *sctx, int prop, const char *val, size_t len);
int gsasl_callback(void *data, Gsasl_session *sctx, int prop);