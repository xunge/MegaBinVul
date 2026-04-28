#include <stddef.h>
#include <string.h>

#define JUMPLISTSIZE 100
#define CMOD_KEEPJUMPS 0x01
#define TRUE 1
#define FALSE 0

typedef long linenr_T;
typedef int colnr_T;

typedef struct {
    linenr_T lnum;
    colnr_T col;
} pos_T;

typedef struct buf_S {
    pos_T b_last_change;
    pos_T b_changelist[JUMPLISTSIZE];
    int b_changelistlen;
    int b_new_change;
} buf_T;

typedef struct win_S {
    pos_T w_cursor;
    buf_T *w_buffer;
    int w_changelistidx;
    int w_redr_type;
    int w_p_diff;
    int w_p_rnu;
    int w_p_cul;
    linenr_T w_botline;
    linenr_T w_topline;
    int w_lines_valid;
    struct {
        int wl_valid;
        linenr_T wl_lnum;
        linenr_T wl_lastlnum;
    } w_lines[1];
    int w_last_cursor_lnum_rnu;
    linenr_T w_last_cursorline;
    int w_cline_folded;
    struct win_S *w_next;
} win_T;

typedef struct tabpage_S {
    struct tabpage_S *tp_next;
    win_T *tp_firstwin;
    int tp_diff_update;
} tabpage_T;

extern buf_T *curbuf;
extern win_T *curwin;
extern tabpage_T *curtab;
extern tabpage_T *first_tabpage;
extern int must_redraw;
extern int VIsual_active;
extern pos_T last_cursormoved;

struct cmdmod_T {
    int cmod_flags;
};

extern struct cmdmod_T cmdmod;

#define FOR_ALL_TAB_WINDOWS(tp, wp) \
    for (tp = first_tabpage; tp != NULL; tp = tp->tp_next) \
        for (wp = tp->tp_firstwin; wp != NULL; wp = wp->w_next)

#define mch_memmove memmove

enum {
    VALID,
    SOME_VALID
};

static void changed(void);
static int comp_textwidth(int);
static void check_visual_pos(void);
static void changed_line_abv_curs_win(win_T *wp);
static void changed_cline_bef_curs_win(win_T *wp);
static void invalidate_botline_win(win_T *wp);
static void approximate_botline_win(win_T *wp);