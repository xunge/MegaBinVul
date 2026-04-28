#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAXPATHLEN 4096
#define DEFAULT_SLASH '/'
#define ZTS 1
#define PHP_WIN32
#define IS_ABSOLUTE_PATH(p, l) (*(p) == '/' || (l) > 1 && (p)[1] == ':')
#define IS_SLASH(c) ((c) == '/' || (c) == '\\')
#define S_IFMT 0170000
#define S_IFDIR 0040000
#define VCWD_GETCWD(b, s) getcwd(b, s)
#define VCWD_STAT(p, s) stat(p, s)
#define ZIP_OPENBASEDIR_CHECKPATH(p) 0
#define TSRMLS_DC
#define TSRMLS_CC
#define E_WARNING 2

typedef struct _zval {
    int type;
    void *value;
} zval;

typedef struct pcre pcre;
typedef struct pcre_extra pcre_extra;

void array_init(zval *zv);
void php_error_docref(void *ref, int type, const char *format, ...);
void add_next_index_string(zval *zv, const char *str, int dup);
void *efree(void *ptr);
int php_stream_scandir(const char *dir, char ***namelist, void *filter, void *compar);
int php_stream_dirent_alphasort(const void *a, const void *b);
pcre *pcre_get_compiled_regex(char *regex, pcre_extra **extra, int *options TSRMLS_DC);
int pcre_exec(const pcre *code, const pcre_extra *extra, const char *subject, int length, int startoffset, int options, int *ovector, int ovecsize);