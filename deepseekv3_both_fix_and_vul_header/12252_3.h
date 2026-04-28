#include <stddef.h>

typedef struct EVP_CIPHER_CTX EVP_CIPHER_CTX;
typedef unsigned long VALUE;
typedef unsigned int ID;

static ID id_key_set;
static VALUE eCipherError;
static VALUE rb_eArgError;
static const VALUE Qtrue = 1;

#define RSTRING_LEN(str) (str)
#define RSTRING_PTR(str) ((char*)(str))

void GetCipher(VALUE self, EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_key_length(EVP_CIPHER_CTX *ctx);
int EVP_CipherInit_ex(EVP_CIPHER_CTX *ctx, void *a, void *b, unsigned char *key, void *c, int d);
void ossl_raise(VALUE exc, const char *fmt, ...);
void StringValue(VALUE);
void rb_ivar_set(VALUE obj, ID id, VALUE val);