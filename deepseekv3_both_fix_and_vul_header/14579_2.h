#include <stdint.h>
#include <stdbool.h>

typedef uint8_t lexer_token_type_t;
typedef uint8_t scanner_type_t;
typedef uint8_t parser_error_t;
typedef uint8_t lexer_object_identifier_type_t;

typedef struct parser_context_t {
    struct {
        uint16_t index;
        struct {
            uint8_t status_flags;
        } *literal_p;
    } lit_object;
    struct {
        lexer_token_type_t type;
        uint16_t line;
        uint16_t column;
    } token;
    struct {
        void *source_p;
        scanner_type_t type;
    } *next_scanner_info_p;
    void *source_p;
    uint16_t stack_depth;
} parser_context_t;

typedef uint16_t parser_pattern_flags_t;
typedef uint16_t parser_pattern_end_marker_t;
typedef uint16_t parser_line_counter_t;
typedef uint16_t cbc_ext_opcode_t;

#define LIT_CHAR_RIGHT_BRACE '}'
#define LEXER_RIGHT_BRACE 0
#define LEXER_THREE_DOTS 1
#define LEXER_RIGHT_SQUARE 2
#define LEXER_COLON 3
#define LEXER_ASSIGN 4
#define LEXER_COMMA 5
#define PARSER_PATTERN_HAS_REST_ELEMENT (1 << 0)
#define PARSER_PATTERN_REST_ELEMENT (1 << 1)
#define PARSER_PATTERN_RHS_NO_LIT 0xFFFF
#define PARSER_PATTERN_ARGUMENTS (1 << 2)
#define CBC_EXT_REQUIRE_OBJECT_COERCIBLE 0
#define CBC_EXT_OBJ_INIT_CONTEXT_CREATE 1
#define CBC_EXT_OBJ_INIT_REST_CONTEXT_CREATE 2
#define CBC_EXT_OBJ_INIT_PUSH_REST 3
#define CBC_EXT_INITIALIZER_PUSH_PROP_LITERAL 4
#define CBC_EXT_INITIALIZER_PUSH_NAME 5
#define CBC_EXT_INITIALIZER_PUSH_PROP 6
#define CBC_EXT_INITIALIZER_PUSH_NAME_LITERAL 7
#define CBC_PUSH_LITERAL 8
#define CBC_EXT_OBJ_INIT_CONTEXT_END 9
#define PARSER_ERR_INVALID_LHS_ASSIGNMENT 0
#define PARSER_ERR_RIGHT_BRACE_EXPECTED 1
#define PARSER_ERR_VARIABLE_REDECLARED 2
#define PARSER_ERR_COLON_EXPECTED 3
#define PARSER_ERR_OBJECT_ITEM_SEPARATOR_EXPECTED 4
#define LEXER_OBJ_IDENT_OBJECT_PATTERN 0
#define LEXER_FLAG_FUNCTION_ARGUMENT (1 << 0)
#define SCANNER_TYPE_ERR_REDECLARED 0
#define PARSER_OBJ_INIT_REST_CONTEXT_STACK_ALLOCATION 0
#define PARSER_OBJ_INIT_CONTEXT_STACK_ALLOCATION 0

#define JERRY_ASSERT(x) ((void)0)
#define PARSER_MINUS_EQUAL_U16(a, b) ((a) -= (b))

parser_pattern_end_marker_t parser_pattern_get_target(parser_context_t *context_p, parser_pattern_flags_t flags);
bool lexer_check_next_character(parser_context_t *context_p, char c);
void parser_emit_cbc_ext(parser_context_t *context_p, cbc_ext_opcode_t opcode);
void lexer_consume_next_character(parser_context_t *context_p);
void parser_pattern_finalize(parser_context_t *context_p, parser_pattern_flags_t flags, parser_pattern_end_marker_t *end_pos);
void lexer_expect_object_literal_id(parser_context_t *context_p, lexer_object_identifier_type_t type);
void lexer_next_token(parser_context_t *context_p);
bool parser_pattern_process_assignment(parser_context_t *context_p, parser_pattern_flags_t flags, cbc_ext_opcode_t opcode, uint16_t rhs, lexer_token_type_t end_type);
void parser_raise_error(parser_context_t *context_p, parser_error_t error);
void parser_reparse_as_common_identifier(parser_context_t *context_p, parser_line_counter_t line, parser_line_counter_t column);
void parser_emit_cbc_literal_from_token(parser_context_t *context_p, cbc_ext_opcode_t opcode);
void parser_pattern_form_assignment(parser_context_t *context_p, parser_pattern_flags_t flags, uint16_t push_prop_opcode, uint16_t prop_index, parser_line_counter_t start_line);