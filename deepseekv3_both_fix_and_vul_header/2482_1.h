#include <stddef.h>

typedef unsigned int OM_uint32;
typedef void *gss_ctx_id_t;
typedef int gss_qop_t;

#define KRB5_CALLCONV
#define GSS_S_COMPLETE 0
#define GSS_S_NO_CONTEXT 1
#define GSS_S_BAD_MECH 2
#define GSS_S_UNAVAILABLE 3
#define GSS_C_NO_CONTEXT NULL

typedef struct gss_iov_buffer_desc {
    int dummy;
} gss_iov_buffer_desc;

typedef struct gss_union_ctx_id_t {
    void *mech_type;
    gss_ctx_id_t internal_ctx_id;
} *gss_union_ctx_id_t;

typedef struct gss_mechanism {
    OM_uint32 (*gss_get_mic_iov)(OM_uint32 *, gss_ctx_id_t, gss_qop_t, gss_iov_buffer_desc *, int);
} *gss_mechanism;

extern OM_uint32 val_wrap_iov_args(OM_uint32 *, gss_ctx_id_t, int, gss_qop_t, void *, gss_iov_buffer_desc *, int);
extern gss_mechanism gssint_get_mechanism(void *);
extern void map_error(OM_uint32 *, gss_mechanism);