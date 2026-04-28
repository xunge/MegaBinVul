#include <stddef.h>

typedef struct cmdarg_T cmdarg_T;
typedef struct oparg_T oparg_T;
typedef struct win_T win_T;
typedef struct buf_T buf_T;
typedef long linenr_T;
typedef unsigned char char_u;

struct cmdarg_T {
    oparg_T *oap;
    int count1;
    int nchar;
};

struct oparg_T {
    // minimal definition for compilation
};

struct win_T {
    struct {
        linenr_T lnum;
    } w_cursor;
};

struct buf_T {
    int b_nwindows;
    int b_changed;
};

static int text_locked(void);
static void text_locked_msg(void);
static int curbuf_locked(void);
static buf_T *curbuf;
static win_T *curwin;
static char_u *grab_file_name(int count1, linenr_T *lnum);
static int curbufIsChanged(void);
static int buf_hide(buf_T *buf);
static int autowrite(buf_T *buf, int forceit);
static void setpcmark(void);
static int do_ecmd(int fnum, char_u *fname, char_u *cmd, char_u *arg, int flags, int opt, win_T *win);
static void check_cursor_lnum(void);
static void beginline(int flags);
static void clearop(oparg_T *oap);
static void clearopbeep(oparg_T *oap);
static void vim_free(void *ptr);

#define FALSE 0
#define OK 1
#define ECMD_LAST 0
#define ECMD_HIDE 0
#define FEAT_PROP_POPUP
#define ERROR_IF_TERM_POPUP_WINDOW 0
#define BL_SOL 0
#define BL_FIX 0