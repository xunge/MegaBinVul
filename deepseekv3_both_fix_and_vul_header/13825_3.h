#include <stddef.h>

typedef unsigned int OM_uint32;
typedef void *gss_ctx_id_t;
typedef void *gss_cred_id_t;
typedef void *gss_name_t;
typedef void *gss_OID;

typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gss_buffer_desc, *gss_buffer_t;

typedef struct gss_channel_bindings_struct {
    OM_uint32 initiator_addrtype;
    gss_buffer_desc initiator_address;
    OM_uint32 acceptor_addrtype;
    gss_buffer_desc acceptor_address;
    gss_buffer_desc application_data;
} *gss_channel_bindings_t;

struct iakerb_ctx_id_rec {
    gss_ctx_id_t gssc;
    int established;
};

struct krb5_gss_ctx_ext_rec {
    int dummy;
};

typedef struct iakerb_ctx_id_rec *iakerb_ctx_id_t;
typedef struct krb5_gss_ctx_ext_rec krb5_gss_ctx_ext_rec;

#define KRB5_CALLCONV
#define GSS_S_FAILURE 1
#define GSS_S_CONTINUE_NEEDED 2
#define GSS_S_COMPLETE 3
#define GSS_S_DEFECTIVE_TOKEN 4
#define GSS_C_NO_CONTEXT NULL
#define GSS_C_NO_NAME NULL
#define GSS_C_NO_CREDENTIAL NULL
#define G_WRONG_TOKID 1
#define KRB5_BAD_MSIZE 2
#define GSS_ERROR(x) ((x) > 1)

extern OM_uint32 iakerb_alloc_context(iakerb_ctx_id_t *, ...);
extern int iakerb_is_iakerb_token(gss_buffer_t);
extern OM_uint32 iakerb_acceptor_step(iakerb_ctx_id_t, int, gss_buffer_t, gss_buffer_t);
extern void iakerb_release_context(iakerb_ctx_id_t);
extern void iakerb_make_exts(iakerb_ctx_id_t, krb5_gss_ctx_ext_rec *);
extern OM_uint32 krb5_gss_accept_sec_context_ext(OM_uint32 *, gss_ctx_id_t *, gss_cred_id_t, gss_buffer_t, gss_channel_bindings_t, gss_name_t *, gss_OID *, gss_buffer_t, OM_uint32 *, OM_uint32 *, gss_cred_id_t *, krb5_gss_ctx_ext_rec *);
extern gss_OID gss_mech_iakerb;
extern gss_OID gss_mech_krb5;