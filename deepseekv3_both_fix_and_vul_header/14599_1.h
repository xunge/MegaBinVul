#include <stddef.h>

#define TRUE 1
#define NOT_VALID 0

typedef struct frame_T frame_T;
typedef struct win_T win_T;

struct frame_T {
    frame_T *fr_parent;
    frame_T *fr_child;
    frame_T *fr_next;
    frame_T *fr_prev;
    win_T *fr_win;
};

struct win_T {
    win_T *w_prev;
    frame_T *w_frame;
    int w_status_height;
    int w_vsep_width;
    void *w_buffer;
    void *w_cursor;
};

extern int ERROR_IF_ANY_POPUP_WINDOW;
extern int ONE_WINDOW;
extern int FEAT_GUI;
extern int need_mouse_correct;
extern void *curbuf;
extern win_T *curwin;
extern int VIsual_active;

void beep_flush(void);
void win_remove(win_T *win, void *unused);
void frame_remove(frame_T *frame);
void win_append(win_T *after, win_T *win);
void frame_insert(frame_T *after, frame_T *frame);
void frame_append(frame_T *after, frame_T *frame);
void frame_fix_height(win_T *win);
void frame_fix_width(win_T *win);
int win_comp_pos(void);
void reset_VIsual_and_resel(void);
void win_enter(win_T *win, int flag);
void redraw_all_later(int flags);