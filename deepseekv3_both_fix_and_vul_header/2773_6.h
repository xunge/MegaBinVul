#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef int krb5_error_code;
typedef void *krb5_context;
typedef void *krb5_kdcpreauth_moddata;
typedef void *krb5_kdcpreauth_modreq;
typedef void *krb5_kdcpreauth_rock;
typedef void *krb5_kdcpreauth_callbacks;

typedef struct {
    int length;
    unsigned char *contents;
    int pa_type;
    int magic;
} krb5_pa_data;

typedef struct {
    int length;
    unsigned char *data;
} krb5_data;

typedef struct {
    int length;
    unsigned char *contents;
} krb5_keyblock;

typedef struct {
    int nktypes;
    int *ktype;
    krb5_pa_data **padata;
    void *server;
    void *client;
    int nonce;
} krb5_kdc_req;

typedef struct {
} krb5_kdc_rep;

typedef struct {
    unsigned char *data;
    int length;
} krb5_octet_data;

typedef struct {
    krb5_data subjectPublicKey;
    int nonce;
    int dhKeyExpiration;
} krb5_kdc_dh_key_info;

typedef struct {
    int choice;
    union {
        struct {
            krb5_data dhSignedData;
            int kdfID;
        } dh_Info;
        struct {
            krb5_data data;
            int length;
        } encKeyPack;
    } u;
} krb5_pa_pk_as_rep;

typedef struct {
    int choice;
    union {
        struct {
            krb5_data data;
            int length;
        } dhSignedData;
        struct {
            krb5_data data;
            int length;
        } encKeyPack;
    } u;
} krb5_pa_pk_as_rep_draft9;

typedef struct {
    krb5_data asChecksum;
    krb5_keyblock replyKey;
} krb5_reply_key_pack;

typedef struct {
    int nonce;
    krb5_keyblock replyKey;
} krb5_reply_key_pack_draft9;

typedef struct pkinit_kdc_context {
    void *cryptoctx;
    void *idctx;
} *pkinit_kdc_context;

typedef struct pkinit_kdc_req_context {
    int pa_type;
    struct {
        struct {
            struct {
                krb5_data subjectPublicKey;
            } *clientPublicValue;
            int *supportedKDFs;
        } *rcv_auth_pack;
        struct {
            struct {
                krb5_data subjectPublicKey;
            } *clientPublicValue;
            struct {
                int nonce;
            } pkAuthenticator;
        } *rcv_auth_pack9;
    };
    void *cryptoctx;
} *pkinit_kdc_req_context;

typedef struct {
    int length;
    unsigned char *data;
} krb5_pa_pk_as_req;

typedef struct {
    int length;
    unsigned char *data;
} krb5_pa_pk_as_req_draft9;

typedef int krb5_enctype;
typedef unsigned char krb5_octet;

#define KRB5_PADATA_PKINIT_KX 16
#define KRB5_PADATA_PK_AS_REQ 16
#define KRB5_PADATA_PK_AS_REP 17
#define KRB5_PADATA_PK_AS_REP_OLD 18
#define KRB5_PADATA_PK_AS_REQ_OLD 19

#define choice_pa_pk_as_rep_encKeyPack 0
#define choice_pa_pk_as_rep_dhInfo 1
#define choice_pa_pk_as_rep_draft9_encKeyPack 0
#define choice_pa_pk_as_rep_draft9_dhSignedData 1

#define CMS_SIGN_SERVER 1
#define CMS_SIGN_DRAFT9 2

#define KV5M_PA_DATA 1
#define KRB5KDC_ERR_ETYPE_NOSUPP 1
#define KRB5KDC_ERR_PREAUTH_FAILED 2
#define KRB5_KEYUSAGE_TGS_REQ_AUTH_CKSUM 3

static void pkiDebug(const char *fmt, ...) {}