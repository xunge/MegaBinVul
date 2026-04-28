#include <string.h>

typedef struct {
    const char *name;
    const char *url;
} cache_t;

extern int web_files;
extern cache_t *web_cache;