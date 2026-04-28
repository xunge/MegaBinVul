#include <stdint.h>
#include <stddef.h>

typedef uint32_t lit_code_point_t;
typedef uint16_t ecma_char_t;
typedef int ecma_value_t;

#define JERRY_ASSERT(expr) ((void)0)
#define ENABLED(x) 0
#define JERRY_ES2015 0
#define JERRY_UNLIKELY(x) (x)
#define LIT_CHAR_0 '0'
#define LIT_UNICODE_CODE_POINT_NULL 0
#define ECMA_VALUE_EMPTY 0
#define RE_FLAG_UNICODE 0x1
#define LIT_CHAR_LOWERCASE_D 'd'
#define LIT_CHAR_UPPERCASE_D 'D'
#define LIT_CHAR_LOWERCASE_S 's'
#define LIT_CHAR_UPPERCASE_S 'S'
#define LIT_CHAR_LOWERCASE_W 'w'
#define LIT_CHAR_UPPERCASE_W 'W'
#define LIT_CHAR_LOWERCASE_F 'f'
#define LIT_CHAR_FF '\f'
#define LIT_CHAR_LOWERCASE_N 'n'
#define LIT_CHAR_LF '\n'
#define LIT_CHAR_LOWERCASE_R 'r'
#define LIT_CHAR_CR '\r'
#define LIT_CHAR_LOWERCASE_T 't'
#define LIT_CHAR_TAB '\t'
#define LIT_CHAR_LOWERCASE_V 'v'
#define LIT_CHAR_VTAB '\v'
#define LIT_CHAR_BACKSLASH '\\'
#define LIT_CHAR_LOWERCASE_C 'c'
#define LIT_CHAR_ASCII_UPPERCASE_LETTERS_BEGIN 'A'
#define LIT_CHAR_ASCII_UPPERCASE_LETTERS_END 'Z'
#define LIT_CHAR_ASCII_LOWERCASE_LETTERS_BEGIN 'a'
#define LIT_CHAR_ASCII_LOWERCASE_LETTERS_END 'z'
#define LIT_CHAR_LOWERCASE_X 'x'
#define LIT_CHAR_LOWERCASE_U 'u'
#define LIT_CHAR_LEFT_BRACE '{'
#define LIT_CHAR_RIGHT_BRACE '}'
#define LIT_CHAR_SLASH '/'
#define LIT_UNICODE_CODE_POINT_MAX 0x10FFFF

typedef struct {
    const uint8_t *input_curr_p;
    const uint8_t *input_end_p;
    struct {
        int type;
        uint32_t value;
    } token;
    int flags;
} re_compiler_ctx_t;

typedef enum {
    RE_TOK_CHAR,
    RE_TOK_CLASS_ESCAPE
} re_token_type_t;

typedef enum {
    RE_ESCAPE_DIGIT,
    RE_ESCAPE_NOT_DIGIT,
    RE_ESCAPE_WHITESPACE,
    RE_ESCAPE_NOT_WHITESPACE,
    RE_ESCAPE_WORD_CHAR,
    RE_ESCAPE_NOT_WORD_CHAR
} re_escape_type_t;

static int lit_char_is_decimal_digit(uint8_t c) { return c >= '0' && c <= '9'; }
static int lit_char_is_octal_digit(uint8_t c) { return c >= '0' && c <= '7'; }
static uint32_t re_parse_octal(re_compiler_ctx_t *re_ctx_p) { return 0; }
static lit_code_point_t lit_cesu8_read_next(const uint8_t **buf_p) { return **buf_p; }
static int lit_is_code_point_utf16_high_surrogate(uint32_t cp) { return 0; }
static int lit_is_code_point_utf16_low_surrogate(uint32_t cp) { return 0; }
static uint32_t lit_convert_surrogate_pair_to_code_point(ecma_char_t high, ecma_char_t low) { return 0; }
static int lit_char_is_hex_digit(uint8_t c) { return 0; }
static int lit_char_hex_to_int(uint8_t c) { return 0; }
static int re_is_syntax_char(uint8_t c) { return 0; }
static uint32_t lit_char_hex_lookup(const uint8_t *start_p, const uint8_t *end_p, size_t length) { return 0; }
static ecma_value_t ecma_raise_syntax_error(const char *msg) { return 0; }