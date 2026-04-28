#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C

#define SUCCESS 0
#define FAILURE -1

typedef struct _zval_struct {
    long type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
    } value;
} zval;

typedef struct _smart_str {
    char *c;
    size_t len;
    size_t a;
} smart_str;

typedef struct {
    char *c;
    size_t len;
} smart_str_data;

typedef struct {
    zval sid;
    smart_str key;
    int apply_trans_sid;
    zval *data;
    zval *post_bytes_processed;
    zval *files;
    zval *current_file;
    zval *current_file_bytes_processed;
    size_t content_length;
    size_t sname_len;
    size_t update_step;
    size_t next_update;
    double next_update_time;
    int cancel_upload;
} php_session_rfc1867_progress;

typedef struct {
    char *session_name;
    int rfc1867_enabled;
    php_session_rfc1867_progress *rfc1867_progress;
    smart_str_data rfc1867_name;
    smart_str_data rfc1867_prefix;
    int use_trans_sid;
    int rfc1867_freq;
    int rfc1867_cleanup;
    char *id;
    int apply_trans_sid;
    int send_cookie;
} php_session_struct;

#define PS(name) (php_session_globals.name)
extern php_session_struct php_session_globals;

typedef struct {
    size_t content_length;
} multipart_event_start;

typedef struct {
    char *name;
    char **value;
    size_t length;
    size_t *newlength;
} multipart_event_formdata;

typedef struct {
    char *name;
    char **filename;
    size_t post_bytes_processed;
} multipart_event_file_start;

typedef struct {
    size_t offset;
    size_t length;
    size_t post_bytes_processed;
} multipart_event_file_data;

typedef struct {
    char *temp_filename;
    size_t post_bytes_processed;
    int cancel_upload;
} multipart_event_file_end;

typedef struct {
    size_t post_bytes_processed;
} multipart_event_end;

enum {
    MULTIPART_EVENT_START,
    MULTIPART_EVENT_FORMDATA,
    MULTIPART_EVENT_FILE_START,
    MULTIPART_EVENT_FILE_DATA,
    MULTIPART_EVENT_FILE_END,
    MULTIPART_EVENT_END
};

static int (*php_session_rfc1867_orig_callback)(unsigned int, void *, void **);

#define Z_TYPE(z) (z).type
#define Z_STRVAL(z) (z).value.str.val
#define Z_STRLEN(z) (z).value.str.len
#define Z_LVAL_P(z) (*(z)).value.lval

static void *ecalloc(size_t nmemb, size_t size) {
    return calloc(nmemb, size);
}

static void efree(void *ptr) {
    free(ptr);
}

static void zval_dtor(zval *z) {
    if (Z_TYPE(*z) && Z_STRVAL(*z)) {
        free(Z_STRVAL(*z));
    }
}

static void ZVAL_STRINGL(zval *z, char *s, size_t l, int dup) {
    z->type = 1;
    if (dup) {
        z->value.str.val = strndup(s, l);
    } else {
        z->value.str.val = s;
    }
    z->value.str.len = l;
}

static void ZVAL_LONG(zval *z, long l) {
    z->type = 2;
    z->value.lval = l;
}

static void smart_str_free(smart_str *s) {
    if (s->c) {
        free(s->c);
        s->c = NULL;
    }
    s->len = 0;
    s->a = 0;
}

static void smart_str_appendl(smart_str *s, char *c, size_t len) {
    s->c = realloc(s->c, s->len + len + 1);
    memcpy(s->c + s->len, c, len);
    s->len += len;
    s->c[s->len] = '\0';
}

static void smart_str_0(smart_str *s) {
    if (s->c) {
        s->c[s->len] = '\0';
    }
}

static char *estrndup(char *s, size_t len) {
    return strndup(s, len);
}

static long sapi_get_request_time(void) {
    return time(NULL);
}