#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_parser_s njs_parser_t;
typedef struct njs_lexer_s njs_lexer_t;
typedef struct njs_str_s njs_str_t;
typedef struct njs_regexp_pattern_s njs_regexp_pattern_t;

typedef int32_t njs_token_t;
typedef int32_t njs_regexp_flags_t;

enum {
    NJS_TOKEN_ILLEGAL,
    NJS_TOKEN_REGEXP
};

struct njs_str_s {
    u_char  *start;
    size_t  length;
};

struct njs_lexer_s {
    u_char  *start;
    u_char  *end;
};

struct njs_parser_s {
    njs_lexer_t *lexer;
};

typedef union {
    struct {
        njs_regexp_pattern_t *data;
    } u;
} njs_value_data_t;

typedef struct {
    njs_value_data_t data;
} njs_value_t;

njs_regexp_flags_t njs_regexp_flags(u_char **p, u_char *end, int dummy);
int njs_slow_path(int condition);
void njs_parser_syntax_error(njs_vm_t *vm, njs_parser_t *parser, const char *fmt, ...);
njs_regexp_pattern_t *njs_regexp_pattern_create(njs_vm_t *vm, u_char *start, size_t length, njs_regexp_flags_t flags);