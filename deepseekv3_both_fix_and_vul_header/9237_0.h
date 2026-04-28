#include <string.h>

#define MAXPATHLEN 4096
#define TSRMLS_DC
#define PHAR_G(v) (phar_globals.v)
#define IS_DIRECTORY_UP(tok, len) ((len) == 2 && (tok)[0] == '.' && (tok)[1] == '.')
#define IS_DIRECTORY_CURRENT(tok, len) ((len) == 1 && (tok)[0] == '.')
#define IS_BACKSLASH(c) ((c) == '/')

struct _phar_globals {
    char *cwd;
    int cwd_len;
} phar_globals;

void *efree(void *ptr);
char *estrndup(const char *s, size_t n);