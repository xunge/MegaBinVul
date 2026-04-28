#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define UNUSED
#define TRUE 1
#define FALSE 0
#define MAXCOL 1000
#define FEAT_FOLDING
#define FEAT_DIFF
#define UPD_NOT_VALID 0

#define VALID_WROW      0x01
#define VALID_WCOL      0x02
#define VALID_CHEIGHT   0x04
#define VALID_CROW      0x08
#define VALID_VIRTCOL   0x10

typedef long linenr_T;
typedef int colnr_T;
typedef unsigned char char_u;

typedef struct window_S {
    int w_width;
    int w_height;
    linenr_T w_topline;
    linenr_T w_botline;
    int w_topfill;
    int w_skipcol;
    int w_wrow;
    int w_cline_row;
    int w_cline_height;
    int w_virtcol;
    int w_curswant;
    int w_valid;
    bool w_p_wrap;
    bool w_p_sms;
    struct cursor_S {
        linenr_T lnum;
    } w_cursor;
} win_T;

extern win_T *curwin;

int hasFolding(linenr_T lnum, linenr_T *first, linenr_T *last);
void validate_cursor(void);
void redraw_later(int flags);
int win_linetabsize(win_T *wp, linenr_T lnum, char_u *line, colnr_T len);
int plines(linenr_T lnum);
int PLINES_NOFILL(linenr_T lnum);
void invalidate_botline(void);
void validate_virtcol(void);
void validate_cheight(void);
void foldAdjustCursor(void);
void coladvance(int col);
long get_scrolloff_value(void);
int diff_check(win_T *wp, linenr_T lnum);
void check_topfill(win_T *wp, bool flag);
char_u *ml_get(linenr_T lnum);
int curwin_col_off(void);
int curwin_col_off2(void);