#include <stddef.h>
#include <errno.h>

typedef unsigned int OM_uint32;
typedef void *gss_ctx_id_t;
typedef struct gss_OID_desc_struct *gss_OID;
typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gss_buffer_desc, *gss_buffer_t;

#define KRB5_CALLCONV
#define GSS_S_CALL_INACCESSIBLE_WRITE 1
#define GSS_S_CALL_INACCESSIBLE_READ 2
#define GSS_S_UNAVAILABLE 3
#define GSS_C_NO_OID ((gss_OID)0)