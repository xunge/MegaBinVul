#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define TSRMLS_CC
#define TSRMLS_DC
#define RETURN_FALSE do { RETVAL_FALSE; return; } while (0)
#define RETVAL_FALSE
#define ZEND_NUM_ARGS() ht
#define FAILURE -1
#define SUCCESS 0
#define E_NOTICE 0
#define E_WARNING 0
#define MAXPATHLEN 4096

struct zip {
    int dummy;
};

#define ZIP_FROM_OBJECT(intern, this) \
    do { \
        intern = (struct zip *)zend_object_store_get_object(this); \
    } while (0)

#define Z_ARRVAL_P(zval_p) ((zval_p)->value.ht)
#define Z_STRVAL_PP(zval_pp) ((*zval_pp)->value.str.val)
#define Z_STRLEN_PP(zval_pp) ((*zval_pp)->value.str.len)

typedef struct _zval_struct {
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
        void *ht;
    } value;
    unsigned char type;
} zval;

typedef struct _zend_object_value {
    void *handle;
} zend_object_value;

typedef struct _zend_object {
    zend_object_value handle;
} zend_object;

typedef struct _HashTable {
    int nTableSize;
    int nNumOfElements;
} HashTable;

static void *zend_object_store_get_object(zval *object) {
    return ((zend_object*)object)->handle.handle;
}

static void php_error_docref(const char *docref, int type, const char *format, ...) {}

static void zval_dtor(zval *zvalue) {}

static void efree(void *ptr) { free(ptr); }
static char *estrndup(const char *s, unsigned int length) { return strndup(s, length); }

static int php_zip_glob(const char *pattern, int pattern_len, long flags, zval *return_value) { return 0; }
static int php_zip_pcre(const char *pattern, int pattern_len, const char *path, int path_len, zval *return_value) { return 0; }
static int php_zip_parse_options(zval *options, long *remove_all_path, char **remove_path, int *remove_path_len, char **add_path, int *add_path_len) { return 0; }
static int php_zip_add_file(struct zip *intern, const char *file, int file_len, const char *entry_name, int entry_name_len, int start, int end) { return 0; }
static void php_basename(const char *file, int file_len, const char *suffix, int suffix_len, char **basename, size_t *basename_len) {}

static int zend_hash_index_find(HashTable *ht, unsigned long h, void **pData) { return 0; }
static int zend_parse_parameters(int num_args, const char *type_spec, ...) { return 0; }

static zval *getThis() { return NULL; }