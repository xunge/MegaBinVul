#include <stddef.h>
#include <syslog.h>
#include <stdint.h>
#include <string.h>

typedef unsigned int krb5_flags;
typedef int krb5_error_code;
typedef int krb5_boolean;
#define TRUE 1
#define FALSE 0

typedef struct krb5_context *krb5_context;
typedef struct krb5_keyblock {
    int enctype;
} krb5_keyblock;

typedef struct krb5_ticket_times {
    int authtime;
    int starttime;
    int endtime;
    int renew_till;
} krb5_ticket_times;

typedef struct krb5_enc_tkt_part {
    krb5_flags flags;
    void *authorization_data;
    void *caddrs;
    void *client;
    void *session;
    void *transited;
    krb5_ticket_times times;
} krb5_enc_tkt_part;

typedef struct krb5_enc_data {
    void *data;
    size_t length;
} krb5_enc_data;

typedef struct krb5_ticket {
    void *server;
    krb5_enc_tkt_part *enc_part2;
    struct {
        int kvno;
        int enctype;
        krb5_enc_data ciphertext;
    } enc_part;
} krb5_ticket;

typedef struct krb5_enc_kdc_rep_part {
    void *session;
    void *nonce;
    krb5_ticket_times times;
    void *last_req;
    int key_exp;
    krb5_flags flags;
    void *server;
    void *caddrs;
    void *enc_padata;
} krb5_enc_kdc_rep_part;

typedef struct krb5_kdc_rep {
    int msg_type;
    void *client;
    krb5_ticket *ticket;
    struct {
        int kvno;
        int enctype;
        krb5_enc_data ciphertext;
    } enc_part;
    void *padata;
} krb5_kdc_rep;

typedef void *krb5_pac;
typedef void *krb5_db_entry;
typedef void *krb5_principal;

typedef struct krb5_last_req_entry {
    int magic;
    int lr_type;
    int value;
} krb5_last_req_entry;

typedef struct krb5_data {
    void *data;
    size_t length;
} krb5_data;

typedef struct krb5_fulladdr {
    void *addr;
    int port;
} krb5_fulladdr;

typedef struct krb5_kdc_req {
    krb5_flags kdc_options;
    void *addresses;
    void *server;
    void *padata;
    int nonce;
} krb5_kdc_req;

typedef struct krb5_pa_data {
    int padata_type;
    krb5_data padata_value;
} krb5_pa_data;

struct tgs_req_info {
    krb5_kdc_req *req;
    krb5_db_entry *client;
    krb5_db_entry *server;
    krb5_keyblock *header_key;
    krb5_db_entry *header_server;
    krb5_pac header_pac;
    krb5_ticket *header_tkt;
    krb5_keyblock *stkt_server_key;
    krb5_db_entry *stkt_server;
    krb5_pac stkt_pac;
    krb5_ticket *stkt;
    krb5_keyblock *subkey;
    krb5_principal tkt_client;
    void *transited;
    krb5_principal cprinc;
    krb5_principal sprinc;
    krb5_principal s4u_cprinc;
    int authtime;
    krb5_flags flags;
    krb5_ticket *subject_tkt;
    krb5_data *auth_indicators;
    krb5_principal *s4u2self;
    krb5_keyblock *local_tgt_key;
    krb5_ticket *local_tgt;
    int is_referral;
};

typedef struct kdc_realm_t {
    krb5_context realm_context;
} kdc_realm_t;

typedef struct krb5_audit_state {
    int stage;
    void *tkt_out_id;
    const char *status;
    krb5_kdc_rep *reply;
} krb5_audit_state;

struct kdc_request_state {
    int flags;
    krb5_keyblock *reply_key;
    krb5_keyblock *strengthen_key;
    void *padata;
    int hide_client;
};

#define KRB5_KDB_FLAG_CONSTRAINED_DELEGATION 0x01
#define KRB5_LRQ_NONE 0
#define KV5M_LAST_REQ_ENTRY 0
#define KRB5_TGS_REP 0
#define KDC_OPT_ENC_TKT_IN_SKEY 0x01
#define KDC_OPT_VALIDATE 0x02
#define KDC_OPT_RENEW 0x04
#define KDC_OPT_FORWARDED 0x08
#define KDC_OPT_PROXY 0x10
#define KDC_OPT_CANONICALIZE 0x20
#define KRB5_PADATA_S4U_X509_USER 0x40
#define ISSUE_TKT 0
#define ENCR_REP 1

krb5_error_code gen_session_key(krb5_context, void*, void*, krb5_keyblock*, const char**);
krb5_error_code get_first_current_key(krb5_context, void*, krb5_keyblock*);
krb5_error_code handle_authdata(kdc_realm_t*, krb5_flags, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
void krb5_klog_syslog(int, const char*, int);
krb5_error_code krb5_encrypt_tkt_part(krb5_context, krb5_keyblock*, krb5_ticket*);
void kau_u2u(krb5_context, krb5_boolean, krb5_audit_state*);
int current_kvno(void*);
krb5_pa_data *krb5int_find_pa_data(krb5_context, void*, int);
krb5_error_code kdc_make_s4u2self_rep(krb5_context, krb5_keyblock*, void*, void*, krb5_kdc_rep*, krb5_enc_kdc_rep_part*);
krb5_error_code kdc_fast_response_handle_padata(struct kdc_request_state*, void*, krb5_kdc_rep*, int);
krb5_error_code kdc_fast_handle_reply_key(struct kdc_request_state*, krb5_keyblock*, krb5_keyblock**);
krb5_error_code return_enc_padata(krb5_context, krb5_data*, void*, krb5_keyblock*, void*, krb5_enc_kdc_rep_part*, int);
krb5_error_code kau_make_tkt_id(krb5_context, krb5_ticket*, void**);
int kdc_fast_hide_client(struct kdc_request_state*);
krb5_principal krb5_anonymous_principal(void);
krb5_error_code krb5_encode_kdc_rep(krb5_context, int, krb5_enc_kdc_rep_part*, int, krb5_keyblock*, krb5_kdc_rep*, krb5_data**);
void log_tgs_req(krb5_context, const krb5_fulladdr*, void*, krb5_kdc_rep*, void*, void*, void*, int, krb5_flags, const char*, int, void*);
void kau_s4u2proxy(krb5_context, krb5_boolean, krb5_audit_state*);
void kau_tgs_req(krb5_context, krb5_boolean, krb5_audit_state*);
void krb5_free_pa_data(krb5_context, void*);
void krb5_free_authdata(krb5_context, void*);
void krb5_free_keyblock_contents(krb5_context, krb5_keyblock*);
void krb5_free_keyblock(krb5_context, krb5_keyblock*);
void zapfree(void*, size_t);