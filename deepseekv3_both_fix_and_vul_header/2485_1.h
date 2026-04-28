#include <stddef.h>
#include <sys/types.h>

typedef unsigned int OM_uint32;
typedef void* gss_ctx_id_t;
typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gss_buffer_desc, *gss_buffer_t;

#define GSS_S_CALL_INACCESSIBLE_WRITE 0
#define GSS_S_CALL_INACCESSIBLE_READ 0
#define GSS_S_NO_CONTEXT 0
#define GSS_S_COMPLETE 0
#define GSS_S_UNAVAILABLE 0
#define GSS_S_BAD_MECH 0
#define GSS_C_NO_BUFFER ((gss_buffer_t)0)
#define GSS_C_NO_CONTEXT ((gss_ctx_id_t)0)

typedef struct gss_union_ctx_id_desc {
    void *mech_type;
    gss_ctx_id_t internal_ctx_id;
} gss_union_ctx_id_desc, *gss_union_ctx_id_t;

typedef struct gss_mechanism_desc {
    OM_uint32 (*gss_pseudo_random)(OM_uint32*, gss_ctx_id_t, int, const gss_buffer_t, ssize_t, gss_buffer_t);
} *gss_mechanism;

#define KRB5_CALLCONV

gss_mechanism gssint_get_mechanism(void*);
void map_error(OM_uint32*, gss_mechanism);