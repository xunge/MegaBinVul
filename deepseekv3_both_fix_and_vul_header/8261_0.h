#include <stdlib.h>
#include <string.h>

typedef struct _zend_function zend_function;
typedef struct _zval zval;
typedef struct _zend_fcall_info zend_fcall_info;
typedef struct _zend_fcall_info_cache zend_fcall_info_cache;
typedef struct _spl_filesystem_object spl_filesystem_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define EG(x) (NULL)
#define ZVAL_STRING(z, s, p) 
#define ZVAL_ZVAL(z, v, c, d) 
#define RETVAL_FALSE 
#define FAILURE (-1)

struct _zend_function {
    struct {
        const char *function_name;
    } common;
};

struct _zval {
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
        void *ptr;
    } value;
};

struct _zend_fcall_info {
    size_t size;
    void *function_table;
    void *object_ptr;
    zval *function_name;
    zval **retval_ptr_ptr;
    int param_count;
    zval ***params;
    int no_separation;
    void *symbol_table;
};

struct _zend_fcall_info_cache {
    int initialized;
    zend_function *function_handler;
    void *calling_scope;
    void *called_scope;
    void *object_ptr;
};

struct _spl_filesystem_object {
    union {
        struct {
            zval zresource;
        } file;
    } u;
};

void *safe_emalloc(size_t nmemb, size_t size, size_t offset);
int zend_get_parameters_array_ex(int param_count, zval ***params);
int zend_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fcic TSRMLS_DC);
void efree(void *ptr);