#include <string.h>
#include <stdlib.h>

typedef struct URLContext {
    void *priv_data;
    int is_streamed;
} URLContext;

typedef struct HTTPContext {
    long long off;
    long long filesize;
    int seekable;
    int is_akamai;
} HTTPContext;