#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define FILEWBUF_POOL_ITEMS 8
#define FILEWBUF_INIT_LEN 128

struct filewbuf {
    FILE *fp;
    wchar_t *wbuf;
    size_t len;
};

static struct filewbuf fb_pool[FILEWBUF_POOL_ITEMS];
static size_t fb_pool_cur = 0;