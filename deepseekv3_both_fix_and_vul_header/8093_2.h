#include <stdlib.h>
#include <string.h>

#define CWD_API
#define TSRMLS_DC
#define TSRMLS_CC

typedef struct _realpath_cache_bucket {
    unsigned long key;
    int path_len;
    char *path;
    char *realpath;
    int realpath_len;
    struct _realpath_cache_bucket *next;
} realpath_cache_bucket;

#define REALPATH_CACHE_SIZE 64
extern realpath_cache_bucket *realpath_cache[REALPATH_CACHE_SIZE];
extern unsigned long realpath_cache_size;

unsigned long realpath_cache_key(const char *path, int path_len);

#define CWDG(name) (name)