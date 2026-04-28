#include <stddef.h>
#include <limits.h>

typedef unsigned int linenr_T;
typedef int colnr_T;
typedef int bool;
#define FALSE 0
#define TRUE 1
#define MAXCOL INT_MAX
#define Ctrl_V 22

typedef struct {
    linenr_T lnum;
    colnr_T col;
} pos_T;

typedef struct {
    pos_T vi_start;
    pos_T vi_end;
    int vi_mode;
    colnr_T vi_curswant;
} visual_info_T;

typedef struct {
    pos_T w_cursor;
    colnr_T w_curswant;
} win_T;

typedef struct {
    visual_info_T b_visual;
} buf_T;

typedef struct {
    char *input;
    char *line;
    linenr_T lnum;
    linenr_T reg_firstlnum;
    buf_T *reg_buf;
    win_T *reg_win;
} regexec_T;

extern regexec_T rex;
extern buf_T *curbuf;
extern win_T *curwin;
extern pos_T VIsual;
extern bool VIsual_active;
extern int VIsual_mode;
extern char *p_sel;

bool LT_POS(pos_T a, pos_T b);
void getvvcol(win_T *wp, pos_T *pos, colnr_T *start, colnr_T *cols, colnr_T *end);
int win_linetabsize(win_T *wp, char *line, colnr_T col);