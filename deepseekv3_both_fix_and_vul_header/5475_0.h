#include <stddef.h>

typedef unsigned int OM_uint32;
typedef void *gss_ctx_id_t;
typedef void *gss_OID;
typedef void *gss_buffer_set_t;
typedef void *krb5_pointer;
typedef int krb5_error_code;

typedef struct {
    void *value;
    size_t length;
} gss_buffer_desc;

typedef struct krb5_gss_ctx_id_rec {
    int terminated;
    int established;
} *krb5_gss_ctx_id_t;

#define GSS_S_FAILURE 1
#define GSS_S_NO_CONTEXT 2
#define GSS_C_NO_BUFFER_SET NULL
#define KG_CTX_INCOMPLETE 1
#define KG_LUCID_VERSION 1

#define GSS_KRB5_EXPORT_LUCID_SEC_CONTEXT_OID NULL
#define GSS_KRB5_EXPORT_LUCID_SEC_CONTEXT_OID_LENGTH 0

#define GSS_ERROR(x) ((x) != 0)

extern OM_uint32 generic_gss_oid_decompose(OM_uint32 *, const gss_OID, size_t, const gss_OID, int *);
extern OM_uint32 generic_gss_add_buffer_set_member(OM_uint32 *, const gss_buffer_desc *, gss_buffer_set_t *);
extern krb5_error_code make_external_lucid_ctx_v1(krb5_pointer, int, void **);