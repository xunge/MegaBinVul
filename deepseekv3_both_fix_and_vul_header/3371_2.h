#include <stdlib.h>

#define IS_BOOL 1
#define IS_LONG 2

typedef struct _gdImage {
    int dummy;
} *gdImagePtr;

typedef struct _gdPoint {
    int x, y;
} gdPoint;
typedef gdPoint *gdPointPtr;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define TSRMLS_CC
#define FAILURE (-1)
#define SUCCESS 0
#define E_WARNING 2
#define RETURN_FALSE do { return_value->type = IS_BOOL; return_value->value.lval = 0; return; } while (0)
#define RETURN_TRUE do { return_value->type = IS_BOOL; return_value->value.lval = 1; return; } while (0)
#define Z_ARRVAL_P(zval) ((zval)->value.ht)
#define Z_LVAL_PP(zval) (*(zval))->value.lval
#define ZEND_FETCH_RESOURCE(rsrc, rsrc_type, passed_id, default_id, resource_type_name, resource_type) \
    rsrc = (rsrc_type) (passed_id ? (*passed_id)->value.lval : default_id)
#define le_gd 0
#define safe_emalloc(n, size, offset) malloc((n)*(size)+(offset))
#define efree(ptr) free(ptr)
#define SEPARATE_ZVAL(ppzv)
#define convert_to_long(zval) (zval)->type = IS_LONG

typedef struct _zval {
    int type;
    union {
        long lval;
        void *ht;
    } value;
} zval;

void php_error_docref(const char *docref, int type, const char *format, ...);
int zend_hash_num_elements(void *ht);
int zend_hash_index_find(void *ht, unsigned long idx, void **pData);
int zend_parse_parameters(int num_args, const char *type_spec, ...);
void gdImageFilledPolygon(gdImagePtr im, gdPointPtr points, int npoints, int col);
void gdImagePolygon(gdImagePtr im, gdPointPtr points, int npoints, int col);