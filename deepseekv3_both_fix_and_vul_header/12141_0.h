#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint64_t flags;
} mcp_meta_t;

typedef struct {
    const char *request;
    int *tokens;
    int ntokens;
    int endlen;
    int reqlen;
    bool noreply;
    struct {
        mcp_meta_t meta;
    } t;
} mcp_parser_t;

#define P_DEBUG(fmt, ...)