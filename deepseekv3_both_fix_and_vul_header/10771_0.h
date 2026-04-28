#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct _php_url {
    char *scheme;
    char *user;
    char *pass;
    char *host;
    unsigned short port;
    char *path;
    char *query;
    char *fragment;
} php_url;

#define STR_FREE(p) free(p)
#define ecalloc(n, size) calloc(n, size)
#define efree(p) free(p)
#define estrndup(s, len) strndup(s, len)
#define PHPAPI
#define php_replace_controlchars_ex(s, len) /* no-op */

static void *zend_memrchr(const void *s, int c, size_t n);