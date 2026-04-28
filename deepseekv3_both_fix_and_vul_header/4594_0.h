#include <stddef.h>
#include <string.h>

typedef struct json_t json_t;
typedef struct json_error_t json_error_t;

typedef enum {
    TOKEN_STRING,
    TOKEN_INTEGER,
    TOKEN_REAL,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_NULL,
    TOKEN_INVALID
} token_type;

typedef struct {
    char *val;
    size_t len;
} string_value;

typedef struct {
    token_type token;
    union {
        string_value string;
        long integer;
        double real;
    } value;
    size_t depth;
} lex_t;

#define JSON_PARSER_MAX_DEPTH 1000
#define JSON_ALLOW_NUL 1

json_t *jsonp_stringn_nocheck_own(const char *value, size_t len);
json_t *json_integer(long value);
json_t *json_real(double value);
json_t *json_true(void);
json_t *json_false(void);
json_t *json_null(void);
json_t *parse_object(lex_t *lex, size_t flags, json_error_t *error);
json_t *parse_array(lex_t *lex, size_t flags, json_error_t *error);
void error_set(json_error_t *error, lex_t *lex, const char *message);