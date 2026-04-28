#include <stddef.h>
#include <stdint.h>

typedef struct window_S win_T;
typedef struct tabpage_S tabpage_T;
typedef struct buf_S buf_T;
typedef struct alist_S alist_T;
typedef struct bufref_S bufref_T;
typedef struct frame_S frame_T;
typedef struct cmdmod_S {
    int cmod_tab;
} cmdmod_T;

#define FALSE 0
#define TRUE 1
#define OK 1
#define FAIL 0
#define FEAT_CMDWIN
#define FEAT_GUI
#define Columns 80
#define ONE_WINDOW 1
#define WSP_ROOM 0
#define WSP_BELOW 0
#define ECMD_ONE 0
#define ECMD_HIDE 0
#define ECMD_OLDBUF 0
#define FPC_SAME 1

typedef uint8_t char_u;
typedef long linenr_T;

struct argentry {
    int ae_fnum;
};

extern int ARGCOUNT;
extern int arglist_locked;
extern int cmdwin_type;
extern int got_int;
extern int p_ea;
extern int p_tpm;
extern int autocmd_no_enter;
extern int autocmd_no_leave;
extern int need_mouse_correct;
extern int arg_had_last;
extern win_T *firstwin;
extern win_T *curwin;
extern win_T *lastwin;
extern win_T *new_curwin;
extern tabpage_T *first_tabpage;
extern tabpage_T *curtab;
extern tabpage_T *new_curtab;
extern alist_T global_alist;
extern cmdmod_T cmdmod;
extern buf_T *curbuf;

struct frame_S {
    frame_T *fr_parent;
};

struct ga_S {
    int ga_len;
    struct argentry *ga_data;
};

struct buf_S {
    char_u *b_ffname;
    int b_fnum;
    int b_nwindows;
    int b_changed;
    struct {
        linenr_T ml_line_count;
    } b_ml;
};

struct window_S {
    win_T *w_next;
    buf_T *w_buffer;
    int w_arg_idx;
    alist_T *w_alist;
    frame_T *w_frame;
    int w_width;
};

struct tabpage_S {
    tabpage_T *tp_next;
};

struct alist_S {
    struct ga_S al_ga;
    int al_refcount;
};

struct bufref_S {
    buf_T *br_buf;
};

char_u *alloc_clear(int size);
void emsg(const char *msg);
void setpcmark();
int buf_hide(buf_T *buf);
int bufIsChanged(buf_T *buf);
int autowrite(buf_T *buf, int force);
int win_valid(win_T *wp);
int valid_tabpage(tabpage_T *tp);
void win_close(win_T *wp, int force);
void alist_unlink(alist_T *alist);
void goto_tabpage_tp(tabpage_T *tp, int trigger, int trigger_leave);
int win_split(int size, int flags);
int do_ecmd(int fnum, char_u *fname, char_u *sfname, char_u *cmd, int flags, int opt, win_T *wp);
void win_move_after(win_T *wp, win_T *target);
void win_enter(win_T *wp, int no_curwin);
void ui_breakcheck();
void vim_free(void *ptr);
int fullpathcmp(char_u *f1, char_u *f2, int checkname, int expandenv);
char_u *alist_name(struct argentry *ae);
char_u *ml_get_buf(buf_T *buf, linenr_T lnum, int will_change);
void set_bufref(bufref_T *bufref, buf_T *buf);
int bufref_valid(bufref_T *bufref);
int tabpage_index(tabpage_T *tp);

#define _(x) x
#define e_invalid_in_cmdline_window "E11: Invalid in command-line window;"
#define E249 "E249: window layout changed unexpectedly"
#define NUL '\0'

#define AARGLIST(alist) ((struct argentry*)alist->al_ga.ga_data)
#define BUFEMPTY() (curbuf->b_ml.ml_line_count == 1 && *ml_get_buf(curbuf, 1, FALSE) == NUL)
#define FOR_ALL_WINDOWS(wp) for (wp = firstwin; wp != NULL; wp = wp->w_next)