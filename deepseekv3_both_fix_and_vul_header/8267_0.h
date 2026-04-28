#include <stddef.h>

typedef struct _zval_struct zval;
typedef struct _zend_hash zend_hash;
typedef struct _Bucket Bucket;

typedef union _zvalue_value {
    long lval;
    double dval;
    struct {
        char *val;
        int len;
    } str;
    zend_hash *ht;
    struct {
        zend_hash *objhandlers;
        zend_hash *properties;
    } obj;
} zvalue_value;

struct _zval_struct {
    zvalue_value value;
    unsigned char type;
    unsigned char is_ref;
    unsigned char refcount;
};

struct _Bucket {
    void *pData;
    Bucket *pListNext;
    Bucket *pListLast;
};

struct _zend_hash {
    Bucket *pListHead;
    Bucket *pListTail;
    int nNumOfElements;
};

#define Z_TYPE_P(zval_p) (zval_p)->type
#define Z_STRLEN_P(zval_p) (zval_p)->value.str.len
#define Z_ARRVAL_P(zval_p) (zval_p)->value.ht
#define Z_STRLEN_PP(zval_pp) (*zval_pp)->value.str.len
#define Z_TYPE_PP(zval_pp) (*zval_pp)->type

#define IS_STRING 6
#define IS_ARRAY 7
#define IS_NULL 0

#define SPL_FILE_OBJECT_READ_CSV (1<<0)
#define SPL_HAS_FLAG(flags, flag) ((flags) & (flag))

typedef struct _spl_filesystem_object {
    union {
        struct {
            char *current_line;
            int current_line_len;
            zval *current_zval;
        } file;
    } u;
    int flags;
} spl_filesystem_object;

#define TSRMLS_DC