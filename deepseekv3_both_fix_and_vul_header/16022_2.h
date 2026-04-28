#include <stddef.h>
#include <stdbool.h>

#define FORWARD 1
#define BACKWARD 2

#define DOBUF_FIRST 1
#define DOBUF_LAST 2
#define DOBUF_MOD 3
#define DOBUF_UNLOAD 4
#define DOBUF_DEL 5
#define DOBUF_WIPE 6
#define DOBUF_WIPE_REUSE 7
#define DOBUF_GOTO 8
#define DOBUF_SPLIT 9
#define DOBUF_FORCEIT 1
#define DOBUF_NOPOPUP 2

#define FAIL 1
#define OK 0
#define TRUE true
#define FALSE false

#define BF_DUMMY (1 << 0)
#define SWB_USEOPEN (1 << 0)
#define SWB_USETAB (1 << 1)

#define FEAT_PROP_POPUP
#define FEAT_GUI
#define FEAT_GUI_DIALOG
#define FEAT_CON_DIALOG
#define FEAT_TERMINAL
#define FEAT_EVAL

typedef struct buf_T buf_T;
typedef struct bufref_T bufref_T;
typedef struct window_S window_S;
typedef struct tabpage_S tabpage_S;

struct buf_T {
    buf_T *b_next;
    buf_T *b_prev;
    int b_fnum;
    int b_p_bl;
    int b_flags;
    int b_nwindows;
    int b_help;
    int b_locked;
    struct {
        void *ml_mfp;
    } b_ml;
    void *b_term;
    unsigned b_changed:1;
};

struct bufref_T {
    buf_T *br_buf;
};

struct window_S {
    buf_T *w_buffer;
    int w_closing;
    int w_jumplistlen;
    int w_jumplistidx;
    struct {
        struct {
            int fnum;
        } fmark;
    } *w_jumplist;
};

struct tabpage_S {
    tabpage_S *tp_next;
};

struct {
    int cmod_flags;
} cmdmod;

#define CMOD_CONFIRM (1 << 0)

extern buf_T *firstbuf;
extern buf_T *lastbuf;
extern buf_T *curbuf;
extern window_S *curwin;
extern tabpage_S *first_tabpage;
extern bufref_T au_new_curbuf;
extern int need_mouse_correct;
extern int p_confirm;
extern int p_write;
extern int VIsual_active;
extern int swb_flags;
extern int ONE_WINDOW;

#define _(x) x
#define e_no_modified_buffer_found "No modified buffer found"
#define e_there_is_no_listed_buffer "There is no listed buffer"
#define e_buffer_nr_does_not_exist "Buffer %d does not exist"
#define e_cannot_go_beyond_last_buffer "Cannot go beyond last buffer"
#define e_cannot_go_before_first_buffer "Cannot go before first buffer"

static int bufIsChanged(buf_T *buf) { return 0; }
static int can_unload_buffer(buf_T *buf) { return 1; }
static void set_bufref(bufref_T *bufref, buf_T *buf) {}
static int bufref_valid(bufref_T *bufref) { return 1; }
static void dialog_changed(buf_T *buf, int flag) {}
static void no_write_message_buf(buf_T *buf) {}
static void no_write_message() {}
static void end_visual_mode() {}
static int empty_curbuf(int flag1, int flag2, int action) { return 0; }
static int win_close(window_S *win, int flag) { return 0; }
static void close_windows(buf_T *buf, int flag) {}
static void close_buffer(void *unused, buf_T *buf, int action, int flag1, int flag2) {}
static int bt_popup(buf_T *buf) { return 0; }
static int bt_terminal(buf_T *buf) { return 0; }
static int bt_quickfix(buf_T *buf) { return 0; }
static int term_job_running(void *term) { return 0; }
static int term_confirm_stop(buf_T *buf) { return 0; }
static void free_terminal(buf_T *buf) {}
static int win_split(int size, int flags) { return 0; }
static int can_abandon(buf_T *buf, int flags) { return 1; }
static void set_curbuf(buf_T *buf, int action) {}
#define RESET_BINDING(win) {}
static int aborting() { return 0; }
static int buf_jump_open_win(buf_T *buf) { return 0; }
static int buf_jump_open_tab(buf_T *buf) { return 0; }
static buf_T *buflist_findnr(int fnum) { return NULL; }

#define FOR_ALL_BUFFERS(buf) for (buf = firstbuf; buf != NULL; buf = buf->b_next)
#define semsg(msg, arg) 
#define emsg(msg) 