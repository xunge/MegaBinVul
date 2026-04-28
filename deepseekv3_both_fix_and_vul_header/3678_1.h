#include <stddef.h>

typedef int ret_t;
typedef struct LDAPMessage LDAPMessage;

typedef struct cherokee_validator_ldap_t {
    void *conn;
    struct {
        char *buf;
    } filter;
} cherokee_validator_ldap_t;

typedef struct cherokee_connection_t {
    struct {
        struct {
            size_t len;
            char *buf;
        } user;
        struct {
            char *buf;
        } passwd;
    } *validator;
} cherokee_connection_t;

typedef struct cherokee_validator_ldap_props_t {
    struct {
        char *buf;
    } basedn;
    struct {
        char *buf;
    } filter;
} cherokee_validator_ldap_props_t;

#define VAL_LDAP_PROP(ldap) ((cherokee_validator_ldap_props_t *)(ldap))
#define LDAP_NO_ATTRS "*"
#define LDAP_SCOPE_SUBTREE 2
#define LDAP_SUCCESS 0
#define CHEROKEE_ERROR_VALIDATOR_LDAP_SEARCH 0
#define ret_ok 0
#define ret_error -1
#define ret_not_found -2

#define LOG_ERROR(code, msg)
#define TRACE(category, fmt, ...)
#define ENTRIES 0

ret_t init_filter(cherokee_validator_ldap_t *ldap, cherokee_validator_ldap_props_t *props, cherokee_connection_t *conn);
ret_t validate_dn(cherokee_validator_ldap_props_t *props, char *dn, char *passwd);
size_t cherokee_buffer_cnt_cspn(struct { size_t len; char *buf; } *buf, int pos, const char *reject);
int cherokee_buffer_is_empty(struct { size_t len; char *buf; } *buf);