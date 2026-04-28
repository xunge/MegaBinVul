#include <stddef.h>
#include <string.h>

typedef struct exarg exarg_T;
typedef struct win win_T;
typedef struct buf buf_T;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define CLEAR 0
#define NUL '\0'

#define CMD_pedit 0
#define CMD_visual 0
#define CMD_view 0
#define CMD_new 0
#define CMD_tabnew 0
#define CMD_tabedit 0
#define CMD_vnew 0
#define CMD_split 0
#define CMD_vsplit 0
#define CMD_sview 0
#define CMD_enew 0
#define CMD_balt 0
#define CMD_badd 0

#define ERROR_IF_POPUP_WINDOW 0
#define ERROR_IF_TERM_POPUP_WINDOW 0
#define ECMD_ONE 0
#define ECMD_HIDE 0
#define ECMD_FORCEIT 0
#define ECMD_OLDBUF 0
#define ECMD_ADDBUF 0
#define ECMD_ALTBUF 0
#define CPO_GOTO1 'g'
#define TMODE_RAW 0
#define EXMODE_VIM 0
#define CMOD_BROWSE (1 << 0)
#define CMOD_KEEPALT (1 << 1)

struct exarg {
    int cmdidx;
    char *arg;
    char *nextcmd;
    int forceit;
    int do_ecmd_lnum;
    char *do_ecmd_cmd;
};

struct win {
    buf_T *w_buffer;
    int w_arg_idx_invalid;
    int w_alt_fnum;
};

struct buf {
    int b_nwindows;
    int b_p_ro;
    int b_fnum;
};

struct cmdmod {
    int cmod_flags;
};

struct cleanup {
    int dummy;
};

extern int exmode_active;
extern int ex_pressedreturn;
extern int global_busy;
extern int RedrawingDisabled;
extern int no_wait_return;
extern int need_wait_return;
extern int msg_scroll;
extern int hold_gui_events;
extern int must_redraw;
extern int pending_exmode_active;
extern int readonlymode;
extern int need_hide;
extern int ex_no_reprint;
extern int need_mouse_correct;
extern char *p_cpo;
extern win_T *curwin;
extern buf_T *curbuf;
extern struct cmdmod cmdmod;

void stuffReadbuff(char *cmd);
void settmode(int mode);
void main_loop(int unused1, int unused2);
int do_ecmd(int unused1, char *arg, char *unused2, exarg_T *eap, int flags1, int flags2, win_T *win);
int curbufIsChanged();
int buf_hide(buf_T *buf);
int curbuf_locked();
void win_close(win_T *win, int unused);
void do_cmd_argument(char *cmd);
void check_arg_idx(win_T *win);
void maketitle();
void setpcmark();
int win_valid(win_T *win);
char *vim_strchr(const char *s, int c);
void enter_cleanup(struct cleanup *cs);
void leave_cleanup(struct cleanup *cs);