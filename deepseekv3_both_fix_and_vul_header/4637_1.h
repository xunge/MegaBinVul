#include <glob.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define MAXPATHLEN 4096
#define GLOB_AVAILABLE_FLAGS (GLOB_MARK|GLOB_NOSORT|GLOB_NOCHECK|GLOB_NOESCAPE|GLOB_BRACE|GLOB_ONLYDIR|GLOB_ERR|GLOB_TILDE)
#define GLOB_FLAGMASK (GLOB_MARK|GLOB_NOSORT|GLOB_NOCHECK|GLOB_NOESCAPE|GLOB_BRACE|GLOB_ONLYDIR|GLOB_ERR|GLOB_TILDE)
#define E_WARNING 2
#define E_ERROR 1

typedef struct _zval_struct zval;
#define TSRMLS_DC
#define TSRMLS_CC
#define ZTS
#define HAVE_GLOB
#define IS_ABSOLUTE_PATH(p, l) (*(p) == '/')
#define DEFAULT_SLASH '/'
#define VCWD_GETCWD(b, s) getcwd(b, s)
#define VCWD_STAT(p, s) stat(p, s)
#define ZIP_OPENBASEDIR_CHECKPATH(p) (0)
#define PHP_WIN32
#define IS_SLASH(c) ((c) == '/' || (c) == '\\')

void php_error_docref(const char *docref TSRMLS_DC, int type, const char *format, ...);
void array_init(zval *array);
void add_next_index_string(zval *array, const char *str, int duplicate);