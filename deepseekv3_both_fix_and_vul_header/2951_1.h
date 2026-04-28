#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef int krb5_error_code;
typedef unsigned int krb5_flags;
typedef int krb5_int32;

#define KRB5KRB_AP_ERR_BADMATCH 1
#define KDC_OPT_CANONICALIZE 0x01
#define KDC_OPT_ENC_TKT_IN_SKEY 0x02
#define KRB5_NT_SRV_HST 1
#define KRB5_NT_SRV_INST 2
#define KRB5_NT_UNKNOWN 3
#define KRB5_CONF_ASTERISK "*"
#define TRUE 1
#define FALSE 0

typedef struct {
    char *data;
    size_t length;
} krb5_data;

typedef struct {
    krb5_data realm;
    // other fields omitted
} krb5_principal_data;
typedef krb5_principal_data *krb5_principal;

typedef struct {
    krb5_flags kdc_options;
    krb5_principal server;
    // other fields omitted
} krb5_kdc_req;

typedef struct {
    void *context;
} krb5_context;

extern krb5_context kdc_context;

struct kdc_realm {
    char **realm_host_based_services;
    char **realm_no_host_referral;
};

extern struct kdc_realm *kdc_active_realm;

static inline int isflagset(krb5_flags options, krb5_flags flag) {
    return (options & flag) == flag;
}

static inline int data_eq_string(krb5_data data, const char *str) {
    return strncmp(data.data, str, data.length) == 0 && str[data.length] == '\0';
}

static inline size_t strlcpy(char *dst, const char *src, size_t size) {
    size_t i;
    for (i = 0; i < size - 1 && src[i]; i++)
        dst[i] = src[i];
    dst[i] = '\0';
    return i;
}

// Mock functions to satisfy compilation
static int krb5_princ_size(krb5_context ctx, krb5_principal princ) { return 0; }
static krb5_data *krb5_princ_component(krb5_context ctx, krb5_principal princ, int n) { return NULL; }
static int krb5_princ_type(krb5_context ctx, krb5_principal princ) { return 0; }
static int krb5_match_config_pattern(char **patterns, const char *str) { return 0; }
static int krb5int_get_domain_realm_mapping(krb5_context ctx, char *str, char ***realms) { return 0; }
static void kdc_err(krb5_context ctx, int code, const char *msg) {}
static int krb5_build_principal(krb5_context ctx, krb5_principal *princ, 
                              size_t realm_len, char *realm_data, 
                              const char *comp1, const char *comp2, ...) { return 0; }