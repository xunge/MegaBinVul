#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct parser_context parser_context_t;
typedef struct scanner_location scanner_location_t;
typedef struct scanner_location_info scanner_location_info_t;
typedef struct scanner_info scanner_info_t;
typedef struct scanner_for_info scanner_for_info_t;

typedef enum {
    LEXER_KEYW_FOR,
    LEXER_KEYW_AWAIT,
    LEXER_KEYW_VAR,
    LEXER_KEYW_LET,
    LEXER_KEYW_CONST,
    LEXER_LEFT_PAREN,
    LEXER_RIGHT_PAREN,
    LEXER_SEMICOLON,
    LEXER_LITERAL,
    LEXER_LEFT_SQUARE,
    LEXER_LEFT_BRACE,
    LEXER_ASSIGN,
    LEXER_EOS
} lexer_token_type_t;

typedef enum {
    SCANNER_TYPE_FOR_IN,
    SCANNER_TYPE_FOR_OF,
    SCANNER_TYPE_BLOCK,
    SCANNER_TYPE_LET_EXPRESSION,
    SCANNER_TYPE_INITIALIZER,
    SCANNER_TYPE_LITERAL_FLAGS,
    SCANNER_TYPE_FOR
} scanner_type_t;

typedef enum {
    PARSER_ERR_INVALID_KEYWORD,
    PARSER_ERR_FOR_AWAIT_NO_ASYNC,
    PARSER_ERR_LEFT_PAREN_EXPECTED,
    PARSER_ERR_FOR_AWAIT_NO_OF,
    PARSER_ERR_RIGHT_PAREN_EXPECTED,
    PARSER_ERR_LEXICAL_LET_BINDING,
    PARSER_ERR_FOR_IN_OF_DECLARATION,
    PARSER_ERR_IN_EXPECTED,
    PARSER_ERR_OF_EXPECTED,
    PARSER_ERR_SEMICOLON_EXPECTED
} parser_error_t;

typedef enum {
    CBC_EXT_FOR_IN_INIT,
    CBC_EXT_FOR_AWAIT_OF_INIT,
    CBC_EXT_FOR_OF_INIT,
    CBC_EXT_CLONE_CONTEXT,
    CBC_EXT_FOR_IN_GET_NEXT,
    CBC_EXT_FOR_OF_GET_NEXT,
    CBC_JUMP_FORWARD,
    CBC_POP,
    CBC_ASSIGN_LET_CONST,
    CBC_ASSIGN_SET_IDENT,
    CBC_PUSH_TWO_LITERALS,
    CBC_PUSH_THREE_LITERALS,
    PARSER_CBC_UNAVAILABLE
} cbc_ext_opcode_t;

typedef enum {
    PARSE_EXPR,
    PARSE_EXPR_LEFT_HAND_SIDE,
    PARSE_EXPR_NO_COMMA
} parse_expr_options_t;

typedef enum {
    PARSER_STATEMENT_FOR_IN,
    PARSER_STATEMENT_FOR_AWAIT_OF,
    PARSER_STATEMENT_FOR_OF,
    PARSER_STATEMENT_FOR
} parser_statement_type_t;

typedef struct {
    uint8_t type;
    uint8_t keyword_type;
    struct {
        uint8_t type;
        uint8_t status_flags;
    } lit_location;
    uint8_t line;
    uint8_t column;
} lexer_token_t;

typedef struct scanner_location {
    uint8_t *source_p;
} scanner_location_t;

typedef struct scanner_location_info {
    uint8_t *source_p;
    uint8_t type;
    scanner_location_t location;
} scanner_location_info_t;

typedef struct scanner_info {
    uint8_t *source_p;
    uint8_t type;
    uint8_t u8_arg;
    scanner_location_t location;
    scanner_location_t end_location;
    scanner_location_t expression_location;
} scanner_info_t;

typedef struct scanner_for_info {
    uint8_t *source_p;
    uint8_t type;
    scanner_location_t end_location;
    scanner_location_t expression_location;
} scanner_for_info_t;

typedef struct parser_context {
    uint8_t *source_p;
    uint8_t *source_end_p;
    lexer_token_t token;
    struct {
        uint16_t index;
    } lit_object;
    uint16_t context_stack_depth;
    uint16_t byte_code_size;
    uint8_t last_cbc_opcode;
    uint8_t status_flags;
    uint8_t global_status_flags;
    uint8_t line;
    uint8_t column;
    scanner_info_t *next_scanner_info_p;
    void *last_statement;
} parser_context_t;

