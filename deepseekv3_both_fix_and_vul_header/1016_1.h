#include <stdbool.h>
#include <stddef.h>

typedef struct buf_T {
    long b_p_tw;
    int b_fnum;
    int b_nwindows;
} buf_T;

typedef struct win_T {
    int w_alt_fnum;
    buf_T *w_buffer;
} win_T;

typedef struct bufref_T {
    buf_T *br_buf;
} bufref_T;

typedef struct cmdmod_T {
    int cmod_flags;
} cmdmod_T;

#define FEAT_SYN_HL
#define FEAT_EVAL

#define DOBUF_UNLOAD 1
#define DOBUF_DEL 2
#define DOBUF_WIPE 3
#define DOBUF_WIPE_REUSE 4
#define DOBUF_GOTO 5

#define CMOD_KEEPALT (1 << 0)

#define EVENT_BUFLEAVE 1

#define INSERT 1
#define FALSE 0

extern buf_T *curbuf;
extern win_T *curwin;
extern buf_T *lastbuf;
extern cmdmod_T cmdmod;
extern int State;
extern bool VIsual_reselect;

void setpcmark(void);
void buflist_altfpos(win_T *wp);
void set_bufref(bufref_T *bufref, buf_T *buf);
bool bufref_valid(bufref_T *bufref);
bool apply_autocmds(int event, char *fname, char *fname_io, bool force, buf_T *buf);
void reset_synblock(win_T *win);
void close_windows(buf_T *buf, bool force);
bool aborting(void);
void u_sync(bool force);
void close_buffer(win_T *win, buf_T *buf, int action, bool abort_if_error, bool hide_if_abort);
bool buf_hide(buf_T *buf);
bool bufIsChanged(buf_T *buf);
bool win_valid(win_T *win);
bool buf_valid(buf_T *buf);
void enter_buffer(buf_T *buf);
void check_colorcolumn(win_T *win);