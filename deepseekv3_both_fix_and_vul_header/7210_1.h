#include <stdlib.h>

typedef struct tabpage_S {
    char *tp_localdir;
    struct tabpage_S *tp_next;
    struct window_S *tp_firstwin;
    struct window_S *tp_lastwin;
    struct window_S *tp_curwin;
    struct frame_S *tp_topframe;
} tabpage_T;

typedef struct window_S {
    int w_winrow;
} win_T;

typedef struct frame_S frame_T;
typedef struct buf_S buf_T;

#define FAIL 1
#define OK 0
#define TRUE 1
#define FALSE 0
#define NOT_VALID 0

extern tabpage_T *curtab;
extern tabpage_T *first_tabpage;
extern tabpage_T *lastused_tabpage;
extern win_T *curwin;
extern win_T *firstwin;
extern frame_T *topframe;
extern buf_T *curbuf;

enum {
    EVENT_WINNEW,
    EVENT_WINENTER,
    EVENT_TABNEW,
    EVENT_TABENTER
};

tabpage_T *alloc_tabpage(void);
void vim_free(void *ptr);
char *vim_strsave(const char *str);
int leave_tabpage(buf_T *buf, int flag);
int win_alloc_firstwin(win_T *win);
void win_init_size(void);
int tabline_height(void);
void win_comp_scroll(win_T *win);
void last_status(int flag);
void gui_may_update_scrollbars(void);
void entering_window(win_T *win);
void redraw_all_later(int flags);
void apply_autocmds(int event, char *fname, char *fname_io, int force, buf_T *buf);
int enter_tabpage(tabpage_T *tp, buf_T *old_curbuf, int trigger_enter_autocmds, int trigger_leave_autocmds);