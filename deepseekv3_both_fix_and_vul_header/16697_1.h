#include <string.h>
#include <stdlib.h>

typedef struct Slapi_PBlock Slapi_PBlock;
typedef struct Slapi_Operation Slapi_Operation;
typedef struct Connection Connection;
typedef struct Slapi_DN Slapi_DN;
typedef struct passwdPolicy passwdPolicy;
typedef struct berval berval;
typedef struct BerElement BerElement;

struct Slapi_Operation {
    int o_tag;
    int o_status;
    int (*o_result_handler)(Connection *, Slapi_Operation *, int, char *, char *, int, struct berval **);
    struct {
        void *result_controls;
    } o_results;
    int o_msgid;
    unsigned int flags;
};

struct Connection {
    int c_ldapversion;
};

struct passwdPolicy {
    int pw_lockout;
    int pw_is_legacy;
};

struct berval {
    char *bv_val;
    int bv_len;
};

struct snmp_vars {
    struct {
        int *dsSecurityErrors;
        int *dsErrors;
        int *dsReferrals;
    } ops_tbl;
};

enum {
    SLAPI_LOG_ERR,
    SLAPI_LOG_TRACE,
    OP_FLAG_INTERNAL,
    OP_FLAG_ACTION_LOG_ACCESS,
    SLAPI_BIND_METHOD,
    SLAPI_OPERATION,
    SLAPI_CONNECTION,
    SLAPI_PB_RESULT_TEXT,
    SLAPI_RESULT_TEXT,
    SLAPI_TARGET_SDN,
    SLAPI_OP_STATUS_RESULT_SENT,
    LDAP_AUTH_SASL,
    LDAP_CONTROL_PRE_READ_ENTRY,
    LDAP_CONTROL_POST_READ_ENTRY,
    LDAP_TAG_REFERRAL,
    LDAP_RES_SEARCH_RESULT,
    LDAP_RES_DELETE,
    LDAP_REQ_SEARCH,
    LDAP_REQ_DELETE,
    LDAP_REFERRAL,
    LDAP_VERSION2,
    LDAP_VERSION3,
    LBER_DEFAULT,
    LBER_SEQUENCE,
    LBER_ERROR,
    _LDAP_SEND_RESULT,
    LDAP_SUCCESS,
    LDAP_INVALID_CREDENTIALS,
    LDAP_INAPPROPRIATE_AUTH,
    LDAP_AUTH_METHOD_NOT_SUPPORTED,
    LDAP_STRONG_AUTH_NOT_SUPPORTED,
    LDAP_STRONG_AUTH_REQUIRED,
    LDAP_CONFIDENTIALITY_REQUIRED,
    LDAP_INSUFFICIENT_ACCESS,
    LDAP_AUTH_UNKNOWN,
    LDAP_OPT_REFERRALS,
    LDAP_PARTIAL_RESULTS,
    LDAP_ADMINLIMIT_EXCEEDED,
    LDAP_SIZELIMIT_EXCEEDED,
    LDAP_CONSTRAINT_VIOLATION,
    LDAP_UNAVAILABLE_CRITICAL_EXTENSION
};

typedef int ber_tag_t;

extern void slapi_pblock_get(Slapi_PBlock *, int, void *);
extern void slapi_log_err(int, const char *, const char *, ...);
extern void slapi_counter_increment(int *);
extern struct snmp_vars *g_get_global_snmp_vars(void);
extern passwdPolicy *new_passwdPolicy(Slapi_PBlock *, const char *);
extern int update_pw_retry(Slapi_PBlock *);
extern BerElement *der_alloc(void);
extern int ber_printf(BerElement *, const char *, ...);
extern int ber_put_seq(BerElement *);
extern void ber_free(BerElement *, int);
extern int flush_ber(Slapi_PBlock *, Connection *, Slapi_Operation *, BerElement *, int);
extern int operation_is_flag_set(Slapi_Operation *, int);
extern int config_check_referral_mode(void);
extern int config_get_plugin_logging(void);
extern int write_controls(BerElement *, void *);
extern int process_read_entry_controls(Slapi_PBlock *, int);
extern void log_result(Slapi_PBlock *, Slapi_Operation *, int, int, int);
extern int check_and_send_extended_result(Slapi_PBlock *, int, BerElement *);
extern int check_and_send_SASL_response(Slapi_PBlock *, int, BerElement *, Connection *);
extern char *slapi_ch_malloc(size_t);
extern void slapi_ch_free(void **);
extern const char *slapi_sdn_get_dn(Slapi_DN *);