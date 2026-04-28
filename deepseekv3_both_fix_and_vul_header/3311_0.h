#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct ASN1_UTCTIME {
    int type;
    int length;
    unsigned char *data;
} ASN1_UTCTIME;

#define V_ASN1_UTCTIME 23
#define TSRMLS_DC
#define TSRMLS_CC
#define E_WARNING 2
#define HAVE_TM_GMTOFF 0
extern long timezone;
extern void php_error_docref(const char *docref, int type, const char *format, ...);
extern char *estrdup(const char *s);
extern void efree(void *ptr);