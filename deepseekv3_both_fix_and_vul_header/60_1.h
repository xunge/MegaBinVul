#include <stddef.h>

typedef long colnr_T;

typedef struct {
    colnr_T col;
    int lnum;
} pos_T;

typedef struct window_S {
    pos_T w_cursor;
} win_T;

typedef unsigned char char_u;

extern win_T *curwin;
extern char_u *p_cpo;

#define NUL '\0'
#define CPO_LISP 'l'
#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define LT_POSP(a, b) ((a)->lnum < (b)->lnum || \
                      ((a)->lnum == (b)->lnum && (a)->col < (b)->col))

char_u *vim_strchr(const char_u *str, int c);
pos_T *findmatch(pos_T *oap, int initc);
int linewhite(int lnum);
char_u *ml_get_curline(void);
int get_indent(void);
int lbr_chartabsize(char_u *line, char_u *p, colnr_T col);
int lbr_chartabsize_adv(char_u *line, char_u **pp, colnr_T col);
int lisp_match(char_u *p);