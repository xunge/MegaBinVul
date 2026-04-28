#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef int krb5_error_code;
typedef struct krb5_context *krb5_context;
typedef struct krb5_data {
    unsigned int length;
    unsigned char *data;
} krb5_data;
typedef struct krb5_kdc_req {
    void *server;
    void *client;
} krb5_kdc_req;
typedef struct krb5_enc_tkt_part {
    unsigned int flags;
} krb5_enc_tkt_part;
typedef struct krb5_pa_data {
    int pa_type;
    unsigned int length;
    unsigned char *contents;
} krb5_pa_data;
typedef struct krb5_kdcpreauth_callbacks {
    krb5_data *(*request_body)(krb5_context, void*);
} *krb5_kdcpreauth_callbacks;
typedef void *krb5_kdcpreauth_rock;
typedef void *krb5_kdcpreauth_moddata;
typedef void (*krb5_kdcpreauth_verify_respond_fn)(void *, int, void *, krb5_pa_data **, void *);
typedef struct krb5_pa_pk_as_req {
    struct {
        unsigned char *data;
        unsigned int length;
    } signedAuthPack;
    struct {
        unsigned char *data;
        unsigned int length;
    } kdcPkId;
} krb5_pa_pk_as_req;
typedef struct krb5_pa_pk_as_req_draft9 {
    struct {
        unsigned char *data;
        unsigned int length;
    } signedAuthPack;
} krb5_pa_pk_as_req_draft9;
typedef struct krb5_auth_pack {
    struct {
        unsigned int ctime;
        struct {
            unsigned int length;
            unsigned char *contents;
        } paChecksum;
    } pkAuthenticator;
    struct {
        struct {
            struct {
                void *parameters;
            } algorithm;
        } *clientPublicValue;
    };
} krb5_auth_pack;
typedef struct krb5_auth_pack_draft9 {
    struct {
        struct {
            struct {
                void *parameters;
            } algorithm;
        } *clientPublicValue;
    };
} krb5_auth_pack_draft9;
typedef struct pkinit_kdc_context {
    void *cryptoctx;
    void *idctx;
    struct {
        int require_crl_checking;
        int dh_min_bits;
    } *opts;
} *pkinit_kdc_context;
typedef struct pkinit_kdc_req_context {
    int pa_type;
    void *cryptoctx;
    void *rcv_auth_pack;
    void *rcv_auth_pack9;
} *pkinit_kdc_req_context;
typedef struct krb5_checksum {
    int checksum_type;
    unsigned int length;
    unsigned char *contents;
} krb5_checksum;
typedef void *krb5_kdcpreauth_modreq;

#define PADATA_TO_KRB5DATA(pad, k5d) \
    do { (k5d)->length = (pad)->length; (k5d)->data = (pad)->contents; } while (0)
#define OCTETDATA_TO_KRB5DATA(od, k5d) \
    do { (k5d)->length = (od)->length; (k5d)->data = (od)->data; } while (0)

#define CMS_SIGN_CLIENT 1
#define CMS_SIGN_DRAFT9 2
#define TKT_FLG_PRE_AUTH 0x00000010
#define CKSUMTYPE_NIST_SHA 0x0F
#define KRB5_PADATA_PK_AS_REQ 16
#define KRB5_PADATA_PK_AS_REQ_OLD 17
#define KRB5_PADATA_PK_AS_REP_OLD 18
#define KRB5KDC_ERR_CLIENT_NAME_MISMATCH (-1765328359)
#define KRB5KDC_ERR_INCONSISTENT_KEY_PURPOSE (-1765328358)
#define KRB5KDC_ERR_PREAUTH_FAILED (-1765328352)
#define KRB5KDC_ERR_PA_CHECKSUM_MUST_BE_INCLUDED (-1765328349)

#define pkiDebug(...)
#define k5_bcmp memcmp
#define EINVAL 22

