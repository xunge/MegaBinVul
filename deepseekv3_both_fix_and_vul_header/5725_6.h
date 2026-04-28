#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, int *return_value, void **return_value_ptr, void *this_ptr, int return_value_used
#define RETURN_NULL() { *return_value = 0; return; }
#define RETURN_FALSE { *return_value = 0; return; }
#define TSRMLS_CC
#define TSRMLS_C
#define FAILURE (-1)
#define REPORT_ERRORS 1
#define ZEND_NUM_ARGS() 0
#define PHP_STREAM_FLAG_NO_FCLOSE (1<<0)

typedef struct {
    int flags;
    int rsrc_id;
} php_stream;

typedef struct {
    // dummy context
} php_stream_context;

typedef struct {
    // dummy zval
} zval;

typedef struct {
    // dummy class entry
} zend_class_entry;

zend_class_entry *dir_class_entry_ptr;

void php_set_default_dir(int rsrc_id);
void php_stream_auto_cleanup(php_stream *stream);
void php_stream_to_zval(php_stream *stream, int *res);
php_stream *php_stream_opendir(const char *path, int options, php_stream_context *context);
php_stream_context *php_stream_context_from_zval(zval *zcontext, int flags);
int zend_parse_parameters(int num_args, const char *type_spec, ...);
void object_init_ex(int *return_value, zend_class_entry *ce);
void add_property_stringl(int *return_value, const char *name, char *value, int len, int dup);
void add_property_resource(int *return_value, const char *name, int value);