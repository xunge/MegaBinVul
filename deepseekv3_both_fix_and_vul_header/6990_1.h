#include <stddef.h>

typedef long linenr_T;

#define MLINE 1
#define OP_NOP 0
#define BL_SOL 0x01
#define BL_FIX 0x02

typedef struct cmdarg_T cmdarg_T;
typedef struct oparg_S oparg_S;
typedef struct window_S window_S;
typedef struct buf_T buf_T;
typedef struct ml_line_S ml_line_S;

struct cmdarg_T {
    int cmdchar;
    int count1;
    oparg_S *oap;
};

struct oparg_S {
    int op_type;
    int motion_type;
};

struct window_S {
    int w_height;
    int w_empty_rows;
    int w_topfill;
    linenr_T w_topline;
    linenr_T w_botline;
    struct {
        linenr_T lnum;
    } w_cursor;
    buf_T *w_buffer;
};

struct buf_T {
    struct {
        int ml_line_count;
    } b_ml;
};

extern window_S *curwin;
extern buf_T *curbuf;

void setpcmark(void);
void validate_botline(void);
int hasAnyFolding(window_S *win);
int hasFolding(linenr_T lnum, linenr_T *lnum1, linenr_T *lnum2);
int diff_check_fill(window_S *win, linenr_T lnum);
int plines(linenr_T lnum);
void cursor_correct(void);
void beginline(int flags);