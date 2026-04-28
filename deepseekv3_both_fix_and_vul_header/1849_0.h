#include <string.h>
#include <stdlib.h>

struct Duration {
    static Duration Millis(int);
};

const char *QueryTerminal(const char *query, char *buffer, size_t size, Duration timeout, const char *(*callback)(const char *, size_t));