#include <stddef.h>

#define TRUE 1
#define FALSE 0

typedef long linenr_T;

typedef struct cursor_S {
    linenr_T lnum;
} cursor_T;

typedef struct {
    linenr_T lnum;
#ifdef FEAT_DIFF
    int fill;
#endif
    int height;
} lineoff_T;

typedef struct memline {
    long ml_line_count;
} memline_T;

typedef struct buf_S {
    memline_T b_ml;
} buf_T;

typedef struct window_S {
    int w_height;
    linenr_T w_topline;
    linenr_T w_botline;
    int w_valid;
    int w_scbind_pos;
    cursor_T w_cursor;
    int w_p_so;
#ifdef FEAT_DIFF
    int w_topfill;
    int w_filler_rows;
#endif
    int w_empty_rows;
    int w_skipcol;
} win_T;

extern win_T *curwin;
extern buf_T *curbuf;
extern int p_so;
extern int mouse_dragging;
extern int dollar_vcol;

#define VALID_TOPLINE (1 << 0)
#define VALID_BOTLINE (1 << 1)
#define VALID_BOTLINE_AP (1 << 2)
#define NOT_VALID 0
#define VALID 1

void check_cursor_lnum(void);
void check_cursor_moved(win_T *win);
int screen_valid(int);
int BUFEMPTY(void);
void redraw_later(int);
int check_top_offset(void);
int diff_check_fill(win_T *win, linenr_T lnum);
int hasAnyFolding(win_T *win);
int hasFolding(linenr_T lnum, linenr_T *firstp, linenr_T *lastp);
void scroll_cursor_halfway(int);
void scroll_cursor_top(int, int);
void scroll_cursor_bot(int, int);
void validate_botline(void);
void botline_forw(lineoff_T *lp);
void validate_cursor(void);
int scrolljump_value(void);