#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>

typedef int krb5_error_code;
typedef void* krb5_context;
typedef struct krb5_kdc_configuration krb5_kdc_configuration;
typedef int krb5_boolean;

typedef struct {
    size_t length;
    void* data;
} krb5_data;

typedef struct _TransitedEncoding {
    int tr_type;
    krb5_data contents;
} TransitedEncoding;

typedef struct {
    unsigned int transited_policy_checked;
} krb5_flags;

typedef struct _EncTicketPart {
    krb5_flags flags;
    TransitedEncoding transited;
} EncTicketPart;

#define DOMAIN_X500_COMPRESS 1
#define KRB5KDC_ERR_TRTYPE_NOSUPP 1
#define ERANGE 34
#define ENOMEM 12

void kdc_log(krb5_context, krb5_kdc_configuration*, int, const char*, ...);
void krb5_warn(krb5_context, krb5_error_code, const char*, ...);
krb5_error_code krb5_domain_x500_decode(krb5_context, krb5_data, char***, unsigned int*, const char*, const char*);
krb5_error_code krb5_check_transited(krb5_context, const char*, const char*, char**, unsigned int, void*);
krb5_error_code krb5_domain_x500_encode(char**, unsigned int, krb5_data*);