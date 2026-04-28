#include <stddef.h>

typedef unsigned char char_u;
typedef long linenr_T;

typedef struct {
    linenr_T lnum;
    int col;
} pos_T;

typedef struct window_S {
    pos_T w_cursor;
} win_T;

typedef struct oparg_S {
    pos_T start;
    int motion_type;
    int inclusive;
} oparg_T;

typedef struct buf_S {
    char_u *b_p_qe;
} buf_T;

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define LT_POS(a, b) ((a).lnum < (b).lnum || ((a).lnum == (b).lnum && (a).col < (b).col))
#define EQUAL_POS(a, b) ((a).lnum == (b).lnum && (a).col == (b).col)
#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')

extern win_T *curwin;
extern buf_T *curbuf;
extern pos_T VIsual;
extern int VIsual_active;
extern char *p_sel;
extern int VIsual_mode;
extern int redraw_cmdline;

char_u *ml_get_curline(void);
int find_next_quote(char_u *line, int start, int quotechar, char_u *escape);
int find_prev_quote(char_u *line, int start, int quotechar, char_u *escape);
void dec_cursor(void);
void dec(pos_T *pos);
int inc_cursor(void);
void redraw_curbuf_later(int flags);

#define OK 1
#define MCHAR 1
#define INVERTED 1