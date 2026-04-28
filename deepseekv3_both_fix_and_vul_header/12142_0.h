#include <stdbool.h>
#include <string.h>

#define PARSER_MAX_TOKENS 10

typedef enum {
    CMD_TYPE_GENERIC,
    CMD_TYPE_GET,
    CMD_TYPE_META
} cmd_type_t;

typedef enum {
    CMD_GET,
    CMD_SET,
    CMD_ADD,
    CMD_REPLACE,
    CMD_APPEND,
    CMD_PREPEND,
    CMD_CAS,
    CMD_GETS,
    CMD_INCR,
    CMD_DECR,
    CMD_DELETE,
    CMD_TOUCH,
    CMD_STATS,
    CMD_VERSION,
    CMD_QUIT,
    CMD_GAT,
    CMD_GATS,
    CMD_WATCH,
    CMD_MG,
    CMD_MS,
    CMD_MD,
    CMD_MN,
    CMD_MA,
    CMD_ME
} command_t;

typedef struct {
    const char *request;
    size_t reqlen;
    size_t parsed;
    size_t endlen;
    int keytoken;
    bool has_space;
    command_t command;
    cmd_type_t cmd_type;
} mcp_parser_t;

int _process_request_meta(mcp_parser_t *pr);
int _process_request_mset(mcp_parser_t *pr);
int _process_request_simple(mcp_parser_t *pr, int min_tokens, int max_tokens);
int _process_request_gat(mcp_parser_t *pr);
int _process_request_storage(mcp_parser_t *pr, int token_max);
void _process_tokenize(mcp_parser_t *pr, int token_max);