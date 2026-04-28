#include <stdbool.h>
#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define OK 1
#define FAIL 0

#define CMD_close 0
#define SNAP_HELP_IDX 0
#define DOBUF_UNLOAD 0
#define UPD_NOT_VALID 0
#define EVENT_BUFLEAVE 0
#define EVENT_WINLEAVE 0
#define EVENT_BUFENTER 0
#define WEE_CURWIN_INVALID 0
#define WEE_TRIGGER_ENTER_AUTOCMDS 0
#define WEE_TRIGGER_LEAVE_AUTOCMDS 0
#define WEE_ALLOW_PARSE_MESSAGES 0

typedef struct win_S {
    struct frame_S *w_frame;
    struct buf_S *w_buffer;
    int w_closing;
    int w_p_diff;
    int w_p_pvw;
    struct win_S *w_next;
} win_T;

typedef struct frame_S {
    struct frame_S *fr_parent;
} frame_T;

typedef struct tabpage_S {
} tabpage_T;

typedef struct buf_S {
    int b_locked;
} buf_T;

typedef struct {
    int in_use;
} gui_T;

extern tabpage_T *curtab;
extern win_T *curwin;
extern buf_T *curbuf;
extern win_T *firstwin;
extern win_T *lastwin;
extern bool ERROR_IF_ANY_POPUP_WINDOW;
extern int split_disallowed;
extern int p_ea;
extern char *p_ead;
extern gui_T gui;

const char *e_cannot_close_last_window;
const char *e_cannot_close_autocmd_or_popup_window;
const char *e_cannot_close_window_only_autocmd_window_would_remain;