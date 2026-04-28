#include <string.h>

typedef struct {
    const char *request;
    int parsed;
    int endlen;
    int reqlen;
    size_t klen;
} mcp_parser_t;