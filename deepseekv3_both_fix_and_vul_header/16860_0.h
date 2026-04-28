#include <stddef.h>

typedef struct win_T win_T;
typedef struct buf_T buf_T;
typedef struct tabpage_T tabpage_T;
typedef struct bufref_T bufref_T;

#define TRUE 1
#define FALSE 0

#define DOBUF_WIPE 1
#define DOBUF_WIPE_REUSE 2
#define DOBUF_DEL 3

#define BF_CHECK_RO (1 << 0)
#define BF_NEVERLOADED (1 << 1)

#define BFA_DEL (1 << 0)
#define BFA_WIPE (1 << 1)
#define BFA_IGNORE_ABORT (1 << 2)

#define FEAT_TERMINAL
#define FEAT_DIFF
#define FEAT_EVAL

#define EXITFREE

extern win_T *curwin;
extern buf_T *curbuf;
extern tabpage_T *curtab;
extern int VIsual_active;
extern int entered_free_all_mem;

struct buf_T {
    int b_nwindows;
    char b_p_bh[2];
    char *b_fname;
    char *b_ffname;
    char *b_sfname;
    int b_fnum;
    int b_locked;
    int b_flags;
    int b_p_initialized;
    int b_p_bl;
    struct buf_T *b_prev;
    struct buf_T *b_next;
#ifdef FEAT_TERMINAL
    void *b_term;
#endif
};

struct win_T {
    buf_T *w_buffer;
    struct {
        int lnum;
        int col;
    } w_cursor;
};

struct bufref_T {
    buf_T *br_buf;
};

extern buf_T *firstbuf;
extern buf_T *lastbuf;

#define CHECK_CURBUF
#define EVENT_BUFWINLEAVE 1
#define EVENT_BUFHIDDEN 2

void set_last_cursor(win_T *win);
void buflist_setfpos(buf_T *buf, win_T *win, int lnum, int col, int set_curswant);
void set_bufref(bufref_T *bufref, buf_T *buf);
int bufref_valid(bufref_T *bufref);
int apply_autocmds(int event, char *fname, char *fname2, int force, buf_T *buf);
int one_window(void);
int win_valid_any_tab(win_T *win);
void block_autocmds(void);
void unblock_autocmds(void);
void goto_tabpage_win(tabpage_T *tp, win_T *wp);
int bt_terminal(buf_T *buf);
int term_job_running(void *term);
int can_unload_buffer(buf_T *buf);
void free_terminal(buf_T *buf);
void diff_buf_delete(buf_T *buf);
int diffopt_hiddenoff(void);
void end_visual_mode(void);
void buf_freeall(buf_T *buf, int flags);
void free_buffer_stuff(buf_T *buf, int free_options);
void buf_clear_file(buf_T *buf);
void free_buffer(buf_T *buf);
int aborting(void);

struct {
    int ga_itemsize;
    int ga_len;
    void *ga_data;
} buf_reuse;

#define ga_init2(ap, size, grow) ((void)0)
#define ga_grow(ap, n) (OK)
#define OK 1

char *_(const char *str);
#define e_auabort "E123"