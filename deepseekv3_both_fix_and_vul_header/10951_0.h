#include <stddef.h>

struct string {
    char *s;
    size_t n;
};

#define LEN(a) (sizeof(a) / sizeof((a)[0]))

void fatal(const char *fmt, ...);