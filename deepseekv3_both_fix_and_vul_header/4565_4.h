#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

typedef struct _gdImage {
    int dummy;
} *gdImagePtr;

typedef struct _zval {
    int type;
    union {
        long lval;
        double dval;
        void *ptr;
    } value;
} zval;

typedef struct _zend_resource {
    int type;
    void *ptr;
} zend_resource;

typedef unsigned long ulong;
typedef struct {
    int pos;
} HashPosition;

typedef struct {
    int flags;
    double linespacing;
} gdFTStringExtra;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define TSRMLS_CC
#define FAILURE -1
#define SUCCESS 0
#define HAVE_GD_STRINGFTEX 0
#define HAVE_GD_STRINGFT 0
#define HAVE_GD_STRINGTTF 0
#define TTFTEXT_BBOX 1
#define E_WARNING 2
#define MAXPATHLEN 4096
#define USE_GD_IMGSTRTTF 0
#define VIRTUAL_DIR 0
#define M_PI 3.14159265358979323846
#define le_gd 0
#define HASH_OF(z) NULL
#define Z_DVAL_PP(z) 0.0
#define gdFTEX_LINESPACE 1

static int zend_parse_parameters(int argc, const char *spec, ...) { return 0; }
#define ZEND_FETCH_RESOURCE(rsrc, type, id, default_id, name, le) \
    do { \
        *(gdImagePtr*)(rsrc) = NULL; \
    } while(0)
static int VCWD_REALPATH(const char *path, char *real_path) { return 0; }
static void php_error_docref(const char *ref, int type, const char *format, ...) {}
static void array_init(zval *zv) {}
static void add_next_index_long(zval *zv, long value) {}
static void convert_to_double_ex(zval **zv) {}
static int zend_hash_internal_pointer_reset_ex(void *ht, HashPosition *pos) { return 0; }
static int zend_hash_get_current_key_ex(void *ht, char **str, uint *len, ulong *num, int flag, HashPosition *pos) { return 0; }
static int zend_hash_get_current_data_ex(void *ht, void **data, HashPosition *pos) { return 0; }
static int zend_hash_move_forward_ex(void *ht, HashPosition *pos) { return 0; }
static void PHP_GD_CHECK_OPEN_BASEDIR(const char *path, const char *message) {}
#define ZEND_WRONG_PARAM_COUNT()
#define RETURN_FALSE