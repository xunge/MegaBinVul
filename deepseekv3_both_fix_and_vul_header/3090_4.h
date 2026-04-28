#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define PHPAPI
#define TSRMLS_D void
#define TSRMLS_CC
#define TSRMLS_C
#define TSRMLS_DC
#define E_WARNING 2
#define STR_EMPTY_ALLOC() ""
#define REGISTER_STRINGL_CONSTANT(name, str, len, flags) do { } while (0)

typedef uint32_t zend_uint;
typedef unsigned char zend_uchar;
typedef int zend_bool;

typedef struct _zend_object_value {
    unsigned int handle;
    const void *handlers;
} zend_object_value;

typedef union _zvalue_value {
    long lval;
    double dval;
    struct {
        char *val;
        int len;
    } str;
    void *ht;
    zend_object_value obj;
} zvalue_value;

typedef struct _zval_struct {
    zvalue_value value;
    zend_uint refcount__gc;
    zend_uchar type;
    zend_uchar is_ref__gc;
} zval;

typedef struct _Bucket {
    unsigned long h;
    unsigned int nKeyLength;
    void *pData;
    void *pDataPtr;
    struct _Bucket *pListNext;
    struct _Bucket *pListLast;
    struct _Bucket *pNext;
    struct _Bucket *pLast;
    const char *arKey;
} Bucket;

typedef void (*dtor_func_t)(void *pElement);

typedef struct _HashTable {
    unsigned int nTableSize;
    unsigned int nTableMask;
    unsigned int nNumOfElements;
    unsigned long nNextFreeElement;
    Bucket *pInternalPointer;
    Bucket *pListHead;
    Bucket *pListTail;
    Bucket **arBuckets;
    dtor_func_t pDestructor;
    zend_bool persistent;
    unsigned char nApplyCount;
    zend_bool bApplyProtection;
} HashTable;

typedef struct _smart_str {
    char *c;
    size_t len;
    size_t a;
} smart_str;

struct php_session_globals_struct {
    int module_number;
    char *id;
    int use_cookies;
    int send_cookie;
    char *session_name;
    int define_sid;
    int apply_trans_sid;
};

typedef struct _zend_executor_globals {
    HashTable *zend_constants;
} zend_executor_globals;

extern struct php_session_globals_struct php_session_globals;
extern zend_executor_globals executor_globals;

#define PS(x) (php_session_globals.x)
#define EG(x) (executor_globals.x)

void php_error_docref(const char *docref, int type, const char *format, ...);
void php_session_send_cookie(void);
void zend_hash_del(HashTable *ht, const char *arKey, unsigned int nKeyLength);
void smart_str_appends(smart_str *str, const char *append);
void smart_str_appendc(smart_str *str, char c);
void smart_str_0(smart_str *str);
void php_url_scanner_reset_vars(void);
void php_url_scanner_add_var(const char *name, size_t name_len, const char *value, size_t value_len, int url_encode);