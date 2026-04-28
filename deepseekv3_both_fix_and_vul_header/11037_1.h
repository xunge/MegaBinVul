#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char char_u;

#define FALSE 0
#define TRUE 1
#define OK 1
#define MAXPATHL 1024
#define VALID 0

#define EVENT_BUFLEAVE 1
#define EVENT_WINLEAVE 2
#define EVENT_WINNEW 3
#define EVENT_WINENTER 4
#define EVENT_BUFENTER 5

#define BCO_ENTER 1
#define BCO_NOHELP 2

typedef struct pos {
    long col;
    long coladd;
} pos_T;

typedef struct file_buffer buf_T;

typedef struct tabpage_S {
    char_u *tp_localdir;
} tabpage_T;

typedef struct window_S {
    buf_T *w_buffer;
    int w_redr_status;
    int w_height;
    int w_width;
    int w_p_wfh;
    int w_p_wfw;
    char_u *w_localdir;
    pos_T w_cursor;
    int w_cursor_coladd;
} win_T;

static win_T *curwin;
static buf_T *curbuf;
static tabpage_T *curtab;
static win_T *prevwin;
static char_u *globaldir;
static int redraw_tabline;
static int restart_edit;
static int redraw_mode;
static int p_wh;
static int p_wiw;
static int vim_ignored;

static int win_valid(win_T *wp);
static void leaving_window(win_T *wp);
static void entering_window(win_T *wp);
static void apply_autocmds(int event, char_u *fname, char_u *fname_io, int force, buf_T *buf);
static void u_sync(int force);
static void update_topline(void);
static void buf_copy_options(buf_T *buf, int flags);
static void check_cursor(void);
static int virtual_active(void);
static void changed_line_abv_curs(void);
static int mch_dirname(char_u *buf, int len);
static char_u *vim_strsave(char_u *str);
static int mch_chdir(char *path);
static void shorten_fnames(int force);
static void maketitle(void);
static int bt_terminal(buf_T *buf);
static void redraw_later(int type);
static void win_setheight(int height);
static void win_setwidth(int width);
static void setmouse(void);
static int popup_is_popup(win_T *win);
static int aborting(void);

#define VIM_CLEAR(ptr) do { free(ptr); (ptr) = NULL; } while (0)
#define DO_AUTOCHDIR 0