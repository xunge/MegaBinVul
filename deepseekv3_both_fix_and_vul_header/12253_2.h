#include <string.h>

#define EVP_MAX_KEY_LENGTH 64
#define EVP_MAX_IV_LENGTH 16

typedef struct EVP_CIPHER_CTX EVP_CIPHER_CTX;
typedef struct EVP_CIPHER EVP_CIPHER;
typedef struct EVP_MD EVP_MD;

typedef unsigned long VALUE;
typedef int ID;
#define Qtrue 1
#define NIL_P(x) ((x) == 0)
#define PRIsVALUE "lu"
#define RSTRING_LEN(x) 0
#define RSTRING_PTR(x) NULL
#define RSTRING_LENINT(x) 0
#define StringValue(x) 
#define rb_scan_args(...) 0
#define rb_class_path(...) 0
#define rb_obj_class(...) 0
#define rb_warn(...)
#define ossl_raise(...)
#define rb_ivar_set(...)
#define GetCipher(...)