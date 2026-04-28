#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef int krb5_error_code;
typedef int krb5_timestamp;
typedef int krb5_flags;

typedef struct krb5_key_data {
    int key_data_kvno;
} krb5_key_data;

typedef struct krb5_keyblock {
    int enctype;
    unsigned char *contents;
    int length;
} krb5_keyblock;

typedef struct krb5_data {
    unsigned char *data;
    int length;
} krb5_data;

typedef struct krb5_principal {
    char *data;
} *krb5_principal;

typedef struct krb5_db_entry {
    krb5_principal princ;
} krb5_db_entry;

typedef struct krb5_kdc_req {
    int nonce;
} krb5_kdc_req;

typedef struct {
    int authtime;
} krb5_times;

typedef struct krb5_enc_tkt_part {
    krb5_principal client;
    krb5_principal server;
    int flags;
    krb5_times times;
    void *authorization_data;
    void *caddrs;
} krb5_enc_tkt_part;

typedef struct krb5_ticket {
    struct {
        krb5_data ciphertext;
        int kvno;
    } enc_part;
    krb5_enc_tkt_part *enc_part2;
    krb5_principal server;
} krb5_ticket;

typedef struct krb5_kdc_rep {
    int msg_type;
    krb5_principal client;
    krb5_ticket *ticket;
    struct {
        int enctype;
        krb5_data ciphertext;
        int kvno;
    } enc_part;
    void *padata;
} krb5_kdc_rep;

typedef struct EncKDCRepPart {
    krb5_keyblock *session;
    void *last_req;
    int nonce;
    int key_exp;
    int flags;
    krb5_principal server;
    krb5_times times;
    void *caddrs;
    void *enc_padata;
} EncKDCRepPart;

typedef struct krb5_pa_data {
    // pa data fields
} krb5_pa_data;

typedef struct krb5_audit_state {
    int stage;
    const char *status;
    krb5_kdc_rep *reply;
    void *tkt_out_id;
} krb5_audit_state;

typedef struct kdc_realm_t {
    // realm fields
} kdc_realm_t;

typedef struct krb5_fast_state {
    // fast state fields
} krb5_fast_state;

typedef struct kdc_request_rock {
    // rock fields
} kdc_request_rock;

typedef struct as_req_state {
    kdc_realm_t *active_realm;
    krb5_audit_state *au_state;
    void *respond;
    void *arg;
    krb5_kdc_req *request;
    krb5_db_entry *client;
    krb5_db_entry *server;
    krb5_timestamp kdc_time;
    const char *status;
    krb5_enc_tkt_part enc_tkt_reply;
    krb5_keyblock server_keyblock;
    krb5_keyblock client_keyblock;
    krb5_key_data *client_key;
    krb5_ticket ticket_reply;
    krb5_kdc_rep reply;
    EncKDCRepPart reply_encpart;
    krb5_keyblock session_key;
    krb5_timestamp authtime;
    krb5_data *inner_body;
    krb5_pa_data *e_data;
    krb5_pa_data *typed_e_data;
    krb5_pa_data **req_padata;
    krb5_data *req_pkt;
    char *cname;
    char *sname;
    krb5_db_entry *local_tgt;
    krb5_db_entry *local_tgt_storage;
    krb5_flags c_flags;
    krb5_pa_data **auth_indicators;
    krb5_pa_data **pa_context;
    krb5_fast_state *rstate;
    kdc_request_rock rock;
    void *local_addr;
    void *remote_addr;
    int preauth_err;
} as_req_state;

typedef void (*loop_respond_fn)(void *, krb5_error_code, krb5_data *);

#define KRB5_AS_REP 11
#define ENCR_REP 1
#define ERROR_TABLE_BASE_krb5 0
#define KRB5KDC_ERR_ETYPE_NOSUPP 14
#define KRB5KDC_ERR_DISCARD 0
#define KRB_ERR_MAX 0
#define KRB_ERR_GENERIC 0
#define ENCTYPE_NULL 0
#define FALSE 0
#define TRUE 1
#define LOG_INFO 0

extern void *kdc_context;
extern krb5_error_code validate_forwardable(krb5_kdc_req *, krb5_db_entry, krb5_db_entry, krb5_timestamp, const char **);
extern krb5_error_code check_indicators(void *, krb5_db_entry *, krb5_pa_data **);
extern krb5_error_code krb5_dbe_find_enctype(void *, krb5_db_entry *, int, int, int, krb5_key_data **);
extern krb5_error_code krb5_dbe_decrypt_key_data(void *, void *, krb5_key_data *, krb5_keyblock *, void *);
extern krb5_error_code fetch_last_req_info(krb5_db_entry *, void *);
extern krb5_timestamp get_key_exp(krb5_db_entry *);
extern krb5_error_code return_padata(void *, kdc_request_rock *, krb5_data *, krb5_kdc_req *, krb5_kdc_rep *, krb5_keyblock *, krb5_pa_data ***);
extern krb5_error_code handle_authdata(void *, krb5_flags, krb5_db_entry *, krb5_db_entry *, void *, krb5_db_entry *, krb5_keyblock *, krb5_keyblock *, void *, krb5_data *, krb5_kdc_req *, void *, void *, krb5_pa_data **, krb5_enc_tkt_part *);
extern krb5_error_code krb5_encrypt_tkt_part(void *, krb5_keyblock *, krb5_ticket *);
extern krb5_error_code kau_make_tkt_id(void *, krb5_ticket *, void *);
extern krb5_error_code kdc_fast_response_handle_padata(krb5_fast_state *, krb5_kdc_req *, krb5_kdc_rep *, int);
extern krb5_error_code kdc_fast_handle_reply_key(krb5_fast_state *, krb5_keyblock *, krb5_keyblock **);
extern krb5_error_code return_enc_padata(void *, krb5_data *, krb5_kdc_req *, krb5_keyblock *, krb5_db_entry *, EncKDCRepPart *, int);
extern int kdc_fast_hide_client(krb5_fast_state *);
extern krb5_principal krb5_anonymous_principal(void);
extern krb5_error_code krb5_encode_kdc_rep(void *, int, EncKDCRepPart *, int, krb5_keyblock *, krb5_kdc_rep *, krb5_data **);
extern void log_as_req(void *, void *, void *, krb5_kdc_req *, krb5_kdc_rep *, krb5_db_entry *, char *, krb5_db_entry *, char *, krb5_timestamp, const char *, krb5_error_code, const char *);
extern void kau_as_req(void *, int, krb5_audit_state *);
extern void kau_free_kdc_req(krb5_audit_state *);
extern void free_padata_context(void *, krb5_pa_data **);
extern void krb5_free_keyblock(void *, krb5_keyblock *);
extern const char *krb5_get_error_message(void *, krb5_error_code);
extern void krb5_free_error_message(void *, const char *);
extern void krb5_free_authdata(void *, void *);
extern void krb5_free_keyblock_contents(void *, krb5_keyblock *);
extern void krb5_free_pa_data(void *, krb5_pa_data *);
extern void krb5_db_free_principal(void *, krb5_db_entry *);
extern void krb5_free_kdc_req(void *, krb5_kdc_req *);
extern void k5_free_data_ptr_list(krb5_pa_data **);
extern krb5_error_code prepare_error_as(krb5_fast_state *, krb5_kdc_req *, krb5_db_entry *, krb5_error_code, krb5_pa_data *, krb5_pa_data *, krb5_principal, krb5_data **, const char *);
extern void kdc_free_rstate(krb5_fast_state *);
extern void krb5_klog_syslog(int, const char *, ...);
extern void krb5_free_data(void *, krb5_data *);