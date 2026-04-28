#include <stddef.h>

struct gstd_tok {
    void *ctx;
    int fd;
    char *desc;
};

typedef unsigned int OM_uint32;
typedef void *gss_ctx_id_t;
typedef void *gss_name_t;
typedef void *gss_cred_id_t;
typedef void *gss_channel_bindings_t;

struct gss_buffer_desc {
    size_t length;
    void *value;
};
typedef struct gss_buffer_desc gss_buffer_desc;

struct gss_OID_desc {
    OM_uint32 length;
    void *elements;
};
typedef struct gss_OID_desc *gss_OID;

#define GSS_C_NO_CONTEXT ((gss_ctx_id_t)0)
#define GSS_C_NO_CREDENTIAL ((gss_cred_id_t)0)
#define GSS_C_NO_CHANNEL_BINDINGS ((gss_channel_bindings_t)0)
#define GSS_S_CONTINUE_NEEDED 1

#define GSTD_GSS_ERROR(maj, min, func, msg)
#define SETUP_GSTD_TOK(tok, ctx, fd, desc)

extern int read_packet(int fd, gss_buffer_desc *buf, int timeout, int initial);
extern int write_packet(int fd, gss_buffer_desc *buf);
extern char *gstd_get_display_name(gss_name_t name);
extern char *gstd_get_export_name(gss_name_t name);
extern char *gstd_get_mech(gss_OID mech_oid);
extern void gss_release_buffer(OM_uint32 *min, gss_buffer_desc *buf);
extern void gss_release_name(OM_uint32 *min, gss_name_t *name);
extern OM_uint32 gss_accept_sec_context(
    OM_uint32 *min,
    gss_ctx_id_t *ctx,
    gss_cred_id_t cred,
    gss_buffer_desc *input,
    gss_channel_bindings_t bindings,
    gss_name_t *src_name,
    gss_OID *mech_type,
    gss_buffer_desc *output,
    OM_uint32 *ret_flags,
    OM_uint32 *time_rec,
    gss_cred_id_t *delegated_cred
);