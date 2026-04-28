#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct parser_context_t parser_context_t;
typedef struct lexer_token_t {
    uint8_t type;
    uint8_t flags;
    uint32_t line;
    uint32_t column;
    struct {
        const uint8_t *start_p;
        const uint8_t *end_p;
    } lit_location;
} lexer_token_t;

struct parser_context_t {
    const uint8_t *source_p;
    const uint8_t *source_end_p;
    uint32_t line;
    uint32_t column;
    lexer_token_t token;
};

#define ENABLED(x) (x)
#define JERRY_ES2015 1

#define LEXER_OBJ_IDENT_CLASS_METHOD (1 << 0)
#define LEXER_OBJ_IDENT_ONLY_IDENTIFIERS (1 << 1)
#define LEXER_OBJ_IDENT_OBJECT_PATTERN (1 << 2)

#define LEXER_PARSE_NO_OPTS 0
#define LEXER_STRING_NO_OPTS 0
#define LEXER_STRING_LITERAL 0
#define LEXER_NO_SKIP_SPACES (1 << 0)

#define PARSER_ERR_PROPERTY_IDENTIFIER_EXPECTED 0
#define PARSER_ERR_RIGHT_SQUARE_EXPECTED 0
#define PARSE_EXPR_NO_COMMA 0

#define LEXER_KEYW_STATIC 0
#define LEXER_PROPERTY_GETTER 0
#define LEXER_PROPERTY_SETTER 0
#define LEXER_KEYW_ASYNC 0
#define LEXER_RIGHT_BRACE 0
#define LEXER_MULTIPLY 0
#define LEXER_RIGHT_SQUARE 0
#define LEXER_CLASS_CONSTRUCTOR 0

#define LIT_CHAR_COMMA ','
#define LIT_CHAR_RIGHT_BRACE '}'
#define LIT_CHAR_LEFT_PAREN '('
#define LIT_CHAR_COLON ':'
#define LIT_CHAR_DOUBLE_QUOTE '"'
#define LIT_CHAR_SINGLE_QUOTE '\''
#define LIT_CHAR_LEFT_SQUARE '['
#define LIT_CHAR_ASTERISK '*'
#define LIT_CHAR_DOT '.'
#define LIT_CHAR_0 '0'
#define LIT_CHAR_9 '9'

void lexer_skip_spaces(parser_context_t *context_p);
void parser_raise_error(parser_context_t *context_p, int error);
bool lexer_parse_identifier(parser_context_t *context_p, int opts);
bool lexer_compare_literal_to_string(parser_context_t *context_p, const char *str, size_t len);
void lexer_parse_string(parser_context_t *context_p, int opts);
void lexer_consume_next_character(parser_context_t *context_p);
void lexer_next_token(parser_context_t *context_p);
void parser_parse_expression(parser_context_t *context_p, int opts);
void lexer_parse_number(parser_context_t *context_p);
void lexer_construct_number_object(parser_context_t *context_p, bool arg1, bool arg2);
void lexer_construct_literal_object(parser_context_t *context_p, void *lit_location, int type);