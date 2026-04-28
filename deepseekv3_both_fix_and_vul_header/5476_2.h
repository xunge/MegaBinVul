#include <stdbool.h>
#include <stdlib.h>

typedef bool bool_t;
typedef void *krb5_context;
typedef void *krb5_principal;

typedef struct XDR {
    int x_op;
} XDR;

#define FALSE false
#define TRUE true
#define XDR_ENCODE 0
#define XDR_DECODE 1
#define XDR_FREE 2

extern int kadm5_init_krb5_context(krb5_context *context);
extern int krb5_unparse_name(krb5_context context, krb5_principal principal, char **name);
extern int krb5_parse_name(krb5_context context, const char *name, krb5_principal *principal);
extern void krb5_free_principal(krb5_context context, krb5_principal principal);
extern bool_t xdr_nullstring(XDR *xdrs, char **objp);