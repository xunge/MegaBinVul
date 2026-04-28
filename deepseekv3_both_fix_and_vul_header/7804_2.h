#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char char_u;
typedef long linenr_T;
typedef int colnr_T;

#define FALSE 0
#define TRUE 1
#define FAIL 1
#define K_IGNORE 0
#define Ctrl_C 3
#define CAR '\r'
#define TAB '\t'
#define K_NOP 0
#define K_XF1 0
#define K_XF2 0
#define WSP_BOT 0
#define ECMD_ONE 0
#define ECMD_HIDE 0
#define MODE_INSERT 1
#define MODE_NORMAL 0
#define SOME_VALID 0
#define HIST_CMD 0
#define HIST_DEBUG 0
#define DOBUF_WIPE 0
#define OPT_LOCAL 0
#define CMOD_NOSWAPFILE (1 << 0)
#define EVENT_BUFFILEPRE 0
#define EVENT_BUFFILEPOST 0
#define EVENT_CMDWINENTER 0
#define EVENT_CMDWINLEAVE 0

struct bufref_S {
    struct buf_S *br_buf;
};
typedef struct bufref_S bufref_T;

struct window_S {
    struct {
        linenr_T lnum;
        colnr_T col;
    } w_cursor;
    int w_p_fen;
    int w_p_rl;
    int w_p_cole;
};
typedef struct window_S win_T;

struct buf_S {
    struct {
        linenr_T ml_line_count;
    } b_ml;
    int b_p_ma;
    int b_p_tw;
};
typedef struct buf_S buf_T;

struct cmdmod_S {
    int cmod_tab;
    int cmod_flags;
};
typedef struct cmdmod_S cmdmod_T;

struct ccline_S {
    char_u *cmdbuff;
    int cmdlen;
    int cmdbufflen;
    int cmdpos;
};
typedef struct ccline_S ccline_T;

struct garray_S {
    void *ga_data;
};
typedef struct garray_S garray_T;

struct hist_entry {
    char_u *hisstr;
    int hisnum;
};
typedef struct hist_entry histentry_T;

static struct cmdmod_S cmdmod;
static struct ccline_S ccline;
static int cmdwin_type;
static int cmdwin_result;
static int cmdline_star;
static int got_int;
static int need_wait_return;
static int curbuf_lock;
static int restart_edit;
static int State;
static int exmode_active;
static int cmdmsg_rl;
static int KeyTyped;
static int RedrawingDisabled;
static int p_wc;
static int p_cwh;
static win_T *curwin;
static buf_T *curbuf;

static char *e_active_window_or_buffer_deleted = "EActive";

#define STRLEN(s) strlen((const char *)(s))
#define _(s) s

static int *get_hisidx(int histype) { return NULL; }
static histentry_T *get_histentry(int histype) { return NULL; }
static int get_hislen(void) { return 0; }