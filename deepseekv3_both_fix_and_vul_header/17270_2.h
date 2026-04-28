#include <stdbool.h>
#include <stdint.h>

typedef uint16_t ecma_char_t;
typedef uintptr_t ecma_value_t;

typedef enum {
    RE_TOK_START_CHAR_CLASS,
    RE_TOK_START_INV_CHAR_CLASS
} re_token_type_t;

typedef struct re_token_t {
    uint32_t qmin;
    uint32_t qmax;
} re_token_t;

typedef struct re_parser_ctx_t {
    ecma_char_t *input_curr_p;
    ecma_char_t *input_end_p;
    uint32_t num_of_classes;
} re_parser_ctx_t;

typedef struct re_compiler_ctx_t {
    struct {
        re_token_type_t type;
    } current_token;
} re_compiler_ctx_t;

typedef void (*re_char_class_callback)(void*, ecma_char_t, ecma_char_t);

#define LIT_CHAR_UNDEF 0
#define LIT_CHAR_LEFT_SQUARE '['
#define LIT_CHAR_CIRCUMFLEX '^'
#define LIT_CHAR_RIGHT_SQUARE ']'
#define LIT_CHAR_MINUS '-'
#define LIT_CHAR_BACKSLASH '\\'
#define LIT_CHAR_LOWERCASE_B 'b'
#define LIT_CHAR_LOWERCASE_F 'f'
#define LIT_CHAR_LOWERCASE_N 'n'
#define LIT_CHAR_LOWERCASE_T 't'
#define LIT_CHAR_LOWERCASE_R 'r'
#define LIT_CHAR_LOWERCASE_V 'v'
#define LIT_CHAR_LOWERCASE_C 'c'
#define LIT_CHAR_LOWERCASE_X 'x'
#define LIT_CHAR_LOWERCASE_U 'u'
#define LIT_CHAR_LOWERCASE_D 'd'
#define LIT_CHAR_UPPERCASE_D 'D'
#define LIT_CHAR_LOWERCASE_S 's'
#define LIT_CHAR_UPPERCASE_S 'S'
#define LIT_CHAR_LOWERCASE_W 'w'
#define LIT_CHAR_UPPERCASE_W 'W'
#define LIT_CHAR_0 '0'
#define LIT_CHAR_9 '9'
#define LIT_CHAR_BS '\b'
#define LIT_CHAR_FF '\f'
#define LIT_CHAR_LF '\n'
#define LIT_CHAR_TAB '\t'
#define LIT_CHAR_CR '\r'
#define LIT_CHAR_VTAB '\v'
#define LIT_CHAR_SP ' '
#define LIT_CHAR_NBSP 0x00A0
#define LIT_CHAR_LS 0x2028
#define LIT_CHAR_PS 0x2029
#define LIT_CHAR_BOM 0xFEFF
#define LIT_CHAR_UNDERSCORE '_'
#define LIT_CHAR_UPPERCASE_A 'A'
#define LIT_CHAR_UPPERCASE_Z 'Z'
#define LIT_CHAR_LOWERCASE_A 'a'
#define LIT_CHAR_LOWERCASE_Z 'z'
#define LIT_UTF16_CODE_UNIT_MAX 0xFFFF
#define LIT_CHAR_ASCII_UPPERCASE_LETTERS_BEGIN 'A'
#define LIT_CHAR_ASCII_UPPERCASE_LETTERS_END 'Z'
#define LIT_CHAR_ASCII_LOWERCASE_LETTERS_BEGIN 'a'
#define LIT_CHAR_ASCII_LOWERCASE_LETTERS_END 'z'
#define LIT_CHAR_ASCII_DIGITS_BEGIN '0'
#define LIT_CHAR_ASCII_DIGITS_END '9'
#define LIT_CHAR_NULL '\0'

#define ECMA_ERR_MSG(msg) msg

ecma_value_t ecma_raise_syntax_error(const char*);
ecma_char_t lit_utf8_peek_prev(const ecma_char_t*);
void lit_utf8_decr(ecma_char_t**);
ecma_char_t lit_utf8_read_next(ecma_char_t**);
bool lit_read_code_unit_from_hex(const ecma_char_t*, int, ecma_char_t*);
ecma_char_t lit_utf8_peek_next(const ecma_char_t*);
bool lit_char_is_octal_digit(ecma_char_t);
uint32_t re_parse_octal(re_parser_ctx_t*);
ecma_value_t re_parse_iterator(re_parser_ctx_t*, re_token_t*);