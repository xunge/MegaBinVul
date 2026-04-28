#include <errno.h>
#include <stdlib.h>
#include <string.h>

typedef int krb5_error_code;
typedef void* krb5_context;
typedef void* LDAP;
typedef void* LDAPMessage;
typedef struct osa_policy_ent_rec {
    /* dummy structure definition */
    int dummy;
} osa_policy_ent_rec;
typedef struct osa_policy_ent_rec *osa_policy_ent_t;
typedef struct kdb5_dal_handle kdb5_dal_handle;
typedef struct krb5_ldap_context krb5_ldap_context;
typedef struct krb5_ldap_server_handle krb5_ldap_server_handle;

#define KRB5_KDB_NOENTRY 12345
#define LDAP_SCOPE_BASE 0

static inline void krb5_clear_error_message(krb5_context ctx) {}
static inline int ldap_first_entry(LDAP *ld, LDAPMessage *msg) { return 0; }
static inline void ldap_msgfree(LDAPMessage *msg) {}
#define LDAP_SEARCH(dn, scope, filter, attrs) do {} while(0)

extern char *password_policy_attributes[];
extern void SETUP_CONTEXT(void);
extern void GET_HANDLE(void);
extern krb5_error_code populate_policy(krb5_context, LDAP *, LDAPMessage *, char *, osa_policy_ent_t);
extern void krb5_ldap_free_password_policy(krb5_context, osa_policy_ent_t);
extern void krb5_ldap_put_handle_to_pool(krb5_ldap_context *, krb5_ldap_server_handle *);