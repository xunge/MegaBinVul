#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>

typedef bool bool_t;
typedef unsigned int OM_uint32;
typedef void* gss_ctx_id_t;
typedef void* gss_name_t;
typedef void* gss_OID;
typedef void* gss_cred_id_t;

struct gss_buffer_desc {
    size_t length;
    void* value;
};
typedef struct gss_buffer_desc gss_buffer_desc;

struct svc_req {
    struct {
        struct {
            void* xp_auth;
            struct {
                int oa_flavor;
                void* oa_base;
                size_t oa_length;
            } xp_verf;
        }* rq_xprt;
        void* rq_clntcred;
    };
};

struct rpc_gss_init_res {
    OM_uint32 gr_major;
    OM_uint32 gr_minor;
    gss_buffer_desc gr_token;
    gss_buffer_desc gr_ctx;
    OM_uint32 gr_win;
};

struct svc_rpc_gss_data {
    gss_ctx_id_t ctx;
    gss_name_t client_name;
    struct {
        gss_OID mech;
        OM_uint32 qop;
        int svc;
    } sec;
    gss_buffer_desc cname;
    gss_buffer_desc checksum;
    OM_uint32 seq;
    OM_uint32 win;
    char seqmask[1];
};

struct rpc_gss_cred {
    int gc_svc;
    OM_uint32 gc_seq;
};

struct gss_union_ctx_id_desc {
    void* mech_oid;
    void* internal_ctx_id;
};
typedef struct gss_union_ctx_id_desc gss_union_ctx_id_desc;

#define SVCAUTH_PRIVATE(auth) ((struct svc_rpc_gss_data *)(auth))
#define GSS_C_NO_CONTEXT ((gss_ctx_id_t) 0)
#define GSS_C_QOP_DEFAULT 0
#define GSS_C_NO_CHANNEL_BINDINGS NULL
#define GSS_S_COMPLETE 0
#define GSS_S_CONTINUE_NEEDED 1
#define FALSE false
#define TRUE true
#define RPCSEC_GSS 6

extern bool_t svc_getargs(void *, void *, caddr_t);
extern void svc_freeargs(void *, void *, caddr_t);
extern void badauth(OM_uint32, OM_uint32, void *);
extern void *mem_alloc(size_t);
extern void log_debug(const char *);
extern void log_status(const char *, OM_uint32, OM_uint32);
extern bool_t xdr_rpc_gss_init_args(void *, caddr_t);
extern gss_cred_id_t svcauth_gss_creds;

OM_uint32 gss_accept_sec_context(OM_uint32 *, gss_ctx_id_t *, gss_cred_id_t,
                                gss_buffer_desc *, void *, gss_name_t *,
                                gss_OID *, gss_buffer_desc *, OM_uint32 *,
                                void *, void *);
OM_uint32 gss_display_name(OM_uint32 *, gss_name_t, gss_buffer_desc *,
                          gss_OID *);
OM_uint32 gss_sign(OM_uint32 *, gss_ctx_id_t, OM_uint32, gss_buffer_desc *,
                  gss_buffer_desc *);
OM_uint32 gss_release_buffer(OM_uint32 *, gss_buffer_desc *);