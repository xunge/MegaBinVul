#include <stdio.h>
#include <stdlib.h>

typedef void* krb5_context;
typedef struct krb5_data {
    unsigned char *contents;
    size_t length;
} krb5_data;
typedef struct krb5_principal {
    char dummy;
} krb5_principal;
typedef struct krb5_kdc_req {
    krb5_principal client;
} krb5_kdc_req;
typedef struct krb5_enc_tkt_part {
    unsigned int flags;
} krb5_enc_tkt_part;
typedef struct krb5_pa_data {
    unsigned char *contents;
    size_t length;
} krb5_pa_data;
typedef struct krb5_keyblock {
    char dummy;
} krb5_keyblock;
typedef struct krb5_pa_otp_req {
    char dummy;
} krb5_pa_otp_req;
typedef int krb5_error_code;
typedef void* krb5_kdcpreauth_rock;
typedef void* krb5_kdcpreauth_moddata;
typedef void (*krb5_kdcpreauth_verify_respond_fn)(void *, krb5_error_code, krb5_pa_data **, krb5_data **, krb5_kdcpreauth_moddata *);

struct request_state {
    void *arg;
    krb5_kdcpreauth_verify_respond_fn respond;
    krb5_enc_tkt_part *enc_tkt_reply;
};

typedef struct krb5_kdcpreauth_callbacks {
    krb5_keyblock* (*fast_armor)(krb5_context, krb5_kdcpreauth_rock);
    krb5_error_code (*get_string)(krb5_context, krb5_kdcpreauth_rock, const char*, char**);
    void (*free_string)(krb5_context, krb5_kdcpreauth_rock, char*);
    void* (*event_context)(krb5_context, krb5_kdcpreauth_rock);
} *krb5_kdcpreauth_callbacks;

typedef struct otp_state otp_state;

#define KRB5KDC_ERR_PREAUTH_FAILED (-1)
#define KRB5_PREAUTH_FAILED (-2)
#define TKT_FLG_PRE_AUTH (1 << 0)

static inline krb5_data make_data(unsigned char *contents, size_t length) {
    krb5_data d;
    d.contents = contents;
    d.length = length;
    return d;
}
krb5_error_code decode_krb5_pa_otp_req(krb5_data *, krb5_pa_otp_req **);
void k5_free_pa_otp_req(krb5_context, krb5_pa_otp_req *);
void *k5alloc(size_t, krb5_error_code *);
void com_err(const char *, krb5_error_code, const char *);
krb5_error_code decrypt_encdata(krb5_context, krb5_keyblock *, krb5_pa_otp_req *, krb5_data *);
krb5_error_code nonce_verify(krb5_context, krb5_keyblock *, krb5_data *);
krb5_error_code timestamp_verify(krb5_context, krb5_data *);
void on_response(void *, krb5_error_code, krb5_pa_data **, krb5_data **, krb5_kdcpreauth_moddata *);
void otp_state_verify(otp_state *, void *, krb5_principal, char *, krb5_pa_otp_req *, void (*)(void *, krb5_error_code, krb5_pa_data **, krb5_data **, krb5_kdcpreauth_moddata *), struct request_state *);
void krb5_free_data_contents(krb5_context, krb5_data *);