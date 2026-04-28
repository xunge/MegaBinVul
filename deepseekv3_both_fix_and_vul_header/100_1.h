#include <stdbool.h>
#include <stddef.h>

typedef struct win_S win_T;
typedef struct frame_S frame_T;
typedef struct tabpage_S tabpage_T;
typedef struct buf_S buf_S;
typedef unsigned char char_u;

#define FALSE 0
#define TRUE 1
#define OK 1
#define FAIL 0
#define DOBUF_UNLOAD 0
#define NOT_VALID 0
#define SNAP_HELP_IDX 0

#define WEE_CURWIN_INVALID 0
#define WEE_TRIGGER_ENTER_AUTOCMDS 0
#define WEE_TRIGGER_LEAVE_AUTOCMDS 0
#define WEE_ALLOW_PARSE_MESSAGES 0

#define EVENT_BUFLEAVE 0
#define EVENT_WINLEAVE 0
#define EVENT_BUFENTER 0

#define e_cannot_close_last_window "E444: Cannot close last window"
#define e_cannot_close_autocmd_or_popup_window "E814: Cannot close autocmd or popup window"
#define e_cannot_close_window_only_autocmd_window_would_remain "E813: Cannot close window, only autocmd window would remain"

struct win_S {
    struct frame_S *w_frame;
    int w_closing;
    struct buf_S *w_buffer;
    int w_p_diff;
    int w_p_pvw;
    win_T *w_next;
};

struct frame_S {
    struct frame_S *fr_parent;
};

struct buf_S {
    int b_locked;
};

struct gui_S {
    int in_use;
};

extern win_T *firstwin;
extern win_T *lastwin;
extern win_T *aucmd_win;
extern win_T *curwin;
extern tabpage_T *curtab;
extern buf_S *curbuf;
extern int split_disallowed;
extern int dont_parse_messages;
extern char *p_ead;
extern int p_ea;
extern struct gui_S gui;
extern bool ERROR_IF_ANY_POPUP_WINDOW;

int may_close_term_popup(void);
int last_window(void);
void emsg(const char *msg);
int win_unlisted(win_T *win);
int one_window(void);
int close_last_window_tabpage(win_T *win, int free_buf, tabpage_T *prev_curtab);
int bt_help(buf_S *buf);
void clear_snapshot(tabpage_T *tab, int idx);
void leaving_window(win_T *win);
win_T *frame2win(frame_T *fr);
frame_T *win_altframe(win_T *win, void *arg);
int win_valid(win_T *win);
void apply_autocmds(int event, char *arg1, char *arg2, int force, buf_S *buf);
int aborting(void);
int popup_win_closed(win_T *win);
int win_valid_any_tab(win_T *win);
void win_close_buffer(win_T *win, int action, int abort_if_last);
int only_one_window(void);
void getout(int status);
void win_close_othertab(win_T *win, int force, tabpage_T *prev_curtab);
win_T *win_free_mem(win_T *win, int *dir, void *arg);
win_T *get_snapshot_curwin(int idx);
int bt_quickfix(buf_S *buf);
void check_cursor(void);
void win_equal(win_T *win, int equalize, int dir);
void win_comp_pos(void);
int win_enter_ext(win_T *win, int flags);
void last_status(int show);
void restore_snapshot(int idx, int close_win);
int diffopt_closeoff(void);
void do_cmdline_cmd(char *cmd);
int win_hasvertsplit(void);
void gui_init_which_components(void *arg);
void redraw_all_later(int flags);
void out_flush(void);
void trigger_winclosed(win_T *win);