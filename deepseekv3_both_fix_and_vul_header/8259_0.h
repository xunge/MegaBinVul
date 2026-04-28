#include <stdio.h>
#include <stdlib.h>

typedef struct _zval_struct zval;
typedef struct _spl_filesystem_object spl_filesystem_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define SUCCESS 0

#define SPL_HAS_FLAG(flags, flag) ((flags) & (flag))
#define SPL_FILE_OBJECT_SKIP_EMPTY (1 << 0)

static int spl_filesystem_file_read_line_ex(zval *this_ptr, spl_filesystem_object *intern, int silent TSRMLS_DC);
static int spl_filesystem_file_is_empty_line(spl_filesystem_object *intern TSRMLS_DC);
static void spl_filesystem_file_free_line(spl_filesystem_object *intern TSRMLS_DC);

struct _spl_filesystem_object {
    int flags;
};