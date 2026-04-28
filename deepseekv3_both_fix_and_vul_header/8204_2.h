#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define RETURN_FALSE return
#define RETURN_EMPTY_STRING() return
#define RETURN_NEW_STR(s) return
#define FAILURE -1
#define ZIP_FROM_OBJECT(intern, self) 
#define PHP_ZIP_STAT_PATH(intern, path, path_len, flags, sb) 
#define PHP_ZIP_STAT_INDEX(intern, index, flags, sb) 
#define ZEND_NUM_ARGS() 0
#define ZSTR_VAL(s) ((s)->val)
#define ZSTR_LEN(s) ((s)->len)

typedef int64_t zend_long;

struct _zend_string {
    char *val;
    size_t len;
};
typedef struct _zend_string zend_string;

typedef struct _zval {
    int type;
    zend_string *value;
} zval;

struct zip;
struct zip_stat {
    size_t size;
};
struct zip_file;

static zval* getThis(void) { return NULL; }
static int zend_parse_parameters(int num_args, const char *type_spec, ...) { return 0; }
static zend_string* zend_string_alloc(size_t len, int persistent) { 
    zend_string *s = malloc(sizeof(zend_string));
    s->val = malloc(len+1);
    s->len = len;
    return s;
}
static void zend_string_free(zend_string *s) {
    free(s->val);
    free(s);
}
static struct zip_file* zip_fopen_index(struct zip *archive, uint64_t index, int flags) { return NULL; }
static struct zip_file* zip_fopen(struct zip *archive, const char *fname, int flags) { return NULL; }
static int zip_fread(struct zip_file *file, void *buf, size_t nbytes) { return 0; }
static int zip_fclose(struct zip_file *file) { return 0; }