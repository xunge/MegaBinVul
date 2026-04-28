#include <string.h>
#include <stdlib.h>

struct name_path {
    const char *elem;
    int elem_len;
    struct name_path *up;
};

extern void *xmalloc(size_t size);