#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct parser_context_t parser_context_t;
typedef struct lexer_token_t lexer_token_t;

struct lexer_token_t {
    int type;
};

struct parser_context_t {
    uint8_t stack_top_uint8;
    lexer_token_t token;
};

#define PARSER_GROUPING_LEVEL_INCREASE 1
#define LEXER_COMMA_SEP_LIST 0
#define LEXER_ASSIGN 0
#define LEXER_LEFT_PAREN 0
#define PARSER_PATTERN_GROUP_EXPR 0
#define JERRY_ES2015 0

#define JERRY_ASSERT(x) ((void)0)
#define JERRY_UNLIKELY(x) (x)
#define ENABLED(x) (x)

static void parser_push_result(parser_context_t *context_p);
static void parser_flush_cbc(parser_context_t *context_p);
static void parser_stack_pop_uint8(parser_context_t *context_p);
static void lexer_next_token(parser_context_t *context_p);
static void parser_append_binary_single_assignment_token(parser_context_t *context_p, uint32_t flags);