static pkinit_kdc_context pkinit_find_realm_context(krb5_context context, 
                                                   krb5_kdcpreauth_moddata moddata, 
                                                   void *server) { return NULL; }
static krb5_error_code pkinit_init_kdc_req_context(krb5_context context, 
                                                  pkinit_kdc_req_context *reqctx) { return 0; }
static krb5_error_code k5int_decode_krb5_pa_pk_as_req(krb5_data *data, 
                                                     krb5_pa_pk_as_req **req) { return 0; }
static krb5_error_code cms_signeddata_verify(krb5_context context, 
                                            void *plgctx_cryptoctx,
                                            void *reqctx_cryptoctx,
                                            void *plgctx_idctx,
                                            int cms_sign_type,
                                            int require_crl_checking,
                                            unsigned char *signed_data,
                                            unsigned int signed_len,
                                            unsigned char **authp_data,
                                            unsigned int *authp_len,
                                            unsigned char **krb5_authz,
                                            unsigned int *krb5_authz_len,
                                            int *is_signed) { return 0; }
static krb5_error_code k5int_decode_krb5_pa_pk_as_req_draft9(krb5_data *data, 
                                                            krb5_pa_pk_as_req_draft9 **req) { return 0; }
static krb5_error_code verify_client_san(krb5_context context,
                                        pkinit_kdc_context plgctx,
                                        pkinit_kdc_req_context reqctx,
                                        void *client,
                                        int *valid_san) { return 0; }
static krb5_error_code verify_client_eku(krb5_context context,
                                        pkinit_kdc_context plgctx,
                                        pkinit_kdc_req_context reqctx,
                                        int *valid_eku) { return 0; }
static int krb5_principal_compare(krb5_context context, void *client1, void *client2) { return 0; }
static void *krb5_anonymous_principal(void) { return NULL; }
static void krb5_set_error_message(krb5_context context, krb5_error_code code, const char *msg) {}
static const char *_(const char *msg) { return msg; }
static krb5_error_code k5int_decode_krb5_auth_pack(krb5_data *data, krb5_auth_pack **auth_pack) { return 0; }
static krb5_error_code krb5_check_clockskew(krb5_context context, unsigned int ctime) { return 0; }
static krb5_error_code server_check_dh(krb5_context context,
                                      void *plgctx_cryptoctx,
                                      void *reqctx_cryptoctx,
                                      void *plgctx_idctx,
                                      void *params,
                                      int dh_min_bits) { return 0; }
static krb5_error_code krb5_c_make_checksum(krb5_context context,
                                           int cksumtype,
                                           void *key,
                                           int usage,
                                           krb5_data *input,
                                           krb5_checksum *cksum) { return 0; }
static krb5_error_code pkinit_check_kdc_pkid(krb5_context context,
                                            void *plgctx_cryptoctx,
                                            void *reqctx_cryptoctx,
                                            void *plgctx_idctx,
                                            unsigned char *kdcPkId,
                                            unsigned int length,
                                            int *valid) { return 0; }
static krb5_error_code k5int_decode_krb5_auth_pack_draft9(krb5_data *data, 
                                                         krb5_auth_pack_draft9 **auth_pack) { return 0; }
static krb5_error_code pkinit_create_edata(krb5_context context,
                                          void *plgctx_cryptoctx,
                                          void *reqctx_cryptoctx,
                                          void *plgctx_idctx,
                                          void *opts,
                                          krb5_error_code retval,
                                          krb5_pa_data ***e_data) { return 0; }
static void pkinit_fini_kdc_req_context(krb5_context context, pkinit_kdc_req_context reqctx) {}
static void free_krb5_pa_pk_as_req(krb5_pa_pk_as_req **req) {}
static void free_krb5_pa_pk_as_req_draft9(krb5_pa_pk_as_req_draft9 **req) {}
static void free_krb5_auth_pack(krb5_auth_pack **auth_pack) {}
static void free_krb5_auth_pack_draft9(krb5_context context, krb5_auth_pack_draft9 **auth_pack) {}