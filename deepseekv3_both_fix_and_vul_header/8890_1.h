#include <stddef.h>

#define PARSE_SCHEME 0

struct parse_state {
    const char *ptr;
    const char *end;
    struct {
        const char *scheme;
    } url;
    char *buffer;
    size_t offset;
};

size_t parse_mb(struct parse_state *state, int type, const char *ptr, const char *end, const char *tmp, int flag);