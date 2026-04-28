#include <limits.h>

#define FALSE 0
#define TRUE 1
#define MAXCOL INT_MAX

#define VALID_TOPLINE   0x0001
#define VALID_BOTLINE   0x0002
#define VALID_BOTLINE_AP 0x0004
#define VALID_WROW      0x0008
#define VALID_CROW      0x0010

#define UPD_NOT_VALID   1

typedef long linenr_T;

typedef struct {
    linenr_T lnum;
    int height;
#ifdef FEAT_DIFF
    int fill;
#endif
} lineoff_T;

typedef struct memline {
    linenr_T ml_line_count;
} memline_T;

typedef struct buf {
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
    struct cursor_pos {
        linenr_T lnum;
    } w_cursor;
    int w_cline_height;
    int w_filler_rows;
#ifdef FEAT_DIFF
    int w_topfill;
#endif
} win_T;

extern win_T *curwin;
extern buf_T *curbuf;
extern int mouse_dragging;

int get_scrolloff_value(void);
void topline_back_winheight(lineoff_T *lp, int add);
int skipcol_from_plines(win_T *wp, int plines);
void set_empty_rows(win_T *wp, int used);
void redraw_later(int type);
void reset_skipcol(void);
void validate_botline(void);
int plines_nofill(linenr_T lnum);
void validate_cheight(void);
int plines_win(win_T *wp, linenr_T lnum, int winheight);
int plines_win_nofill(win_T *wp, linenr_T lnum, int winheight);
int curwin_col_off(void);
int curwin_col_off2(void);
#ifdef FEAT_FOLDING
int hasFolding(linenr_T lnum, linenr_T *lp, linenr_T *rp);
#endif
#ifdef FEAT_DIFF
int diff_check_fill(win_T *wp, linenr_T lnum);
#endif
void topline_back(lineoff_T *lp);
void botline_forw(lineoff_T *lp);
void scroll_cursor_halfway(int atend, int always);
void scrollup(long count, int upd_topline);
void update_screen(void);