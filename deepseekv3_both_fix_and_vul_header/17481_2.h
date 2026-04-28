#include <stdbool.h>
#include <stddef.h>

#define FALSE false

typedef struct window_S win_T;
typedef struct tabpage_S tabpage_T;
typedef struct cursor_S cursor_T;
typedef struct save_cursor_S save_cursor_T;
typedef struct buf_S buf_T;
typedef struct memline_S memline_T;

struct cursor_S {
    long lnum;
};

struct save_cursor_S {
    cursor_T w_cursor_save;
    long w_topline_save;
    cursor_T w_cursor_corr;
    long w_topline_corr;
};

struct memline_S {
    long ml_line_count;
};

struct buf_S {
    memline_T b_ml;
};

struct window_S {
    cursor_T w_cursor;
    long w_topline;
    buf_T *w_buffer;
    save_cursor_T w_save_cursor;
    win_T *w_next;
};

extern win_T *curwin;
extern buf_T *curbuf;
extern win_T *first_window;

void check_lnums_both(int do_curwin, bool flag);

#define FOR_ALL_TAB_WINDOWS(tp, wp) \
    for (wp = first_window; wp != NULL; wp = wp->w_next) \
        if (wp->w_buffer != NULL)