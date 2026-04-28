#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define EVP_MAX_KEY_LENGTH 64

typedef struct EVP_CIPHER_CTX EVP_CIPHER_CTX;
typedef struct EVP_CIPHER EVP_CIPHER;

typedef uintptr_t VALUE;

static VALUE rb_eRuntimeError;
static VALUE eCipherError;

#define StringValueCStr(v) ((char *)(uintptr_t)(v))
#define PRIsVALUE "lu"
#define ossl_raise(exception, msg, ...) 
#define GetCipherInit(self, ctx) 
#define AllocCipher(self, ctx) 

static EVP_CIPHER *EVP_get_cipherbyname(const char *name) { return NULL; }
static int EVP_CipherInit_ex(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *cipher, void *a, unsigned char *key, void *b, int c) { return 1; }