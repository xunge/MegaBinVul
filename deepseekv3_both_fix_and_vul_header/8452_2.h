#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef char XML_Char;

#define IS_NULL 0
#define IS_LONG 1
#define IS_STRING 2
#define IS_BOOL 3

typedef struct _zval {
    int type;
    union {
        long lval;
        struct {
            char *val;
            int len;
        } str;
        void *ht;
    } value;
} zval;

typedef struct _st_entry {
    int type;
    char *varname;
    zval *data;
} st_entry;

typedef struct _wddx_stack {
    char *varname;
} wddx_stack;

#define EL_PACKET "packet"
#define EL_VERSION "version"
#define EL_STRING "string"
#define EL_BINARY "binary"
#define EL_CHAR "char"
#define EL_CHAR_CODE "code"
#define EL_NUMBER "number"
#define EL_BOOLEAN "boolean"
#define EL_VALUE "value"
#define EL_NULL "null"
#define EL_ARRAY "array"
#define EL_STRUCT "struct"
#define EL_VAR "var"
#define EL_NAME "name"
#define EL_RECORDSET "recordset"
#define EL_FIELD "field"
#define EL_DATETIME "datetime"

#define ST_STRING 0
#define ST_BINARY 1
#define ST_NUMBER 2
#define ST_BOOLEAN 3
#define ST_NULL 4
#define ST_ARRAY 5
#define ST_STRUCT 6
#define ST_RECORDSET 7
#define ST_FIELD 8
#define ST_DATETIME 9

#define SET_STACK_VARNAME \
    if (stack->varname) { \
        ent.varname = estrdup(stack->varname); \
        efree(stack->varname); \
        stack->varname = NULL; \
    } else { \
        ent.varname = NULL; \
    }

#define ALLOC_ZVAL(z) z = (zval *) emalloc(sizeof(zval))
#define INIT_PZVAL(z) ZVAL_NULL(z)
#define STR_EMPTY_ALLOC() estrdup("")
#define MAKE_STD_ZVAL(z) ALLOC_ZVAL(z); INIT_PZVAL(z)
#define ZVAL_NULL(z) Z_TYPE_P(z) = IS_NULL
#define Z_TYPE_P(z) (z)->type
#define Z_STRVAL_P(z) (z)->value.str.val
#define Z_STRLEN_P(z) (z)->value.str.len
#define Z_LVAL_P(z) (z)->value.lval
#define Z_ARRVAL_P(z) (z)->value.ht

#define SUCCESS 0

void wddx_stack_push(wddx_stack *stack, st_entry *ent, size_t size);
int wddx_stack_top(wddx_stack *stack, void **entry);
void php_wddx_process_data(void *user_data, const char *data, size_t data_len);
char *estrdup(const char *s);
char *estrndup(const char *s, size_t length);
void *emalloc(size_t size);
void efree(void *ptr);
void array_init(zval *z);
void add_assoc_zval_ex(zval *arg, const char *key, size_t key_len, zval *value);
char *php_memnstr(const char *haystack, const char *needle, size_t needle_len, const char *end);
int zend_hash_find(void *ht, char *key, size_t key_len, void **result);