#include <stdint.h>
#include <stddef.h>

typedef uint32_t OM_uint32;
typedef void *gss_ctx_id_t;
typedef int gss_qop_t;

typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gss_buffer_desc, *gss_buffer_t;

typedef struct gss_union_ctx_id_desc {
    void *internal_ctx_id;
    void *mech_type;
} *gss_union_ctx_id_t;

typedef struct gss_mechanism_struct {
    OM_uint32 (*gss_wrap)(
        OM_uint32 *,
        gss_ctx_id_t,
        int,
        gss_qop_t,
        gss_buffer_t,
        int *,
        gss_buffer_t);
    OM_uint32 (*gss_wrap_aead)(
        OM_uint32 *,
        gss_ctx_id_t,
        int,
        gss_qop_t,
        gss_buffer_t,
        int *,
        gss_buffer_t);
    OM_uint32 (*gss_wrap_iov)(
        OM_uint32 *,
        gss_ctx_id_t,
        int,
        gss_qop_t,
        gss_buffer_t,
        int *,
        gss_buffer_t);
    OM_uint32 (*gss_wrap_iov_length)(
        OM_uint32 *,
        gss_ctx_id_t,
        int,
        gss_qop_t,
        gss_buffer_t,
        int *,
        gss_buffer_t);
} *gss_mechanism;

#define KRB5_CALLCONV
#define GSS_S_COMPLETE 0
#define GSS_S_NO_CONTEXT 1
#define GSS_S_UNAVAILABLE 2
#define GSS_S_BAD_MECH 3
#define GSS_C_NO_CONTEXT ((void *)0)
#define GSS_C_NO_BUFFER ((gss_buffer_t)0)

extern OM_uint32 val_wrap_args(
    OM_uint32 *,
    gss_ctx_id_t,
    int,
    gss_qop_t,
    gss_buffer_t,
    int *,
    gss_buffer_t);
extern gss_mechanism gssint_get_mechanism(void *);
extern OM_uint32 gssint_wrap_aead(
    gss_mechanism,
    OM_uint32 *,
    gss_union_ctx_id_t,
    int,
    gss_qop_t,
    gss_buffer_t,
    gss_buffer_t,
    int *,
    gss_buffer_t);
extern void map_error(OM_uint32 *, gss_mechanism);