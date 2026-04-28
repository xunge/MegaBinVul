#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _realpath_cache_bucket {
    unsigned long key;
    time_t expires;
    char *path;
    int path_len;
    char *realpath;
    int realpath_len;
    struct _realpath_cache_bucket *next;
} realpath_cache_bucket;

#define REALPATH_CACHE_SIZE 16
extern realpath_cache_bucket *realpath_cache[REALPATH_CACHE_SIZE];
extern unsigned int realpath_cache_ttl;
extern size_t realpath_cache_size;
extern unsigned long realpath_cache_key(const char *path, int path_len);

#define CWDG(name) (name)
#define TSRMLS_DC
#define TSRMLS_CC
#define PHP_WIN32