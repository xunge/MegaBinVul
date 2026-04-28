#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    LEXER_LEFT_PAREN,
    LEXER_LITERAL,
    LEXER_THREE_DOTS,
    LEXER_LEFT_SQUARE,
    LEXER_LEFT_BRACE,
    LEXER_RIGHT_PAREN
} lexer_token_type_t;

typedef enum {
    LEXER_IDENT_LITERAL
} lexer_lit_location_type_t;

typedef enum {
    LEXER_KEYW_EVAL
} lexer_keyword_type_t;

typedef enum {
    SCANNER_SCAN_BRACKET_NO_ARROW,
    SCANNER_SCAN_BRACKET_SIMPLE_ARROW,
    SCANNER_SCAN_BRACKET_ARROW_WITH_ONE_ARG
} scanner_scan_bracket_arrow_type_t;

typedef enum {
    SCAN_MODE_PRIMARY_EXPRESSION,
    SCAN_MODE_PRIMARY_EXPRESSION_END
} scanner_mode_t;

typedef enum {
    SCAN_STACK_PAREN_EXPRESSION,
    SCAN_STACK_ARROW_ARGUMENTS,
    SCAN_STACK_USE_ASYNC
} scan_stack_type_t;

typedef struct {
    uint16_t status_flags;
    const uint8_t *source_p;
} scanner_literal_pool_t;

typedef struct {
    lexer_token_type_t type;
    union {
        struct {
            lexer_lit_location_type_t type;
        } lit_location;
        lexer_keyword_type_t keyword_type;
    };
} lexer_token_t;

typedef struct {
    lexer_token_t token;
    const uint8_t *source_p;
    uint8_t stack_top_uint8;
} parser_context_t;

typedef struct {
    scanner_mode_t mode;
    scanner_literal_pool_t *active_literal_pool_p;
    const uint8_t *async_source_p;
} scanner_context_t;

#define JERRY_ESNEXT 1
#define JERRY_ASSERT(expr) ((void)0)
#define JERRY_UNLIKELY(expr) (expr)
#define LIT_CHAR_RIGHT_PAREN ')'
#define LIT_CHAR_LEFT_PAREN '('
#define SCANNER_LITERAL_POOL_CAN_EVAL (1 << 0)
#define SCANNER_LITERAL_POOL_HAS_SUPER_REFERENCE (1 << 1)
#define SCANNER_LITERAL_POOL_MAY_ASYNC_ARROW (1 << 2)

bool lexer_check_arrow(parser_context_t *context_p);
bool lexer_check_next_character(parser_context_t *context_p, char ch);
void lexer_consume_next_character(parser_context_t *context_p);
bool lexer_check_arrow_param(parser_context_t *context_p);
bool lexer_token_is_async(parser_context_t *context_p);
void lexer_next_token(parser_context_t *context_p);
void scanner_add_async_literal(parser_context_t *context_p, scanner_context_t *scanner_context_p);
void parser_stack_push_uint8(parser_context_t *context_p, uint8_t value);
void scanner_scan_simple_arrow(parser_context_t *context_p, scanner_context_t *scanner_context_p, const uint8_t *source_p);
scanner_literal_pool_t *scanner_push_literal_pool(parser_context_t *context_p, scanner_context_t *scanner_context_p, uint16_t status_flags);
void scanner_append_argument(parser_context_t *context_p, scanner_context_t *scanner_context_p);
void scanner_detect_eval_call(parser_context_t *context_p, scanner_context_t *scanner_context_p);
void scanner_check_arrow_arg(parser_context_t *context_p, scanner_context_t *scanner_context_p);
void scanner_check_async_function(parser_context_t *context_p, scanner_context_t *scanner_context_p);