#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct parser_context_t parser_context_t;
typedef struct lexer_token_t {
    uint8_t type;
    uint8_t flags;
    uint32_t keyword_type;
    uint32_t line;
    uint32_t column;
    struct {
        const uint8_t *start_p;
        size_t length;
    } lit_location;
} lexer_token_t;

struct parser_context_t {
    const uint8_t *source_p;
    const uint8_t *source_end_p;
    const uint8_t *function_start_p;
    uint32_t line;
    uint32_t column;
    lexer_token_t token;
};

#define JERRY_ASSERT(x)
#define JERRY_FUNCTION_TO_STRING 0
#define JERRY_ESNEXT 0

#define LEXER_EOS 0
#define LEXER_PROPERTY_GETTER 1
#define LEXER_PROPERTY_SETTER 2
#define LEXER_KEYW_ASYNC 3
#define LEXER_KEYW_STATIC 4
#define LEXER_RIGHT_SQUARE 5
#define LEXER_MULTIPLY 6
#define LEXER_HASHMARK 7
#define LEXER_LEFT_BRACE 8
#define LEXER_RIGHT_BRACE 9
#define LEXER_THREE_DOTS 10

#define LEXER_OBJ_IDENT_CLASS_IDENTIFIER 0x01
#define LEXER_OBJ_IDENT_CLASS_NO_STATIC 0x02
#define LEXER_OBJ_IDENT_SET_FUNCTION_START 0x04
#define LEXER_OBJ_IDENT_ONLY_IDENTIFIERS 0x08
#define LEXER_OBJ_IDENT_OBJECT_PATTERN 0x10
#define LEXER_OBJ_IDENT_CLASS_PRIVATE 0x20

#define LEXER_PARSE_NO_OPTS 0
#define LEXER_STRING_NO_OPTS 0
#define LEXER_STRING_LITERAL 0
#define LEXER_NO_SKIP_SPACES 0x01

#define PARSE_EXPR_NO_COMMA 0
#define PARSER_ERR_PROPERTY_IDENTIFIER_EXPECTED 0
#define PARSER_ERR_INVALID_CHARACTER 0
#define PARSER_ERR_RIGHT_SQUARE_EXPECTED 0

#define LIT_CHAR_COMMA ','
#define LIT_CHAR_RIGHT_BRACE '}'
#define LIT_CHAR_LEFT_PAREN '('
#define LIT_CHAR_SEMICOLON ';'
#define LIT_CHAR_EQUALS '='
#define LIT_CHAR_COLON ':'
#define LIT_CHAR_DOUBLE_QUOTE '"'
#define LIT_CHAR_SINGLE_QUOTE '\''
#define LIT_CHAR_LEFT_SQUARE '['
#define LIT_CHAR_ASTERISK '*'
#define LIT_CHAR_HASHMARK '#'
#define LIT_CHAR_LEFT_BRACE '{'
#define LIT_CHAR_RIGHT_BRACE '}'
#define LIT_CHAR_DOT '.'
#define LIT_CHAR_0 '0'
#define LIT_CHAR_9 '9'

#define PARSER_PLUS_EQUAL_LC(column, count) (column += count)

void lexer_skip_spaces(parser_context_t *context_p);
void parser_raise_error(parser_context_t *context_p, uint32_t error);
bool lexer_parse_identifier(parser_context_t *context_p, uint32_t opts);
bool lexer_compare_literal_to_string(parser_context_t *context_p, const char *str, size_t length);
void lexer_parse_string(parser_context_t *context_p, uint32_t opts);
void lexer_consume_next_character(parser_context_t *context_p);
void lexer_next_token(parser_context_t *context_p);
void parser_parse_expression(parser_context_t *context_p, uint32_t opts);
bool lit_char_is_decimal_digit(uint8_t c);
void lexer_parse_number(parser_context_t *context_p);
void lexer_construct_number_object(parser_context_t *context_p, bool arg1, bool arg2);
void parser_resolve_private_identifier(parser_context_t *context_p);
void lexer_construct_literal_object(parser_context_t *context_p, void *lit_location, uint32_t opts);