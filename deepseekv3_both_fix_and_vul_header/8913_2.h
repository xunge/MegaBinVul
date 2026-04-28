#include <stddef.h>

typedef void* gss_ctx_id_t;
typedef struct {
    size_t length;
    void* value;
} gss_buffer_desc;
typedef gss_buffer_desc* gss_buffer_t;

typedef struct iakerb_ctx_id_t {
    int established;
    gss_ctx_id_t gssc;
} *iakerb_ctx_id_t;

#define KRB5_CALLCONV
#define OM_uint32 unsigned int
#define GSS_S_UNAVAILABLE 1
#define GSS_C_NO_CONTEXT NULL

extern OM_uint32 krb5_gss_export_sec_context(OM_uint32*, gss_ctx_id_t*, gss_buffer_t);
extern void iakerb_release_context(iakerb_ctx_id_t);