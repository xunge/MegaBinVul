#include <stdlib.h>
#include <string.h>

typedef struct _pcre_cache_entry {
    void *re;
    void *extra;
} pcre_cache_entry;

typedef struct _pcre_extra {
    unsigned long int flags;
    void *study_data;
    unsigned long int match_limit;
    unsigned long int match_limit_recursion;
} pcre_extra;

typedef struct _zval {
    void *value;
    int type;
} zval;

#define TSRMLS_DC
#define TSRMLS_CC
#define PHPAPI
#define PREG_PATTERN_ORDER 1
#define PREG_SET_ORDER 2
#define PREG_OFFSET_CAPTURE 0x100
#define PCRE_NO_UTF8_CHECK 0x40000000
#define PCRE_NOTEMPTY 0x00000004
#define PCRE_ANCHORED 0x00000010
#define PCRE_ERROR_NOMATCH (-1)
#define PHP_PCRE_NO_ERROR 0
#define E_WARNING 2
#define E_NOTICE 8
#define PCRE_EXTRA_MATCH_LIMIT 0x00000001
#define PCRE_EXTRA_MATCH_LIMIT_RECURSION 0x00000002
#define PCRE_INFO_CAPTURECOUNT 2

#define Z_ARRVAL_P(zval) ((zval)->value)
#define Z_ADDREF_P(zval)
#define RETVAL_FALSE
#define RETVAL_LONG(x)
#define RETURN_FALSE
#define ALLOC_ZVAL(z) (z = malloc(sizeof(zval)))
#define INIT_PZVAL(z)
#define PCRE_G(x) (x)
#define safe_emalloc(n, size, offset) malloc((n)*(size)+(offset))
#define efree free

extern int backtrack_limit;
extern int recursion_limit;
extern int error_code;

void zval_dtor(zval *);
void array_init(zval *);
void add_next_index_stringl(zval *, char *, int, int);
void add_next_index_string(zval *, char *, int);
void add_assoc_stringl(zval *, char *, char *, int, int);
void add_offset_pair(zval *, char *, int, int, char *);
void php_error_docref(const char *, int, const char *, ...);
void pcre_handle_exec_error(int);
char **make_subpats_table(int, pcre_cache_entry *);