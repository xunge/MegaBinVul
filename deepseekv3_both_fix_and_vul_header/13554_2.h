#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define MAX_EXPR_NESTING 20
#define MAKE_TOKEN(x) (x)
#define INSIDE_FSTRING_EXPR(tok) ((tok)->last_expr_end != -1)

struct tok_state {
    char *start;
    char *cur;
    int lineno;
    int col_offset;
    int first_lineno;
    int starting_col_offset;
    int decoding_erred;
    char *multi_line_start;
    char *line_start;
    int tok_mode_stack_index;
};

typedef struct tokenizer_mode {
    int kind;
    int f_string_quote_size;
    int f_string_quote;
    char *last_expr_buffer;
    int last_expr_size;
    int last_expr_end;
    char *f_string_start;
    char *f_string_multi_line_start;
    int curly_bracket_expr_start_depth;
    int f_string_raw;
} tokenizer_mode;

struct token {
    int type;
};

int tok_nextc(struct tok_state *tok);
void tok_backup(struct tok_state *tok, int c);
int syntaxerror(struct tok_state *tok, const char *msg, ...);
int warn_invalid_escape_sequence(struct tok_state *tok, int c);
int tok_get_normal_mode(struct tok_state *tok, tokenizer_mode* current_tok, struct token *token);
#define TOK_REGULAR_MODE 0
#define TOK_GET_MODE(tok) ((tokenizer_mode *)0)
#define FSTRING_END 0
#define FSTRING_MIDDLE 0
#define ERRORTOKEN 0

void *PyMem_Free(void *ptr);