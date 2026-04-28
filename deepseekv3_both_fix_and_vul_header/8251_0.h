#include <string.h>

typedef struct _spl_filesystem_object {
    char *file_name;
    int file_name_len;
    char *_path;
    int _path_len;
} spl_filesystem_object;

#define IS_SLASH_AT(str, pos) ((str)[(pos)] == '/' || (str)[(pos)] == '\\')
#define PHP_WIN32
#define NETWARE
#define TSRMLS_DC

void *efree(void *ptr);
char *estrndup(const char *s, size_t len);