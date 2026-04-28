#include <stddef.h>

typedef long linenr_T;
typedef unsigned int colnr_T;
typedef int char_u;

#define FALSE 0
#define FAIL 1
#define CMOD_LOCKMARKS 0x01

struct pos {
    linenr_T lnum;
    colnr_T col;
};

struct cmdmod {
    int cmod_flags;
};

struct buf {
    struct pos b_op_start;
    struct pos b_op_end;
};

struct window {
    struct pos w_cursor;
};

extern struct cmdmod cmdmod;
extern struct buf *curbuf;
extern struct window *curwin;
extern int VIsual_active;
extern struct pos VIsual;

int u_save(linenr_T n1, linenr_T n2);
char_u *vim_strsave(char_u *str);
void vim_free(void *ptr);
char_u *ml_get(linenr_T lnum);
int ml_append(linenr_T lnum, char_u *line, colnr_T len, int newfile);
void appended_lines_mark(linenr_T lnum, linenr_T count);
void check_pos(struct buf *buf, struct pos *pos);
void msgmore(long count);