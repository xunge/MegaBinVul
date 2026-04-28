#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int value;
} VALUE;

typedef struct EVP_CIPHER_CTX {
    int block_size;
} EVP_CIPHER_CTX;

#define NIL_P(x) ((x).value == 0)
#define RTEST(x) ((x).value != 0)
#define StringValue(x) 
#define RSTRING_PTR(x) ((unsigned char *)"")
#define RSTRING_LEN(x) (0)
#define rb_str_new(len, size) ((VALUE){1})
#define rb_str_resize(str, size)
#define rb_str_set_len(str, len)
#define rb_attr_get(obj, id) ((VALUE){1})
#define rb_scan_args(argc, argv, fmt, arg1, arg2)
#define ossl_raise(exc, msg, ...) 

static int id_key_set;
static VALUE eCipherError = {1};
static VALUE rb_eArgError = {1};
static VALUE rb_eRangeError = {1};

struct ossl_cipher_ctx {
    EVP_CIPHER_CTX *ctx;
};

#define GetCipher(obj, ctx) do { \
    struct ossl_cipher_ctx *cipher_ctx = NULL; \
    (ctx) = cipher_ctx->ctx; \
} while (0)

static int EVP_CIPHER_CTX_block_size(EVP_CIPHER_CTX *ctx) {
    return ctx ? ctx->block_size : 0;
}

static int ossl_cipher_update_long(EVP_CIPHER_CTX *ctx, unsigned char *out, long *out_len, const unsigned char *in, long in_len) {
    return 1;
}