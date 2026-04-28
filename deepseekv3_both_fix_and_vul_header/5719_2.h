#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, void *return_value, void **return_value_ptr, void *this_ptr, int return_value_used
#define TSRMLS_CC
#define TSRMLS_C
#define TSRMLS_DC
#define ZEND_NUM_ARGS() ht
#define FAILURE -1
#define RETURN_NULL()
#define RETURN_FALSE
#define REPORT_ERRORS 1
#define PHP_STREAM_FLAG_NO_FCLOSE (1<<0)

typedef struct _php_stream {
    int flags;
    int rsrc_id;
} php_stream;

typedef struct _php_stream_context php_stream_context;
typedef struct _zval_struct {
    int type;
} zval;

extern int zend_parse_parameters(int, const char *, ...);
extern php_stream *php_stream_opendir(const char *, int, php_stream_context *);
extern php_stream_context *php_stream_context_from_zval(zval *, int);
extern void php_set_default_dir(int);
extern void object_init_ex(zval *, void *);
extern void add_property_stringl(zval *, const char *, const char *, int, int);
extern void add_property_resource(zval *, const char *, int);
extern void php_stream_auto_cleanup(php_stream *);
extern void php_stream_to_zval(php_stream *, zval *);
extern void *dir_class_entry_ptr;