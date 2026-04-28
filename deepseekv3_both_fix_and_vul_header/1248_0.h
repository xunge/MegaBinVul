#include <stddef.h>

typedef char char_u;
typedef int bool;

#define TRUE 1
#define FALSE 0
#define NUL '\0'
#define NL '\n'
#define OK 1

typedef struct {
    int ga_itemsize;
    int ga_len;
    void *ga_data;
} garray_T;

typedef struct {
    garray_T eval_ga;
    void *eval_cookie;
    char_u *(*eval_getline)(int, void *, int, int);
    char_u *eval_tofree;
    int eval_break_count;
    bool eval_using_cmdline;
    void *eval_cctx;
} evalarg_T;

#define GETLINE_CONCAT_ALL 0

char_u *newline_skip_comments(char_u *arg);
char_u *skipwhite(char_u *p);
bool vim9_comment_start(char_u *p);
char_u *vim_strsave(char_u *str);
void vim_free(void *ptr);
int ga_grow(garray_T *gap, int n);
char_u *next_line_from_context(void *cctx, bool);