#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef int krb5_error_code;
typedef struct krb5_context_t {
    void *profile;
} *krb5_context;
typedef unsigned int krb5_timestamp;

typedef struct krb5_data {
    char *data;
    size_t length;
} krb5_data;

typedef struct krb5_enc_data {
    krb5_data ciphertext;
} krb5_enc_data;

typedef struct krb5_keyblock {
    int enctype;
} krb5_keyblock;

typedef struct krb5_pa_enc_ts {
    krb5_timestamp patimestamp;
} krb5_pa_enc_ts;

typedef struct krb5_pa_data {
    unsigned char *contents;
    size_t length;
} krb5_pa_data;

typedef struct krb5_kdc_req {
    struct {
        krb5_data realm;
    } *server;
} krb5_kdc_req;

typedef struct krb5_enc_tkt_part {
    unsigned int flags;
} krb5_enc_tkt_part;

typedef void *krb5_kdcpreauth_modreq;
typedef void *krb5_kdcpreauth_moddata;
typedef void *krb5_kdcpreauth_rock;

typedef struct krb5_kdcpreauth_callbacks {
    krb5_keyblock *(*fast_armor)(krb5_context, krb5_kdcpreauth_rock);
    krb5_error_code (*client_keys)(krb5_context, krb5_kdcpreauth_rock, krb5_keyblock ***);
    void (*free_keys)(krb5_context, krb5_kdcpreauth_rock, krb5_keyblock **);
    void (*add_auth_indicator)(krb5_context, krb5_kdcpreauth_rock, char *);
} *krb5_kdcpreauth_callbacks;

typedef void (*krb5_kdcpreauth_verify_respond_fn)(void *arg, krb5_error_code retval,
                                                 krb5_kdcpreauth_modreq modreq,
                                                 krb5_data *e_data,
                                                 krb5_pa_data **edata);

#define KRB5_CONF_REALMS "realms"
#define KRB5_CONF_ENCRYPTED_CHALLENGE_INDICATOR "encrypted_challenge_auth_indicator"
#define TKT_FLG_PRE_AUTH 0x00000001
#define KRB5_KEYUSAGE_ENC_CHALLENGE_CLIENT 0
#define KRB5KDC_ERR_PREAUTH_FAILED 0

static char *k5memdup0(const void *data, size_t len, krb5_error_code *code) {
    char *s = malloc(len + 1);
    if (s) {
        memcpy(s, data, len);
        s[len] = '\0';
    } else {
        *code = ENOMEM;
    }
    return s;
}

static void k5_setmsg(krb5_context ctx, krb5_error_code code, const char *msg) {}

static krb5_error_code decode_krb5_enc_data(krb5_data *in, krb5_enc_data **out) { return 0; }
static krb5_error_code decode_krb5_pa_enc_ts(krb5_data *in, krb5_pa_enc_ts **out) { return 0; }
static krb5_error_code krb5_c_fx_cf2_simple(krb5_context ctx, krb5_keyblock *k1, const char *p1,
                                           krb5_keyblock *k2, const char *p2,
                                           krb5_keyblock **out) { return 0; }
static krb5_error_code krb5_c_decrypt(krb5_context ctx, krb5_keyblock *key, int usage,
                                     void *iv, krb5_enc_data *in, krb5_data *out) { return 0; }
static void krb5_free_enc_data(krb5_context ctx, krb5_enc_data *data) {}
static void krb5_free_pa_enc_ts(krb5_context ctx, krb5_pa_enc_ts *data) {}
static void krb5_free_keyblock(krb5_context ctx, krb5_keyblock *key) {}
static krb5_error_code krb5_check_clockskew(krb5_context ctx, krb5_timestamp ts) { return 0; }
static krb5_error_code profile_get_string(void *profile, const char *section, 
                                        const char *name, const char *subname,
                                        const char *def_val, char **ret_val) { return 0; }