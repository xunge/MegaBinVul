#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define ZEND_WRONG_PARAM_COUNT()
#define RETURN_FALSE
#define TSRMLS_CC
#define TTFTEXT_BBOX 0
#define M_PI 3.14159265358979323846
#define MAXPATHLEN PATH_MAX
#define HAVE_GD_FREETYPE
#define PHP_GD_CHECK_OPEN_BASEDIR(path, message)
#define VIRTUAL_DIR

#define FAILURE (-1)
#define SUCCESS 0
#define HASH_KEY_IS_STRING 0
#define E_WARNING 2
#define gdFTEX_LINESPACE (1<<0)

typedef struct _gdImage {
    int dummy;
} *gdImagePtr;

typedef struct _zval {
    int type;
    void *value;
} zval;

typedef struct _HashPosition {
    void *pos;
} HashPosition;

struct _gdFTStringExtra {
    int flags;
    double linespacing;
};

typedef struct _gdFTStringExtra gdFTStringExtra;

extern int le_gd;

int zend_parse_parameters(int num_args, const char *type_spec, ...);
void ZEND_FETCH_RESOURCE(gdImagePtr *im, int type, zval **IM, int id, const char *name, int le);
void zend_hash_internal_pointer_reset_ex(void *ht, HashPosition *pos);
int zend_hash_get_current_key_ex(void *ht, char **str_index, uint *str_length, ulong *num_index, int duplicate, HashPosition *pos);
int zend_hash_get_current_data_ex(void *ht, void **pData, HashPosition *pos);
void convert_to_double_ex(zval **pzval);
double Z_DVAL_PP(zval **pzval);
int zend_hash_move_forward_ex(void *ht, HashPosition *pos);
void *HASH_OF(zval *zv);
void php_error_docref(const char *docref, int type, const char *format, ...);
void array_init(zval *zv);
void add_next_index_long(zval *zv, long value);
char *gdImageStringFT(gdImagePtr im, int *brect, int fg, char *fontname, double ptsize, double angle, int x, int y, char *string);
char *gdImageStringFTEx(gdImagePtr im, int *brect, int fg, char *fontname, double ptsize, double angle, int x, int y, char *string, gdFTStringExtra *strex);

#define ZEND_FETCH_RESOURCE(rsrc, rsrc_type, passed_id, default_id, resource_type_name, resource_type) \
    ZEND_FETCH_RESOURCE(&(rsrc), 0, passed_id, default_id, resource_type_name, resource_type)

#ifdef VIRTUAL_DIR
static inline int VCWD_REALPATH(const char *path, char *resolved_path) {
    char *res = realpath(path, resolved_path);
    return res != NULL;
}
#else
static inline int VCWD_REALPATH(const char *path, char *resolved_path) {
    return 0;
}
#endif