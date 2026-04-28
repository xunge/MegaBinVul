#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;

struct njs_parser_s;
typedef struct njs_parser_s njs_parser_t;

struct njs_parser_node_s {
    int token_line;
};
typedef struct njs_parser_node_s njs_parser_node_t;

struct njs_parser_scope_s {
    int async;
    int in_args;
};
typedef struct njs_parser_scope_s njs_parser_scope_t;

struct njs_lexer_token_s {
    int line;
};
typedef struct njs_lexer_token_s njs_lexer_token_t;

struct njs_queue_link_s;
typedef struct njs_queue_link_s njs_queue_link_t;

struct njs_parser_s {
    njs_parser_scope_t *scope;
    void *lexer;
    njs_parser_node_t *node;
};

#define NJS_ERROR (-1)
#define NJS_TOKEN_AWAIT 0
#define njs_slow_path(expr) (expr)

njs_parser_scope_t* njs_function_scope(njs_parser_scope_t* scope);
void njs_parser_syntax_error(njs_parser_t* parser, const char* msg);
njs_parser_node_t* njs_parser_node_new(njs_parser_t* parser, int token);
void njs_lexer_consume_token(void* lexer, int count);
void njs_parser_next(njs_parser_t* parser, void (*handler)(njs_parser_t*));
njs_int_t njs_parser_after(njs_parser_t* parser, njs_queue_link_t* current, njs_parser_node_t* node, int flags, void (*after)(njs_parser_t*, njs_parser_node_t*));
void njs_parser_unary_expression(njs_parser_t* parser);
void njs_parser_await_after(njs_parser_t* parser, njs_parser_node_t* node);