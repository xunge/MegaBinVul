#include <stddef.h>

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C
#define FAILURE (-1)
#define SUCCESS 0
#define E_WARNING 2

struct _php_serializer {
    int (*decode)(const char *, int);
};

struct _php_session {
    struct _php_serializer *serializer;
};

extern struct _php_session php_session_globals;
#define PS(session) (php_session_globals.session)

void php_error_docref(const char *ref, int level, const char *format, ...);
void php_session_destroy(void);