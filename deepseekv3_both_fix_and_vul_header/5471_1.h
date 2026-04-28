#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef unsigned int OM_uint32;
typedef void *gss_ctx_id_t;

typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gss_buffer_desc, *gss_buffer_t;

typedef struct krb5_gss_ctx_id_rec {
    int terminated;
    int established;
    int have_acceptor_subkey;
    void *k5_context;
    void *subkey;
    void *acceptor_subkey;
} *krb5_gss_ctx_id_t;

typedef int krb5_error_code;
typedef void *krb5_key;

typedef struct krb5_data {
    size_t length;
    void *data;
} krb5_data;

#define KRB5_CALLCONV
#define GSS_C_PRF_KEY_FULL 0
#define GSS_C_PRF_KEY_PARTIAL 1
#define KG_CTX_INCOMPLETE 0
#define GSS_S_NO_CONTEXT 0
#define GSS_S_COMPLETE 0
#define GSS_S_FAILURE 1
#define KG_INPUT_TOO_LONG 0

static void *k5alloc(size_t size, krb5_error_code *code) {
    void *ptr = malloc(size);
    if (ptr == NULL)
        *code = ENOMEM;
    return ptr;
}

static void store_32_be(int value, void *buf) {
    unsigned char *p = buf;
    p[0] = (value >> 24) & 0xFF;
    p[1] = (value >> 16) & 0xFF;
    p[2] = (value >> 8) & 0xFF;
    p[3] = value & 0xFF;
}

static void gss_release_buffer(OM_uint32 *minor, gss_buffer_t buf) {
    free(buf->value);
    buf->value = NULL;
    buf->length = 0;
}

static void krb5_free_data_contents(void *ctx, krb5_data *data) {
    free(data->data);
    data->data = NULL;
    data->length = 0;
}

static krb5_error_code krb5_c_prf_length(void *ctx, int enctype, size_t *len) {
    return 0;
}

static krb5_error_code krb5_k_key_enctype(void *ctx, krb5_key key) {
    return 0;
}

static krb5_error_code krb5_k_prf(void *ctx, krb5_key key, krb5_data *in, krb5_data *out) {
    return 0;
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))