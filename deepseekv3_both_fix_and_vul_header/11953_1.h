#include <stddef.h>
#include <stdbool.h>

#define TRUE true
#define FALSE false

typedef struct frame_S frame_T;
typedef struct win_S win_T;
typedef struct buf_S buf_T;

struct frame_S {
    frame_T *fr_parent;
    frame_T *fr_child;
    frame_T *fr_next;
    frame_T *fr_prev;
    win_T   *fr_win;
};

struct win_S {
    win_T   *w_prev;
    frame_T *w_frame;
    int     w_status_height;
    int     w_vsep_width;
    buf_T   *w_buffer;
    struct {
        int line;
        int col;
    } w_cursor;
};

struct buf_S {
    // minimal definition
};

enum {
    UPD_NOT_VALID
};

extern int ERROR_IF_ANY_POPUP_WINDOW;
extern int ONE_WINDOW;
extern int FEAT_GUI;
extern bool need_mouse_correct;
extern buf_T *curbuf;
extern win_T *curwin;
extern bool VIsual_active;

void beep_flush(void);
void win_remove(win_T *win, void *unused);
void frame_remove(frame_T *frame);
void win_append(win_T *after, win_T *wp);
void frame_insert(frame_T *after, frame_T *frame);
void frame_append(frame_T *after, frame_T *frame);
void frame_fix_height(win_T *win);
void frame_fix_width(win_T *win);
int win_comp_pos(void);
void reset_VIsual_and_resel(void);
void win_enter(win_T *win, bool flag);
void redraw_all_later(int flags);