#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define NL '\n'
#define NUL '\0'

typedef struct evalarg_S evalarg_T;
typedef unsigned char char_u;

struct evalarg_S {
    void *eval_cookie;
    void *eval_cctx;
};

int in_vim9script(void);
char_u *skipwhite(char_u *p);
int vim9_comment_start(char_u *p);
int VIM_ISWHITE(char c);
char_u *newline_skip_comments(char_u *p);
char_u *getline_peek_skip_comments(evalarg_T *evalarg);
char_u *peek_next_line_from_context(void *cctx);