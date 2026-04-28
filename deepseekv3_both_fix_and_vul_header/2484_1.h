#include <stddef.h>

typedef unsigned int OM_uint32;
typedef void *gss_ctx_id_t;
typedef void *gss_name_t;
typedef struct gss_OID_desc_struct *gss_OID;
typedef struct gss_OID_desc_struct {
    OM_uint32 length;
    void *elements;
} gss_OID_desc;

struct gss_union_ctx_id_t {
    gss_OID mech_type;
    gss_ctx_id_t internal_ctx_id;
};
typedef struct gss_union_ctx_id_t *gss_union_ctx_id_t;

struct gss_mechanism {
    OM_uint32 (*gss_inquire_context)(
        OM_uint32 *,
        gss_ctx_id_t,
        gss_name_t *,
        gss_name_t *,
        OM_uint32 *,
        gss_OID *,
        OM_uint32 *,
        int *,
        int *);
    OM_uint32 (*gss_display_name)();
    OM_uint32 (*gss_release_name)();
};
typedef struct gss_mechanism *gss_mechanism;

#define KRB5_CALLCONV
#define GSS_S_COMPLETE 0
#define GSS_S_NO_CONTEXT 1
#define GSS_S_UNAVAILABLE 2
#define GSS_C_NO_CONTEXT NULL
#define GSS_C_NO_NAME NULL

extern OM_uint32 val_inq_ctx_args(
    OM_uint32 *,
    gss_ctx_id_t,
    gss_name_t *,
    gss_name_t *,
    OM_uint32 *,
    gss_OID *,
    OM_uint32 *,
    int *,
    int *);

extern gss_mechanism gssint_get_mechanism(gss_OID);
extern OM_uint32 gssint_convert_name_to_union_name(
    OM_uint32 *,
    gss_mechanism,
    gss_name_t,
    gss_name_t *);
extern gss_OID gssint_get_public_oid(gss_OID);
extern OM_uint32 gss_release_name(OM_uint32 *, gss_name_t *);
extern void map_error(OM_uint32 *, gss_mechanism);