#include <stddef.h>

#define PKCS5_SALT_LEN 8
#define EVP_MAX_KEY_LENGTH 64
#define EVP_MAX_IV_LENGTH 16

typedef struct {} EVP_CIPHER_CTX;
typedef struct {} EVP_MD;
typedef int VALUE;
typedef int ID;

#define Qnil 0
#define Qtrue 1
#define NIL_P(x) ((x) == Qnil)

static VALUE eCipherError;
static ID id_key_set;