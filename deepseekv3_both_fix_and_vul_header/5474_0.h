#include <stddef.h>
#include <errno.h>

typedef unsigned int OM_uint32;
typedef void* gss_ctx_id_t;
typedef struct gss_OID_desc_struct* gss_OID;
typedef struct gss_buffer_set_desc_struct* gss_buffer_set_t;

#define KRB5_CALLCONV
#define GSS_S_CALL_INACCESSIBLE_WRITE 1
#define GSS_S_CALL_INACCESSIBLE_READ 2
#define GSS_S_NO_CONTEXT 3
#define GSS_S_UNAVAILABLE 4
#define GSS_C_NO_OID ((gss_OID)0)
#define GSS_C_NO_BUFFER_SET ((gss_buffer_set_t)0)

typedef struct krb5_gss_ctx_id_rec {
    int established;
    int terminated;
} krb5_gss_ctx_id_rec;

typedef struct gss_OID_desc_struct {
    OM_uint32 length;
    void* elements;
} gss_OID_desc;

typedef struct {
    gss_OID_desc oid;
    OM_uint32 (*func)(OM_uint32*, const gss_ctx_id_t, const gss_OID, gss_buffer_set_t*);
} krb5_gss_inquire_sec_context_by_oid_op;

static krb5_gss_inquire_sec_context_by_oid_op krb5_gss_inquire_sec_context_by_oid_ops[] = {0};

int g_OID_prefix_equal(const gss_OID, const gss_OID);