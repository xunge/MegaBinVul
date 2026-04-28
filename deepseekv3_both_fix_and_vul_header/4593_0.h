#include <stddef.h>

typedef struct json_t json_t;
typedef struct lex_t lex_t;
typedef struct json_error_t json_error_t;

#define JSON_DECODE_ANY 1
#define JSON_DISABLE_EOF_CHECK 2

#define TOKEN_EOF 0

struct lex_t {
    int token;
    size_t depth;
    struct {
        size_t position;
    } stream;
};

struct json_error_t {
    int position;
};

void lex_scan(lex_t *lex, json_error_t *error);
json_t *parse_value(lex_t *lex, size_t flags, json_error_t *error);
void error_set(json_error_t *error, lex_t *lex, const char *message);
void json_decref(json_t *json);