#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FS_IS_DIR 0
#define SPL_FS_FILE 0
#define FAILURE -1
#define SUCCESS 0
#define IS_SLASH_AT(str, pos) ((str)[pos] == '/' || (str)[pos] == '\\')
#define REPORT_ERRORS 0
#define USE_PATH 0
#define TSRMLS_DC
#define TSRMLS_CC

typedef struct _zval {
    long value;
    int type;
    int refcount__gc;
} zval;

typedef struct _php_stream {
    char *orig_path;
} php_stream;

typedef struct _php_stream_context {
    // context fields
} php_stream_context;

typedef struct _zend_function {
    // function fields
} zend_function;

typedef struct _HashTable {
    // hash table fields
} HashTable;

typedef struct _zend_class_entry {
    HashTable function_table;
    // other class fields
} zend_class_entry;

typedef struct _zend_object {
    zend_class_entry *ce;
    // other object fields
} zend_object;

struct _executor_globals {
    void *exception;
};

extern struct _executor_globals executor_globals;

typedef struct _spl_filesystem_object {
    zend_object std;
    char *file_name;
    size_t file_name_len;
    char *orig_path;
    int type;
    union {
        struct {
            php_stream *stream;
            zval *zcontext;
            php_stream_context *context;
            char *open_mode;
            size_t open_mode_len;
            zval zresource;
            char delimiter;
            char enclosure;
            char escape;
            zend_function *func_getCurr;
        } file;
    } u;
} spl_filesystem_object;

extern void *spl_ce_LogicException;
extern void *spl_ce_RuntimeException;

#define Z_LVAL(z) (z).value
#define EG(v) (executor_globals.v)
#define Z_RESVAL_P(zp) (zp)->value
#define ZVAL_RESOURCE(zp, res) do { \
    (zp)->value = res; \
    (zp)->type = 1; /* IS_RESOURCE */ \
} while (0)
#define Z_SET_REFCOUNT(z, rc) (z).refcount__gc = rc

char *estrndup(const char *s, size_t length);
void php_stat(const char *filename, size_t filename_len, int stat_flags, zval *return_value TSRMLS_DC);
php_stream_context *php_stream_context_from_zval(zval *zcontext, int flags);
php_stream *php_stream_open_wrapper_ex(const char *path, const char *mode, int options, char **opened_path, php_stream_context *context);
long php_stream_get_resource_id(php_stream *stream);
void zend_throw_exception_ex(void *exception, long code TSRMLS_DC, const char *format, ...);
void zend_list_addref(long id);
void zend_hash_find(HashTable *ht, const char *key, size_t key_len, void **result);