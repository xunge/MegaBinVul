#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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
#define PHPAPI
#define ecalloc(n, size) calloc(n, size)
#define efree(p) free(p)
#define estrndup(s, len) strndup(s, len)
#define zend_memrchr(s, c, n) memrchr(s, c, n)

static void php_replace_controlchars_ex(char *str, size_t len) {
    /* implementation not provided */
}