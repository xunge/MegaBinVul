#include <stddef.h>

#define FORWARD 1
#define BACKWARD 0

#define DOBUF_FIRST 0
#define DOBUF_LAST 1
#define DOBUF_MOD 2
#define DOBUF_UNLOAD 3
#define DOBUF_DEL 4
#define DOBUF_WIPE 5
#define DOBUF_WIPE_REUSE 6
#define DOBUF_GOTO 7
#define DOBUF_SPLIT 8

#define DOBUF_FORCEIT 0x01
#define DOBUF_NOPOPUP 0x02

#define FAIL 1
#define OK 0

#define TRUE 1
#define FALSE 0

#define ONE_WINDOW 1

#define SWB_USEOPEN 0x01
#define SWB_USETAB 0x02

typedef struct buf_T buf_T;
typedef struct bufref_T bufref_T;
typedef struct window_T window_T;
typedef struct tabpage_T tabpage_T;
typedef struct xfmark_T xfmark_T;

struct xfmark_T {
    int fnum;
};

struct buf_T {
    buf_T *b_next;
    buf_T *b_prev;
    int b_fnum;
    int b_p_bl;
    int b_help;
    int b_nwindows;
    int b_locked;
    struct {
        void *ml_mfp;
    } b_ml;
};

struct bufref_T {
    buf_T *br_buf;
};

struct window_T {
    int w_closing;
    buf_T *w_buffer;
    int w_jumplistlen;
    int w_jumplistidx;
    struct {
        xfmark_T fmark;
    } *w_jumplist;
};

struct tabpage_T {
    tabpage_T *tp_next;
};

extern buf_T *firstbuf;
extern buf_T *lastbuf;
extern buf_T *curbuf;
extern window_T *curwin;
extern tabpage_T *first_tabpage;
extern int need_mouse_correct;
extern int p_confirm;
extern int p_write;
extern int swb_flags;
extern int VIsual_active;

static bufref_T au_new_curbuf;

struct {
    int cmod_flags;
    #define CMOD_CONFIRM 0x01
} cmdmod;

static int bufIsChanged(buf_T *buf) { return 0; }
static int can_unload_buffer(buf_T *buf) { return 1; }
static void set_bufref(bufref_T *bufref, buf_T *buf) {}
static int bufref_valid(bufref_T *bufref) { return 1; }
static void dialog_changed(buf_T *buf, int flag) {}
static void end_visual_mode(void) {}
static int empty_curbuf(int flag1, int flag2, int action) { return 0; }
static int win_close(window_T *win, int flag) { return 0; }
static void close_windows(buf_T *buf, int flag) {}
static void close_buffer(void *unused, buf_T *buf, int action, int flag1, int flag2) {}
static buf_T *buflist_findnr(int fnum) { return NULL; }
static int buf_jump_open_win(buf_T *buf) { return 0; }
static int buf_jump_open_tab(buf_T *buf) { return 0; }
static int win_split(int size, int flags) { return 0; }
static int can_abandon(buf_T *buf, int flag) { return 1; }
static void no_write_message(void) {}
static void set_curbuf(buf_T *buf, int action) {}
static void RESET_BINDING(window_T *win) {}
static int aborting(void) { return 0; }

#define FOR_ALL_BUFFERS(bp) for (bp = firstbuf; bp != NULL; bp = bp->b_next)

#define _(x) x
#define e_no_modified_buffer_found "No modified buffer found"
#define e_there_is_no_listed_buffer "There is no listed buffer"
#define e_buffer_nr_does_not_exist "Buffer %d does not exist"
#define e_cannot_go_beyond_last_buffer "Cannot go beyond last buffer"
#define e_cannot_go_before_first_buffer "Cannot go before first buffer"
#define e_no_write_since_last_change_for_buffer_nr_add_bang_to_override "No write since last change for buffer %d (add ! to override)"

static void emsg(const char *msg) {}
static void semsg(const char *msg, int n) {}

#ifdef FEAT_PROP_POPUP
static int bt_popup(buf_T *buf) { return 0; }
#endif

#ifdef FEAT_TERMINAL
static int bt_terminal(buf_T *buf) { return 0; }
#endif