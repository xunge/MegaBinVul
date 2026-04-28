#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

typedef int krb5_error_code;
typedef int krb5_int32;

typedef struct krb5_context *krb5_context;

typedef struct krb5_data {
    unsigned int length;
    char *data;
} krb5_data;

typedef struct krb5_principal_data {
    int type;
    int magic;
    krb5_data realm;
    krb5_data *data;
    int length;
} *krb5_principal;

#define KV5M_PRINCIPAL 0
#define KRB5_NT_UNKNOWN 0
#define ENOMEM 12

static inline krb5_data make_data(char *d, unsigned int len) {
    krb5_data data;
    data.data = d;
    data.length = len;
    return data;
}