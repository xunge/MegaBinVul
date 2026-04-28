#include <stddef.h>

#define PARSER_MAXLEN 1024
#define P_DEBUG(fmt, ...)

typedef struct {
    const char *request;
    int endlen;
    int reqlen;
    int *tokens;
    int ntokens;
} mcp_parser_t;