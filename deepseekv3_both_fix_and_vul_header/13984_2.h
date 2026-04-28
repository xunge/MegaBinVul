#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef int krb5_error_code;
typedef struct kdc_realm_t kdc_realm_t;
typedef struct krb5_pa_data {
    unsigned int length;
    unsigned char *contents;
} krb5_pa_data;
typedef struct krb5_keyblock krb5_keyblock;
typedef struct krb5_pa_s4u_x509_user {
    struct {
        char *user;
    } user_id;
} krb5_pa_s4u_x509_user;
typedef struct krb5_pa_for_user {
    char *user;
} krb5_pa_for_user;
typedef struct krb5_data {
    unsigned int length;
    char *data;
} krb5_data;

extern krb5_error_code decode_krb5_pa_for_user(krb5_data *, krb5_pa_for_user **);
extern krb5_error_code verify_for_user_checksum(void *, krb5_keyblock *, krb5_pa_for_user *);
extern void krb5_free_pa_for_user(void *, krb5_pa_for_user *);

extern void *kdc_context;