#include <stddef.h>

typedef unsigned int OM_uint32;
typedef void* gss_ctx_id_t;
typedef struct gss_buffer_desc_struct {
    size_t length;
    void* value;
} gss_buffer_desc, *gss_buffer_t;

#define GSS_C_NO_CONTEXT ((gss_ctx_id_t) 0)
#define GSS_S_NO_CONTEXT 1
#define GSS_S_COMPLETE 0
#define GSS_S_BAD_MECH 2

typedef struct gss_union_ctx_id_desc {
    void* mech_type;
    gss_ctx_id_t internal_ctx_id;
} gss_union_ctx_id_desc, *gss_union_ctx_id_t;

typedef struct gss_mechanism_desc {
    OM_uint32 (*gss_complete_auth_token)(
        OM_uint32*,
        gss_ctx_id_t,
        gss_buffer_t
    );
} *gss_mechanism;

extern gss_mechanism gssint_get_mechanism(void*);
extern void map_error(OM_uint32*, gss_mechanism);

#define KRB5_CALLCONV