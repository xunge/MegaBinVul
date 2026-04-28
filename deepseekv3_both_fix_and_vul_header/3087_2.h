#include <stdlib.h>
#include <string.h>

#define TSRMLS_D void
#define TSRMLS_C
#define TSRMLS_CC

#define FAILURE (-1)
#define SUCCESS 0
#define E_ERROR 1
#define E_NOTICE 2
#define php_session_active 1

typedef struct _ps_module {
    char *s_name;
    int (*s_open)(void **, const char *, const char *);
    char *(*s_create_sid)(void **, const char *);
    int (*s_read)(void **, const char *, char **, int *);
} ps_module;

typedef struct {
    ps_module *mod;
    void *mod_data;
    char *save_path;
    char *session_name;
    char *id;
    int use_cookies;
    int send_cookie;
    int use_trans_sid;
    int use_only_cookies;
    int apply_trans_sid;
    int session_status;
    int invalid_session_id;
} php_session;

extern php_session php_session_globals;
#define PS(name) (php_session_globals.name)

void php_error_docref(const char *docref, int type, const char *format, ...);
void php_session_decode(char *val, int vallen);
void php_session_track_init(void);
void php_session_reset_id(void);
void efree(void *ptr);