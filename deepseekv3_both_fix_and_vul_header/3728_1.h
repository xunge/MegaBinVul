#include <stddef.h>

typedef struct exarg exarg_T;
typedef struct buf buf_T;
typedef struct win win_T;
typedef struct tabpage tabpage_T;
typedef struct bufref {
    buf_T *br_buf;
    int br_fnum;
    int br_buf_free_count;
} bufref_T;
typedef struct cleanup cleanup_T;

#define OK 1
#define FAIL 0
#define TRUE 1
#define FALSE 0
#define SEA_DIALOG 0
#define SEA_NONE 1
#define SEA_QUIT 2
#define WSP_VERT 0
#define WSP_ROOM 0
#define WSP_BELOW 0
#define DOBUF_GOTO 0
#define CMD_unhide 0
#define CMD_sunhide 0
#define ONE_WINDOW 0

struct exarg {
    int addr_count;
    int line2;
    int cmdidx;
};

struct buf {
    int b_nwindows;
    struct buf *b_next;
    int b_p_bl;
    int b_locked;
    struct {
        void *ml_mfp;
    } b_ml;
};

struct win {
    struct win *w_next;
    struct win *w_prev;
    struct buf *w_buffer;
    int w_height;
    int w_width;
    int w_status_height;
    int w_closing;
};

struct tabpage {
    struct tabpage *tp_next;
};

struct cmdmod {
    int cmod_tab;
    int cmod_split;
};

extern struct cmdmod cmdmod;
extern int p_ch;
extern int p_ea;
extern int p_tpm;
extern int swap_exists_action;
extern int swap_exists_did_quit;
extern int autocmd_no_enter;
extern int autocmd_no_leave;
extern int got_int;
extern int need_mouse_correct;
extern buf_T *firstbuf;
extern win_T *firstwin;
extern win_T *lastwin;
extern tabpage_T *first_tabpage;
extern tabpage_T *curtab;
extern win_T *curwin;

int Rows;
int Columns;
int tabline_height(void);
void setpcmark(void);
int win_close(win_T *wp, int force);
int win_unlisted(win_T *wp);
void goto_tabpage_tp(tabpage_T *tp, int update_curtab, int trigger_enter_autocmds);
int win_split(int size, int flags);
void win_move_after(win_T *wp, win_T *after);
void set_curbuf(buf_T *buf, int action);
int bufref_valid(bufref_T *bufref);
void set_bufref(bufref_T *bufref, buf_T *buf);
int buf_hide(buf_T *buf);
int bufIsChanged(buf_T *buf);
int autowrite(buf_T *buf, int force);
int win_valid(win_T *wp);
void win_enter(win_T *wp, int no_display);
void handle_swap_exists(char *fname);
void ui_breakcheck(void);
int vgetc(void);
int aborting(void);
void enter_cleanup(cleanup_T *cs);
void leave_cleanup(cleanup_T *cs);
int tabpage_index(tabpage_T *tp);

#define FOR_ALL_WINDOWS(wp) for ((wp) = firstwin; (wp) != NULL; (wp) = (wp)->w_next)