#include <limits.h>

#define FALSE 0
#define TRUE 1
#define MAXCOL INT_MAX

typedef long linenr_T;

typedef struct {
    linenr_T lnum;
    int fill;
    int height;
} lineoff_T;

typedef struct cursor_S {
    linenr_T lnum;
} cursor_T;

typedef struct memline {
    linenr_T ml_line_count;
} memline_T;

typedef struct buf_S {
    memline_T b_ml;
} buf_T;

typedef struct window_S {
    linenr_T w_topline;
    linenr_T w_botline;
    int w_skipcol;
    int w_empty_rows;
    int w_valid;
    int w_height;
    int w_width;
    int w_p_wrap;
    int w_p_sms;
    cursor_T w_cursor;
    int w_cline_height;
    int w_filler_rows;
    int w_topfill;
} win_T;

#define FEAT_DIFF
#define FEAT_FOLDING

#define VALID_BOTLINE 0x01
#define VALID_BOTLINE_AP 0x02
#define VALID_WROW 0x04
#define VALID_CROW 0x08
#define VALID_TOPLINE 0x10

#define UPD_NOT_VALID 1

extern win_T *curwin;
extern buf_T *curbuf;
extern int mouse_dragging;

void topline_back_winheight(lineoff_T *lp, int add_height);
void set_empty_rows(win_T *wp, int used);
void validate_botline(void);
void validate_cheight(void);
long get_scrolloff_value(void);
int curwin_col_off(void);
int curwin_col_off2(void);
int plines_nofill(linenr_T lnum);
int plines_win_nofill(win_T *wp, linenr_T lnum, int winheight);
int plines_win(win_T *wp, linenr_T lnum, int winheight);
int skipcol_from_plines(win_T *wp, int plines_offset);
void redraw_later(int type);
void reset_skipcol(void);
int hasFolding(linenr_T lnum, linenr_T *lp, linenr_T *bp);
int diff_check_fill(win_T *wp, linenr_T lnum);
void topline_back(lineoff_T *lp);
void botline_forw(lineoff_T *lp);
void scroll_cursor_halfway(int atend, int always);
void scrollup(int line_count, int do_smooth);