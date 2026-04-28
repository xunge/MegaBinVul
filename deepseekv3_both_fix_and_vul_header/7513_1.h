typedef struct gnutls_session_int *gnutls_session_t;
typedef struct gnutls_certificate_credentials_int *gnutls_certificate_credentials_t;
typedef struct gnutls_datum_t {
    unsigned char *data;
    unsigned int size;
} gnutls_datum_t;
typedef int gnutls_pk_algorithm_t;
typedef struct gnutls_retr_st {
    gnutls_pk_algorithm_t pk_algorithm;
    gnutls_datum_t cert;
    gnutls_datum_t key;
    gnutls_datum_t chain;
} gnutls_retr_st;

extern int weechat_no_gnutls;
extern gnutls_certificate_credentials_t gnutls_xcred;
extern int network_init_gnutls_ok;

int gnutls_global_init(void);
int gnutls_certificate_allocate_credentials(gnutls_certificate_credentials_t *);
void network_load_ca_files(int unused);
int hook_connect_gnutls_verify_certificates(gnutls_session_t session);
int hook_connect_gnutls_set_certificates(gnutls_session_t session,
                                        const gnutls_datum_t *req_ca_rdn,
                                        int nreqs,
                                        const gnutls_pk_algorithm_t *pk_algos,
                                        int pk_algos_length,
                                        gnutls_retr_st *st);