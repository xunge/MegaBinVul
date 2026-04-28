#include <stdlib.h>

typedef struct SRP_user_pwd_st {
    char *id;
    void *s;  /* Placeholder for BIGNUM */
    void *v;  /* Placeholder for BIGNUM */ 
    char *info;
} SRP_user_pwd;

#define BN_free(ptr) free(ptr)
#define BN_clear_free(ptr) free(ptr)
#define OPENSSL_free(ptr) free(ptr)