typedef struct {
    uint16_t branch;
    uint16_t start_offset;
} parser_for_in_of_statement_t;

typedef struct {
    uint16_t branch;
    uint16_t start_offset;
    scanner_location_t condition_location;
    scanner_location_t expression_location;
} parser_for_statement_t;

typedef struct {
    void *branch_list_p;
} parser_loop_statement_t;

typedef struct {
    uint16_t branch;
} parser_branch_t;

typedef uint32_t parser_pattern_flags_t;

#define JERRY_ESNEXT 1
#define JERRY_NDEBUG 0
#define JERRY_UNLIKELY(x) (x)
#define JERRY_ASSERT(x) ((void)0)
#define LEXER_LIT_LOCATION_HAS_ESCAPE 0x01
#define LEXER_IDENT_LITERAL 0
#define SCANNER_LITERAL_DESTRUCTURING_FOR 0x01
#define SCANNER_LITERAL_OBJECT_HAS_REST 0x02
#define PARSER_PATTERN_BINDING 0x01
#define PARSER_PATTERN_TARGET_ON_STACK 0x02
#define PARSER_PATTERN_HAS_REST_ELEMENT 0x04
#define PARSER_PATTERN_LET 0x08
#define PARSER_PATTERN_CONST 0x10
#define PARSER_IS_STRICT 0x01
#define ECMA_PARSE_INTERNAL_FOR_IN_OFF_CONTEXT_ERROR 0x01
#define PARSER_FOR_IN_CONTEXT_STACK_ALLOCATION 0
#define PARSER_FOR_OF_CONTEXT_STACK_ALLOCATION 0
#define PARSER_REGISTER_START 0
#define LIT_CHAR_LEFT_SQUARE '['
#define LIT_CHAR_LEFT_BRACE '{'
#define PARSER_PLUS_EQUAL_U16(a, b) ((a) += (b))

/* Function declarations */
void lexer_next_token(parser_context_t *context_p);
void parser_raise_error(parser_context_t *context_p, parser_error_t error);
void scanner_release_next(parser_context_t *context_p, size_t size);
void scanner_get_location(scanner_location_t *location, parser_context_t *context_p);
void scanner_set_location(parser_context_t *context_p, scanner_location_t *location);
void scanner_seek(parser_context_t *context_p);
void parser_parse_expression(parser_context_t *context_p, parse_expr_options_t options);
void parser_emit_cbc_ext_forward_branch(parser_context_t *context_p, cbc_ext_opcode_t opcode, void *branch);
void parser_emit_cbc_ext(parser_context_t *context_p, cbc_ext_opcode_t opcode);
bool lexer_check_next_characters(parser_context_t *context_p, char c1, char c2);
void parser_parse_initializer_by_next_char(parser_context_t *context_p, parser_pattern_flags_t flags);
void lexer_expect_identifier(parser_context_t *context_p, uint8_t type);
void parser_emit_cbc_forward_branch(parser_context_t *context_p, cbc_ext_opcode_t opcode, parser_branch_t *branch);
void parser_parse_expression_statement(parser_context_t *context_p, parse_expr_options_t options);
void parser_set_branch_to_current_position(parser_context_t *context_p, parser_branch_t *branch);
void parser_emit_cbc_literal(parser_context_t *context_p, uint16_t opcode, uint16_t literal_index);
void parser_parse_initializer(parser_context_t *context_p, parser_pattern_flags_t flags);
void parser_emit_cbc(parser_context_t *context_p, cbc_ext_opcode_t opcode);
uint16_t parser_check_left_hand_side_expression(parser_context_t *context_p, uint16_t opcode);
void parser_flush_cbc(parser_context_t *context_p);
void parser_stack_push(parser_context_t *context_p, void *data, size_t size);
void parser_stack_push_uint8(parser_context_t *context_p, uint8_t value);
void parser_stack_iterator_init(parser_context_t *context_p, void *iterator);
void parser_parse_var_statement(parser_context_t *context_p);
bool parser_push_block_context(parser_context_t *context_p, bool flag);
bool lexer_token_is_let(parser_context_t *context_p);