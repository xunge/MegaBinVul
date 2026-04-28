#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define PARSE_EXPR_LEFT_HAND_SIDE 0
#define PARSE_EXPR_HAS_LITERAL 0
#define PARSE_EXPR_NO_COMMA 0
#define PARSE_EXPR_NO_PUSH_RESULT 0
#define PARSER_GROUPING_LEVEL_INCREASE 0
#define PARSER_RIGHT_TO_LEFT_ORDER_EXPONENTIATION 0
#define PARSER_RIGHT_TO_LEFT_ORDER_MAX_PRECEDENCE 0
#define PARSER_RIGHT_TO_LEFT_ORDER_TERNARY_PRECEDENCE 0
#define PARSER_ERR_RIGHT_PAREN_EXPECTED 0
#define JERRY_ES2015 0

#define JERRY_ASSERT(expr) ((void)0)
#define JERRY_LIKELY(expr) (expr)
#define JERRY_UNLIKELY(expr) (expr)
#define ENABLED(x) (x)

enum {
    LEXER_EXPRESSION_START,
    LEXER_LEFT_PAREN,
    LEXER_COMMA_SEP_LIST,
    LEXER_RIGHT_PAREN,
    LEXER_QUESTION_MARK,
    LEXER_COMMA,
    LEXER_FIRST_BINARY_OP,
    CBC_PUSH_LITERAL
};

typedef struct {
    int type;
} lexer_token_t;

typedef struct parser_context_t {
    lexer_token_t token;
    uint8_t stack_top_uint8;
    uint8_t last_cbc_opcode;
} parser_context_t;

extern uint8_t parser_binary_precedence_table[];

void parser_stack_push_uint8(parser_context_t *context_p, uint8_t value);
void parser_process_binary_opcodes(parser_context_t *context_p, uint8_t min_prec_treshold);
bool parser_parse_unary_expression(parser_context_t *context_p, size_t *grouping_level);
void parser_process_unary_expression(parser_context_t *context_p, size_t grouping_level);
bool parser_process_group_expression(parser_context_t *context_p, size_t *grouping_level);
bool parser_process_ternary_expression(parser_context_t *context_p, size_t grouping_level);
void parser_process_expression_sequence(parser_context_t *context_p);
void parser_append_binary_token(parser_context_t *context_p);
void lexer_next_token(parser_context_t *context_p);
void parser_raise_error(parser_context_t *context_p, int error_code);
void parser_stack_pop_uint8(parser_context_t *context_p);
void parser_push_result(parser_context_t *context_p);

#define LEXER_IS_BINARY_OP_TOKEN(type) ((type) >= LEXER_FIRST_BINARY_OP)