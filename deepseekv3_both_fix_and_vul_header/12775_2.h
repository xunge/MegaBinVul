#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct parser_context_t parser_context_t;
typedef struct lexer_lit_location_t lexer_lit_location_t;
typedef uint16_t prop_length_t;

#define ENABLED(x) 0
#define JERRY_BUILTIN_BIGINT 0
#define JERRY_ESNEXT 0
#define LEXER_TO_ASCII_LOWERCASE(c) ((c) | 0x20)
#define LIT_CHAR_0 '0'
#define LIT_CHAR_UNDERSCORE '_'
#define LIT_CHAR_LOWERCASE_X 'x'
#define LIT_CHAR_LOWERCASE_O 'o'
#define LIT_CHAR_7 '7'
#define LIT_CHAR_8 '8'
#define LIT_CHAR_9 '9'
#define LIT_CHAR_LOWERCASE_B 'b'
#define LIT_CHAR_DOT '.'
#define LIT_CHAR_LOWERCASE_E 'e'
#define LIT_CHAR_PLUS '+'
#define LIT_CHAR_MINUS '-'
#define LIT_CHAR_LOWERCASE_N 'n'
#define PARSER_MAXIMUM_STRING_LENGTH 0
#define PARSER_IS_STRICT 0
#define PARSER_ERR_INVALID_UNDERSCORE_IN_NUMBER 0
#define PARSER_ERR_INVALID_HEX_DIGIT 0
#define PARSER_ERR_INVALID_OCTAL_DIGIT 0
#define PARSER_ERR_OCTAL_NUMBER_NOT_ALLOWED 0
#define PARSER_ERR_INVALID_NUMBER 0
#define PARSER_ERR_INVALID_BIN_DIGIT 0
#define PARSER_ERR_MISSING_EXPONENT 0
#define PARSER_ERR_INVALID_BIGINT 0
#define PARSER_ERR_NUMBER_TOO_LONG 0
#define PARSER_ERR_IDENTIFIER_AFTER_NUMBER 0
#define LEXER_PARSE_CHECK_START_AND_RETURN 0
#define PARSER_PLUS_EQUAL_LC(a, b) ((a) += (b))

enum {
    LEXER_LITERAL,
    LEXER_NUMBER_LITERAL
};

enum {
    LEXER_NUMBER_DECIMAL,
    LEXER_NUMBER_HEXADECIMAL,
    LEXER_NUMBER_OCTAL,
    LEXER_NUMBER_BINARY,
    LEXER_NUMBER_BIGINT
};

struct lexer_lit_location_t {
    const uint8_t *char_p;
    prop_length_t length;
    uint8_t type;
    bool has_escape;
};

struct parser_context_t {
    const uint8_t *source_p;
    const uint8_t *source_end_p;
    struct {
        uint8_t type;
        uint8_t extra_value;
        lexer_lit_location_t lit_location;
    } token;
    unsigned int status_flags;
    size_t column;
};

static bool lit_char_is_hex_digit(uint8_t c) { return false; }
static bool lit_char_is_octal_digit(uint8_t c) { return false; }
static bool lit_char_is_binary_digit(uint8_t c) { return false; }
static void lexer_check_numbers(parser_context_t *context_p, const uint8_t **source_p, const uint8_t *source_end_p, uint8_t max_char, bool allow_underscore) {}
static bool lexer_parse_identifier(parser_context_t *context_p, int flags) { return false; }
static void parser_raise_error(parser_context_t *context_p, int error_code) {}