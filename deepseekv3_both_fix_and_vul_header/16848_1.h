#include <limits.h>
#include <stddef.h>

struct ist {
    char *ptr;
    size_t len;
};

#define HTTP_IS_LWS(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')
#define unlikely(x) (x)