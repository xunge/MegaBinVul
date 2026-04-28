#include <stddef.h>
#include <string.h>
#include <syslog.h>

typedef void* gss_ctx_id_t;
typedef void* gss_name_t;
typedef void* krb5_context;
typedef void* krb5_principal;
typedef unsigned int OM_uint32;
typedef void* SVCXPRT;

struct gss_buffer_desc_struct {
    size_t length;
    void* value;
};
typedef struct gss_buffer_desc_struct gss_buffer_desc;

struct krb5_data_struct {
    unsigned int length;
    char* data;
};
typedef struct krb5_data_struct krb5_data;

struct kadm5_params_struct {
    char* realm;
};

struct kadm5_server_handle_struct {
    krb5_context context;
    struct kadm5_params_struct params;
};
typedef struct kadm5_server_handle_struct* kadm5_server_handle_t;

struct svc_req {
    struct {
        unsigned int oa_flavor;
        char* oa_base;
        unsigned int oa_length;
    } rq_cred;
    char* rq_svccred;
    SVCXPRT* rq_xprt;
};

#define RPCSEC_GSS 6
#define GSS_S_COMPLETE 0
#define LOG_ERR 3
#define GSS_C_NO_NAME NULL

extern void* global_server_handle;
extern int gss_to_krb5_name_1(struct svc_req*, krb5_context, gss_name_t, krb5_principal*, gss_buffer_desc*);
extern void log_badauth(OM_uint32, OM_uint32, SVCXPRT*, char*);
extern void trunc_name(size_t*, char**);
extern void krb5_klog_syslog(int, const char*, ...);
extern OM_uint32 gss_inquire_context(OM_uint32*, gss_ctx_id_t, gss_name_t*, gss_name_t*, OM_uint32*, OM_uint32*, OM_uint32*, OM_uint32*, OM_uint32*);
extern OM_uint32 gss_release_buffer(OM_uint32*, gss_buffer_desc*);
extern OM_uint32 gss_release_name(OM_uint32*, gss_name_t*);
extern int krb5_princ_size(krb5_context, krb5_principal);
extern krb5_data* krb5_princ_component(krb5_context, krb5_principal, int);
extern krb5_data* krb5_princ_realm(krb5_context, krb5_principal);
extern void krb5_free_principal(krb5_context, krb5_principal);