#include <stdint.h>
#include <stddef.h>

typedef union _zend_value {
    int64_t lval;
    double dval;
    void *ptr;
    struct {
        uint32_t w1;
        uint32_t w2;
    } ww;
} zend_value;

struct _zval_struct {
    zend_value value;
    uint32_t type_info;
};

typedef struct _zval_struct zval;

struct _zend_string {
    uint32_t gc;
    uint32_t h;
    size_t len;
    char val[1];
};

typedef struct _zend_string zend_string;

struct _zend_resource {
    int32_t refcount;
    int32_t handle;
    int32_t type;
    void *ptr;
};

typedef struct _zend_resource zend_resource;

typedef struct _Bucket {
    zval val;
    uint32_t h;
    uint32_t key;
} Bucket;

typedef struct _HashTable {
    uint32_t nTableSize;
    uint32_t nTableMask;
    uint32_t nNumUsed;
    uint32_t nNumOfElements;
    uint32_t nNextFreeElement;
    Bucket *arData;
    uint32_t *arHash;
} HashTable;

typedef struct _spl_array_object {
    HashTable *ht;
    int nApplyCount;
} spl_array_object;

typedef int64_t zend_long;

enum {
    IS_UNDEF = 0,
    IS_NULL = 1,
    IS_FALSE = 2,
    IS_TRUE = 3,
    IS_LONG = 4,
    IS_DOUBLE = 5,
    IS_STRING = 6,
    IS_ARRAY = 7,
    IS_OBJECT = 8,
    IS_RESOURCE = 9,
    IS_REFERENCE = 10,
    IS_INDIRECT = 11
};

enum {
    BP_VAR_R = 0,
    BP_VAR_W = 1,
    BP_VAR_RW = 2,
    BP_VAR_UNSET = 3,
    BP_VAR_IS = 4
};

enum {
    E_ERROR = 1,
    E_WARNING = 2,
    E_NOTICE = 8
};

#define Z_ISUNDEF_P(pz) ((pz)->type_info == IS_UNDEF)
#define Z_TYPE_P(pz) ((pz)->type_info)
#define Z_STR_P(pz) ((zend_string*)(pz)->value.ptr)
#define Z_RES_P(pz) ((zend_resource*)(pz)->value.ptr)
#define Z_DVAL_P(pz) ((pz)->value.dval)
#define Z_LVAL_P(pz) ((pz)->value.lval)
#define Z_INDIRECT_P(pz) ((zval*)(pz)->value.ptr)
#define ZVAL_NULL(pz) do { (pz)->type_info = IS_NULL; } while (0)
#define ZVAL_UNDEF(pz) do { (pz)->type_info = IS_UNDEF; } while (0)
#define ZVAL_DEREF(pz) do { (pz) = Z_INDIRECT_P(pz); } while (0)
#define ZSTR_EMPTY_ALLOC() ((zend_string*)1)
#define ZSTR_VAL(s) ((s)->val)

static zval global_uninitialized_zval = {{0}, IS_UNDEF};
static zval global_error_zval = {{0}, IS_NULL};
#define EG(v) global_##v

static HashTable* spl_array_get_hash_table(spl_array_object* intern) { return intern->ht; }
static void zend_error(int level, const char *format, ...) {}
static zval* zend_symtable_find(HashTable *ht, zend_string *key) { return NULL; }
static zval* zend_symtable_update(HashTable *ht, zend_string *key, zval *value) { return NULL; }
static zval* zend_hash_index_find(HashTable *ht, zend_long index) { return NULL; }
static zval* zend_hash_index_update(HashTable *ht, zend_long index, zval *value) { return NULL; }