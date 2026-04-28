#include <stdlib.h>
#include <stddef.h>

typedef struct _zval_struct {
    int type;
} zval;

typedef struct _spl_filesystem_object {
    unsigned int flags;
    union {
        struct {
            void *stream;
            char *current_line;
            size_t current_line_len;
            zval *current_zval;
        } file;
    } u;
} spl_filesystem_object;

#define SUCCESS 0
#define TSRMLS_DC
#define TSRMLS_CC
#define SPL_HAS_FLAG(flags, flag) ((flags) & (flag))
#define SPL_FILE_OBJECT_SKIP_EMPTY (1<<0)
#define IS_NULL 0

#define ALLOC_INIT_ZVAL(z) do { (z) = malloc(sizeof(zval)); } while (0)
#define Z_TYPE_P(zval_p) ((zval_p)->type)
#define ZVAL_NULL(z) do { (z)->type = IS_NULL; } while (0)
#define ZVAL_ZVAL(z, zv, copy, dtor) do { *(z) = *(zv); } while (0)

static char *estrndup(const char *s, size_t length);
static void zval_ptr_dtor(zval **zval_ptr);
static void zval_dtor(zval *zval);
static int spl_filesystem_file_read(spl_filesystem_object *intern, int silent TSRMLS_DC);
static void php_fgetcsv(void *stream, char delimiter, char enclosure, char escape, size_t buf_len, char *buf, zval *return_value TSRMLS_DC);