#include <limits.h>

#define FALSE 0
#define TRUE 1
#define MAXCOL INT_MAX

#define VALID_BOTLINE 0x01
#define VALID_BOTLINE_AP 0x02
#define VALID_WROW 0x04
#define VALID_CROW 0x08
#define VALID_TOPLINE 0x10
#define UPD_NOT_VALID 0

typedef long linenr_T;

typedef struct {
    linenr_T lnum;
    int height;
    int fill;
} lineoff_T;

typedef struct {
    linenr_T w_topline;
    int w_skipcol;
    int w_topfill;
    linenr_T w_botline;
    linenr_T w_valid;
    int w_empty_rows;
    struct {
        linenr_T lnum;
    } w_cursor;
    int w_p_wrap;
    int w_p_sms;
    int w_height;
    int w_width;
    int w_cline_height;
    int w_filler_rows;
} win_T;

typedef struct {
    struct {
        linenr_T ml_line_count;
    } b_ml;
} buf_T;

extern win_T *curwin;
extern buf_T *curbuf;
extern int mouse_dragging;

int get_scrolloff_value(void);
void topline_back_winheight(lineoff_T *lp, int add_height);
int skipcol_from_plines(win_T *wp, int plines);
void set_empty_rows(win_T *wp, int used);
void validate_botline(void);
void validate_cheight(void);
int plines_nofill(linenr_T lnum);
int plines_win(win_T *wp, linenr_T lnum, int winheight);
int plines_win_nofill(win_T *wp, linenr_T lnum, int winheight);
int curwin_col_off(void);
int curwin_col_off2(void);
int diff_check_fill(win_T *wp, linenr_T lnum);
void topline_back(lineoff_T *lp);
void botline_forw(lineoff_T *lp);
void scroll_cursor_halfway(int atend, int always);
void scrollup(long count, int upd_topline);
void reset_skipcol(void);
void redraw_later(int flags);