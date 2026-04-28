#include <stddef.h>

#define TSRMLS_D void
#define TSRMLS_CC
#define TSRMLS_C
#define SUCCESS 0
#define FAILURE -1
#define E_WARNING 2

typedef struct _php_session_module {
    int (*s_destroy)(void **, const char *);
} php_session_module;

typedef struct _php_session_status {
    int session_status;
    php_session_module *mod;
    void *mod_data;
    char *id;
} php_session_status;

#define PS(name) (php_session_globals.name)
#define php_session_active 1

extern php_session_status php_session_globals;

void php_error_docref(const char *docref, int type, const char *format, ...);
void php_rshutdown_session_globals(TSRMLS_D);
void php_rinit_session_globals(TSRMLS_D);