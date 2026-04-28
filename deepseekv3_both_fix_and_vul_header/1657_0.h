#include <stddef.h>

typedef struct win_T win_T;
typedef int bool;

extern win_T *curwin;
extern bool p_spsc;

void changed_line_abv_curs_win(win_T *wp);
void invalidate_botline_win(win_T *wp);
void update_topline(void);
void curs_columns(bool);
void redraw_win_later(win_T *wp, int type);

#define UPD_NOT_VALID 0
#define TRUE 1

struct win_T {
    int w_width;
    int w_lines_valid;
    int w_wrow;
    int w_redr_status;
};