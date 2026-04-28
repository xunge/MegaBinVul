#include <stdint.h>
#include <stdbool.h>

typedef int ecma_value_t;
typedef uint16_t ecma_char_t;
typedef unsigned char lit_utf8_byte_t;

#define ECMA_VALUE_EMPTY 0
#define ECMA_IS_VALUE_ERROR(x) (0)
#define ECMA_ERR_MSG(x) (x)
#define LIT_CHAR_CIRCUMFLEX '^'
#define LIT_CHAR_DOLLAR_SIGN '$'
#define LIT_CHAR_VLINE '|'
#define LIT_CHAR_DOT '.'
#define LIT_CHAR_BACKSLASH '\\'
#define LIT_CHAR_0 '0'
#define LIT_CHAR_9 '9'
#define LIT_CHAR_LOWERCASE_B 'b'
#define LIT_CHAR_UPPERCASE_B 'B'
#define LIT_CHAR_LEFT_PAREN '('
#define LIT_CHAR_QUESTION '?'
#define LIT_CHAR_EQUALS '='
#define LIT_CHAR_EXCLAMATION '!'
#define LIT_CHAR_COLON ':'
#define LIT_CHAR_RIGHT_PAREN ')'
#define LIT_CHAR_LEFT_SQUARE '['
#define LIT_CHAR_ASTERISK '*'
#define LIT_CHAR_PLUS '+'
#define LIT_CHAR_LEFT_BRACE '{'
#define LIT_CHAR_RIGHT_SQUARE ']'
#define LIT_CHAR_RIGHT_BRACE '}'
#define RE_TOK_EOF 0
#define RE_TOK_ASSERT_START 1
#define RE_TOK_ASSERT_END 2
#define RE_TOK_ALTERNATIVE 3
#define RE_TOK_PERIOD 4
#define RE_TOK_BACKREFERENCE 5
#define RE_TOK_ASSERT_WORD_BOUNDARY 6
#define RE_TOK_ASSERT_NOT_WORD_BOUNDARY 7
#define RE_TOK_ASSERT_LOOKAHEAD 8
#define RE_TOK_START_NON_CAPTURE_GROUP 9
#define RE_TOK_START_CAPTURE_GROUP 10
#define RE_TOK_END_GROUP 11
#define RE_TOK_CHAR_CLASS 12
#define RE_TOK_CHAR 13
#define RE_FLAG_UNICODE (1 << 0)
#define LIT_UTF8_MAX_BYTES_IN_CODE_UNIT 3
#define ENABLED(x) (0)
#define JERRY_ES2015 0

typedef struct {
    int type;
    uint32_t value;
} re_token_t;

typedef struct {
    const lit_utf8_byte_t *input_curr_p;
    const lit_utf8_byte_t *input_end_p;
    re_token_t token;
    int groups_count;
    int flags;
} re_compiler_ctx_t;

static ecma_value_t ecma_raise_syntax_error(const char *msg);
static ecma_value_t re_parse_char_escape(re_compiler_ctx_t *re_ctx_p);
static void re_count_groups(re_compiler_ctx_t *re_ctx_p);
static ecma_value_t re_parse_quantifier(re_compiler_ctx_t *re_ctx_p);
static ecma_value_t re_check_quantifier(re_compiler_ctx_t *re_ctx_p);
static ecma_char_t lit_cesu8_read_next(const lit_utf8_byte_t **buf_p);
static ecma_char_t lit_cesu8_peek_next(const lit_utf8_byte_t *buf_p);
static uint32_t lit_parse_decimal(const lit_utf8_byte_t **buf_p, const lit_utf8_byte_t *buf_end_p);
static bool lit_is_code_point_utf16_high_surrogate(ecma_char_t ch);
static bool lit_is_code_point_utf16_low_surrogate(ecma_char_t ch);
static uint32_t lit_convert_surrogate_pair_to_code_point(ecma_char_t high, ecma_char_t low);
static bool ecma_is_value_true(ecma_value_t value);