#include <stdlib.h>
#include <string.h>

typedef struct X509_VERIFY_PARAM_ID X509_VERIFY_PARAM_ID;
typedef struct stack_st_OPENSSL_STRING sk_OPENSSL_STRING;

struct X509_VERIFY_PARAM_ID {
    sk_OPENSSL_STRING *hosts;
};

struct stack_st_OPENSSL_STRING;

void string_stack_free(sk_OPENSSL_STRING *sk);
sk_OPENSSL_STRING *sk_OPENSSL_STRING_new_null();
void sk_OPENSSL_STRING_free(sk_OPENSSL_STRING *sk);
int sk_OPENSSL_STRING_push(sk_OPENSSL_STRING *sk, char *str);
int sk_OPENSSL_STRING_num(const sk_OPENSSL_STRING *sk);

#define SET_HOST 1