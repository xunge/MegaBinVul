#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef int bool_t;
typedef uint32_t OM_uint32;
typedef void* gss_ctx_id_t;

typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gss_buffer_desc;

typedef struct XDR {
    int x_op;
} XDR;

#define FALSE 0
#define TRUE 1
#define XDR_FREE 0
#define XDR_DECODE 0
#define GSS_S_COMPLETE 0

void xdrmem_create(XDR*, void*, size_t, int);
bool_t xdr_bytes(XDR*, char**, unsigned int*, unsigned int);
bool_t xdr_u_int32(XDR*, uint32_t*);
void XDR_DESTROY(XDR*);
void xdr_free(bool_t (*)(), caddr_t);
void gss_release_buffer(OM_uint32*, gss_buffer_desc*);
OM_uint32 gss_unseal(OM_uint32*, gss_ctx_id_t, gss_buffer_desc*, gss_buffer_desc*, int*, int*);
#define PRINTF(args) printf args