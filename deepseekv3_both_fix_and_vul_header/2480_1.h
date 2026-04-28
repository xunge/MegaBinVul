#include <stddef.h>

typedef unsigned int OM_uint32;
typedef void *gss_ctx_id_t;
typedef int gss_qop_t;
typedef struct gss_union_ctx_id_desc *gss_union_ctx_id_t;
typedef struct gss_mechanism_desc *gss_mechanism;

#define GSS_S_CALL_INACCESSIBLE_WRITE 0
#define GSS_S_CALL_INACCESSIBLE_READ 0
#define GSS_S_NO_CONTEXT 0
#define GSS_S_BAD_MECH 0
#define GSS_S_UNAVAILABLE 0
#define GSS_S_COMPLETE 0
#define GSS_C_NO_CONTEXT NULL
#define KRB5_CALLCONV

struct gss_union_ctx_id_desc {
    void *mech_type;
    gss_ctx_id_t internal_ctx_id;
};

struct gss_mechanism_desc {
    OM_uint32 (*gss_wrap_size_limit)(
        OM_uint32 *,
        gss_ctx_id_t,
        int,
        gss_qop_t,
        OM_uint32,
        OM_uint32 *);
    OM_uint32 (*gss_wrap_iov_length)(
        OM_uint32 *,
        gss_ctx_id_t,
        int,
        gss_qop_t,
        OM_uint32,
        OM_uint32 *);
};

extern gss_mechanism gssint_get_mechanism(void *);
extern OM_uint32 gssint_wrap_size_limit_iov_shim(
    gss_mechanism,
    OM_uint32 *,
    gss_ctx_id_t,
    int,
    gss_qop_t,
    OM_uint32,
    OM_uint32 *);
extern void map_error(OM_uint32 *, gss_mechanism);