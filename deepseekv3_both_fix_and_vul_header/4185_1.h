#include <string.h>
#include <errno.h>
#include <stdlib.h>

typedef int krb5_error_code;
typedef void *krb5_context;

typedef enum {
    MODIFY_PRINCIPAL
} OPERATION;

#define TRUE 1
#define EINVAL 22
#define TKTPOLICY_ARG "tktpolicy"
#define USERDN_ARG "userdn"
#define CONTAINERDN_ARG "containerdn"
#define LINKDN_ARG "linkdn"

typedef struct {
    char *tktpolicydn;
    char *dn;
    char *containerdn;
    char *linkdn;
    int dn_from_kbd;
} xargs_t;

char *strtok_r(char *, const char *, char **);
int k5_setmsg(krb5_context, krb5_error_code, const char *, ...);
char *k5memdup(const void *, size_t, krb5_error_code *);
krb5_error_code krb5_ldap_name_to_policydn(krb5_context, const char *, char **);