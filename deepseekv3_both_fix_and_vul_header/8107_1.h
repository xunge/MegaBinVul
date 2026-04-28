#include <stdlib.h>

typedef struct _php_snmp_object {
    void *zo;
    void *session;
} php_snmp_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define efree free

void netsnmp_session_free(void **session);
void zend_object_std_dtor(void *zo TSRMLS_CC);