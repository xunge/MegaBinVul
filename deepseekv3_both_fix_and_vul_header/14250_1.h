#include <stddef.h>
#include <string.h>

typedef unsigned char char_u;
typedef long linenr_T;
typedef int colnr_T;

#define NUL '\0'

typedef struct {
    linenr_T lnum;
    colnr_T col;
} pos_T;

typedef struct window_S {
    pos_T w_cursor;
} win_T;

typedef struct exarg {
    char_u *arg;
    linenr_T line2;
    int cmdidx;
} exarg_T;

typedef struct regmatch {
    void *regprog;
    int rm_ic;
    char_u *startp[1];
} regmatch_T;

#define FEAT_EVAL
#define FAIL 1
#define BL_SOL 0
#define BL_FIX 0
#define RE_MAGIC 0
#define CMD_visual 0
#define e_nomatch "E486: Pattern not found"

extern win_T *curwin;
extern int p_ic;
extern int magic_isset(void);
extern int not_in_vim9(exarg_T *eap);
extern void beginline(int);
extern char_u *skip_regexp(char_u *, int, int);
extern void *vim_regcomp(char_u *, int);
extern int vim_regexec(regmatch_T *, char_u *, colnr_T);
extern void vim_regfree(void *);
extern char_u *ml_get_curline(void);
extern void emsg(const char *);
extern size_t STRLEN(const char_u *);
extern void check_cursor(void);
extern void do_exedit(exarg_T *, void *);
extern const char *_(const char *);