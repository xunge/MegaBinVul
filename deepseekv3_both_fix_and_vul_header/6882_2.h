#include <stdlib.h>
#include <string.h>

typedef unsigned int OM_uint32;
typedef void *gss_ctx_id_t;
typedef void *gss_const_cred_id_t;
typedef void *gss_channel_bindings_t;
typedef void *gss_name_t;
typedef void *gss_cred_id_t;

typedef struct {
    size_t length;
    void *value;
} gss_buffer_desc;
typedef gss_buffer_desc *gss_buffer_t;

typedef struct gss_OID_desc_struct {
    OM_uint32 length;
    void *elements;
} gss_OID_desc, *gss_OID;

typedef struct {
    size_t len;
    gss_OID *val;
} MechTypeList;

typedef struct {
    size_t length;
    void *data;
} MechToken;

typedef struct {
    MechTypeList mechTypes;
    MechToken *mechToken;
    void *mechListMIC;
} NegTokenInit;

enum {
    choice_NegotiationToken_negTokenInit = 0
};

typedef struct {
    int element;
    union {
        NegTokenInit negTokenInit;
    } u;
} NegotiationToken;

typedef struct gssspnego_ctx {
    void *ctx_id_mutex;
    MechTypeList initiator_mech_types;
    gss_name_t mech_src_name;
    gss_ctx_id_t negotiated_ctx_id;
    gss_OID negotiated_mech_type;
    gss_OID preferred_mech_type;
    OM_uint32 mech_flags;
    OM_uint32 mech_time_rec;
    int open;
} *gssspnego_ctx;

typedef struct spnego_name {
    gss_name_t mech;
} *spnego_name;

#define GSS_C_NO_BUFFER ((gss_buffer_t)0)
#define GSS_C_NO_OID ((gss_OID)0)
#define GSS_C_NO_NAME ((gss_name_t)0)
#define GSS_SPNEGO_MECHANISM ((gss_OID)0)
#define GSS_S_COMPLETE 0
#define GSS_S_CONTINUE_NEEDED 1
#define GSS_S_DEFECTIVE_TOKEN 2
#define GSS_S_FAILURE 3

#define HEIMDAL_MUTEX_lock(x)
#define HEIMDAL_MUTEX_unlock(x)

#define GSSAPI_CALLCONV

extern OM_uint32 send_supported_mechs(OM_uint32 *, gss_buffer_t);
extern OM_uint32 _gss_spnego_alloc_sec_context(OM_uint32 *, gss_ctx_id_t *);
extern OM_uint32 gss_decapsulate_token(const gss_buffer_t, gss_OID, gss_buffer_t);
extern OM_uint32 decode_NegotiationToken(void *, size_t, NegotiationToken *, size_t *);
extern void gss_release_buffer(OM_uint32 *, gss_buffer_t);
extern void free_NegotiationToken(NegotiationToken *);
extern OM_uint32 copy_MechTypeList(const MechTypeList *, MechTypeList *);
extern OM_uint32 select_mech(OM_uint32 *, gss_OID *, int, gss_OID *);
extern OM_uint32 gss_accept_sec_context(OM_uint32 *, gss_ctx_id_t *, gss_const_cred_id_t, gss_buffer_t, gss_channel_bindings_t, gss_name_t *, gss_OID *, gss_buffer_t, OM_uint32 *, OM_uint32 *, gss_cred_id_t *);
extern void gss_release_name(OM_uint32 *, gss_name_t *);
extern void gss_mg_collect_error(gss_OID, OM_uint32, OM_uint32);
extern OM_uint32 acceptor_complete(OM_uint32 *, gssspnego_ctx, int *, gss_buffer_t, gss_buffer_t, gss_buffer_t, void *, gss_buffer_t);
extern OM_uint32 send_reject(OM_uint32 *, gss_buffer_t);
extern OM_uint32 send_accept(OM_uint32 *, gssspnego_ctx, gss_buffer_t, int, gss_buffer_t, gss_buffer_t);
extern void _gss_spnego_internal_delete_sec_context(OM_uint32 *, gss_ctx_id_t *, gss_buffer_t);