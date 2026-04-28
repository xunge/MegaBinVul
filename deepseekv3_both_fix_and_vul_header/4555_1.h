#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define ZEND_WRONG_PARAM_COUNT() 
#define RETURN_FALSE 
#define TSRMLS_CC
#define SUCCESS 0
#define FAILURE -1
#define HASH_KEY_IS_STRING 1
#define E_WARNING 2
#define MAXPATHLEN 4096
#define TTFTEXT_BBOX 1
#define HAVE_GD_FREETYPE 1
#define VCWD_REALPATH(a,b) realpath(a,b)
#define PHP_GD_CHECK_OPEN_BASEDIR(a,b)
#define M_PI 3.14159265358979323846

typedef struct _gdFTStringExtra {
    int flags;
    double linespacing;
} gdFTStringExtra;

typedef struct _zval {
    long value;
    int type;
} zval;
typedef struct _zend_hash_key {
    char *arKey;
    unsigned int nKeyLength;
    unsigned long h;
} zend_hash_key;
typedef struct _HashTable {
    int dummy;
} HashTable;
typedef struct _HashPosition {
    int dummy;
} HashPosition;
typedef struct _gdImage {
    int dummy;
} gdImage;
typedef gdImage *gdImagePtr;

#define le_gd 0
#define Z_DVAL_PP(a) (*(a))->value
#define RETVAL_FALSE 
#define ZVAL_FALSE(z) 
#define ZVAL_BOOL(z, b) 
#define convert_to_double_ex(a) 
#define add_next_index_long(a, b) 
#define php_error_docref(a, b, c, ...) 
#define array_init(a) 
#define zend_wrong_param_count() 
#define zend_parse_parameters(a, b, ...) 0
#define zend_hash_internal_pointer_reset_ex(a, b) 
#define zend_hash_get_current_key_ex(a, b, c, d, e, f) 0
#define zend_hash_get_current_data_ex(a, b, c) 0
#define zend_hash_move_forward_ex(a, b) 0
#define HASH_OF(a) NULL
#define ZEND_FETCH_RESOURCE(a, b, c, d, e, f) 
#define gdFTEX_LINESPACE 1