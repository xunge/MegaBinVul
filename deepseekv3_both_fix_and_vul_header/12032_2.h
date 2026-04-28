#include <stddef.h>

typedef struct window_S win_T;
typedef long linenr_T;
typedef struct gui_S gui_T;

struct pos_T {
    linenr_T lnum;
    int col;
};
typedef struct pos_T pos_T;

#define FEAT_DIFF
#define FALSE 0
#define TRUE 1
#define SBAR_NONE 0
#define UPD_VALID 0
#define UPD_NOT_VALID 1

extern win_T *firstwin;
extern int current_scrollbar;
extern int exmode_active;
extern int scrollbar_value;
extern win_T *curwin;
extern gui_T gui;
extern int get_scrolloff_value(void);
extern void cursor_correct(void);
extern void update_topline(void);
extern void coladvance(int);
extern void validate_cursor(void);
extern int pum_visible(void);
extern void pum_redraw(void);
extern void scrolldown(long, int);
extern void scrollup(long, int);
extern void updateWindow(win_T *);
extern void mch_disable_flush(void);
extern void mch_enable_flush(void);

#define W_NEXT(wp) ((wp)->w_next)
#define EQUAL_POS(a, b) ((a).lnum == (b).lnum && (a).col == (b).col)

struct window_S {
    win_T *w_next;
    linenr_T w_topline;
    pos_T w_cursor;
    int w_redr_type;
    int w_lines_valid;
    linenr_T w_scbind_pos;
    int w_curswant;
    int w_leftcol;
    int w_skipcol;
    void *w_buffer;
#ifdef FEAT_DIFF
    int w_topfill;
#endif
};

struct gui_S {
    win_T *dragged_wp;
    int dragged_sb;
};

extern void *curbuf;