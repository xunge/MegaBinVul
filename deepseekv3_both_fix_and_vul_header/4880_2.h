#include <stdint.h>
#include <stddef.h>
#include <limits.h>

typedef uint32_t OM_uint32;
typedef struct gss_buffer_desc_struct {
    void *value;
    size_t length;
} gss_buffer_desc, *gss_buffer_t;
typedef void *gss_ctx_id_t;
typedef struct gss_OID_desc_struct {
    OM_uint32 length;
    void *elements;
} gss_OID_desc, *gss_OID;

typedef enum {
    ERROR_TOKEN_SEND,
    CONT_TOKEN_SEND
} send_token_flag;

typedef enum {
    REJECT,
    ACCEPT_INCOMPLETE
} negState_values;

typedef struct spnego_gss_ctx_id_rec {
    int firstpass;
} *spnego_gss_ctx_id_t;

#define GSS_S_COMPLETE 0
#define GSS_S_DEFECTIVE_TOKEN 1
#define GSS_C_NO_OID ((gss_OID)0)
#define GSS_C_NO_BUFFER ((gss_buffer_t)0)
#define HEADER_ID 0x60
#define CONTEXT 0xA0

extern OM_uint32 g_verify_token_header(gss_OID, unsigned int*, unsigned char**, int, unsigned int);
extern OM_uint32 get_negTokenResp(OM_uint32*, unsigned char*, unsigned int, OM_uint32*, gss_OID*, gss_buffer_t*, gss_buffer_t*);
extern void generic_gss_release_oid(OM_uint32*, gss_OID*);
extern gss_OID gss_mech_spnego;