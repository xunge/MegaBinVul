#include <stddef.h>
#include <assert.h>

typedef unsigned int OM_uint32;
typedef void *gss_ctx_id_t;

typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gss_buffer_desc, *gss_buffer_t;

#define GSS_C_NO_BUFFER ((gss_buffer_t)0)
#define GSS_C_NO_CONTEXT ((gss_ctx_id_t)0)
#define GSS_S_COMPLETE 0

#define KG_IAKERB_CONTEXT 0
#define KG_CONTEXT 0

typedef struct iakerb_ctx_id_t *iakerb_ctx_id_t;
struct iakerb_ctx_id_t {
    int magic;
};

void iakerb_release_context(iakerb_ctx_id_t ctx);
OM_uint32 krb5_gss_delete_sec_context(OM_uint32 *minor_status, gss_ctx_id_t *context_handle, gss_buffer_t output_token);

#define KRB5_CALLCONV