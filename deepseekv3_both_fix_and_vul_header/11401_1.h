#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

enum rules_token {
    TOK_END_OF_LINE,
    TOK_END_OF_FILE,
    TOK_ERROR,
    TOK_LHS_KEYSYM,
    TOK_COLON,
    TOK_BANG,
    TOK_TILDE,
    TOK_STRING,
    TOK_INCLUDE,
    TOK_IDENT
};

struct scanner {
    int line;
    int column;
    int token_line;
    int token_column;
    char *buf;
    size_t buf_pos;
};

union lvalue {
    struct {
        char *str;
        size_t len;
    } string;
};

static bool is_space(char c);
static char peek(struct scanner *s);
static char next(struct scanner *s);
static bool eof(struct scanner *s);
static bool eol(struct scanner *s);
static bool chr(struct scanner *s, char c);
static void skip_to_eol(struct scanner *s);
static bool buf_append(struct scanner *s, char c);
static void scanner_err(struct scanner *s, const char *fmt, ...);
static void scanner_warn(struct scanner *s, const char *fmt, ...);
static bool hex(struct scanner *s, uint8_t *o);
static bool oct(struct scanner *s, uint8_t *o);
static bool is_valid_utf8(const char *s, size_t len);
static bool is_alpha(char c);
static bool is_alnum(char c);
static bool streq(const char *a, const char *b);