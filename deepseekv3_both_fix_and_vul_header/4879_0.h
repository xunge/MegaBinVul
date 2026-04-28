#include <stddef.h>

typedef unsigned int OM_uint32;
typedef struct spnego_gss_ctx_id_t *spnego_gss_ctx_id_t;
typedef struct gss_OID_desc *gss_OID;
typedef struct gss_buffer_desc_struct *gss_buffer_t;
typedef enum { CONT_TOKEN_SEND } send_token_flag;
typedef enum { REQUEST_MIC } negState_enum;

#define GSS_S_DEFECTIVE_TOKEN 0
#define GSS_S_CONTINUE_NEEDED 0
#define GSS_C_NO_BUFFER NULL

struct gss_OID_desc {
    OM_uint32 length;
    void *elements;
};

struct gss_buffer_desc_struct {
    size_t length;
    void *value;
};

struct spnego_gss_ctx_id_t {
    struct gss_ctx_id_t *ctx_handle;
    struct gss_OID_set_desc *mech_set;
    gss_OID internal_mech;
    int mech_complete;
    int mic_reqd;
};

struct gss_ctx_id_t {
    void *internal_handle;
};

struct gss_OID_set_desc {
    size_t count;
    struct gss_OID_desc *elements;
};

extern OM_uint32 generic_gss_release_oid(OM_uint32 *, gss_OID *);
extern OM_uint32 gss_delete_sec_context(OM_uint32 *, struct gss_ctx_id_t **, gss_buffer_t);
extern int g_OID_equal(gss_OID, struct gss_OID_desc *);