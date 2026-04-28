#include <stddef.h>

typedef struct _krb5_keyblock {
    int dummy;
} krb5_keyblock;

typedef struct _krb5_pa_data {
    unsigned int length;
    unsigned char *contents;
} krb5_pa_data;

typedef struct _krb5_kdc_req {
    int nonce;
} krb5_kdc_req;

typedef struct _krb5_pa_s4u_x509_user {
    struct {
        void *user;
        struct {
            unsigned int length;
        } subject_cert;
    } user_id;
} krb5_pa_s4u_x509_user;

typedef struct _krb5_data {
    unsigned int length;
    char *data;
} krb5_data;

typedef int krb5_error_code;
typedef void* krb5_context;

#define KRB5KDC_ERR_C_PRINCIPAL_UNKNOWN 1

extern krb5_error_code decode_krb5_pa_s4u_x509_user(krb5_data *, krb5_pa_s4u_x509_user **);
extern krb5_error_code verify_s4u_x509_user_checksum(krb5_context, krb5_keyblock *, krb5_data *, int, krb5_pa_s4u_x509_user *);
extern void krb5_free_pa_s4u_x509_user(krb5_context, krb5_pa_s4u_x509_user *);
extern int krb5_princ_size(krb5_context, void *);