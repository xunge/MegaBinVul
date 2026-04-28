#include <sys/types.h>
#include <errno.h>
#include <string.h>

typedef int krb5_error_code;
typedef int krb5_enctype;

#define EINVAL 22
#define ENOMEM 12
#define FALSE 0

#define ENCTYPE_DSA_SHA1_CMS 0
#define ENCTYPE_MD5_RSA_CMS 0
#define ENCTYPE_SHA1_RSA_CMS 0
#define ENCTYPE_RC2_CBC_ENV 0
#define ENCTYPE_RSA_ENV 0
#define ENCTYPE_RSA_ES_OAEP_ENV 0
#define ENCTYPE_DES3_CBC_ENV 0

extern int krb5int_c_deprecated_enctype(krb5_enctype ktype);
extern krb5_error_code krb5_enctype_to_name(krb5_enctype ktype, int flag, char *buf, size_t buflen);