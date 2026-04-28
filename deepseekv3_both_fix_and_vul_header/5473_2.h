#include <stddef.h>

typedef unsigned int OM_uint32;
typedef void *gss_ctx_id_t;
typedef int gss_qop_t;

#define KG_CTX_INCOMPLETE 0
#define GSS_S_NO_CONTEXT 0
#define GSS_IOV_BUFFER_TYPE_STREAM 0

typedef struct gss_iov_buffer_desc {
    int dummy;
} gss_iov_buffer_desc;

typedef struct krb5_gss_ctx_id_rec {
    int terminated;
    int established;
} krb5_gss_ctx_id_rec;

extern OM_uint32 kg_unseal_stream_iov(OM_uint32 *, krb5_gss_ctx_id_rec *, int *, gss_qop_t *, gss_iov_buffer_desc *, int, int);
extern OM_uint32 kg_unseal_iov_token(OM_uint32 *, krb5_gss_ctx_id_rec *, int *, gss_qop_t *, gss_iov_buffer_desc *, int, int);
extern gss_iov_buffer_desc *kg_locate_iov(gss_iov_buffer_desc *, int, int);