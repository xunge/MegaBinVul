#include <stddef.h>

typedef unsigned char char_u;

typedef struct {
    char_u *nextcmd;
} exarg_T;

typedef struct {
    int eval_flags;
} evalarg_T;

typedef struct {
    int dummy; // Placeholder for typval_T
} typval_T;

extern int did_emsg;
extern int called_emsg;
extern int in_vim9script(void);
extern int eval1(char_u **, typval_T *, evalarg_T *);
extern char_u *skipwhite(char_u *);
extern char_u *vim_strchr(char_u *, int);
extern void clear_tv(typval_T *);
extern int aborting(void);
extern int vim9_bad_comment(char_u *);
extern void semsg(const char *, ...);
extern char_u *check_nextcmd(char_u *);
extern void set_nextcmd(exarg_T *, char_u *);
extern int ends_excmd2(char_u *, char_u *);

#define FALSE 0
#define TRUE 1
#define FAIL (-1)
#define NUL '\0'
#define NL '\n'
#define _(x) x
#define e_trailing_characters_str ""
#define e_invalid_expression_str ""
#define EVAL_CONSTANT (1 << 0)