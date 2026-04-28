#include <stdbool.h>

#define FALSE false
#define TRUE true

typedef struct window_S {
    bool w_p_wrap;
    bool w_p_sms;
    int w_width;
    int w_height;
    int w_cline_height;
    long w_skipcol;
    long w_virtcol;
    int w_topline;
    struct cursor {
        int lnum;
    } w_cursor;
} win_T;

extern win_T *curwin;

int curwin_col_off(void);
int curwin_col_off2(void);
long get_scrolloff_value(void);
void validate_cheight(void);
int plines_win(win_T *win, int lnum, bool fake);
void reset_skipcol(void);
void validate_virtcol(void);
void redraw_later(int flags);
enum { UPD_NOT_VALID };