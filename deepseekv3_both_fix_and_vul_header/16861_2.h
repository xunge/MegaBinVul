#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

typedef unsigned char char_u;
typedef long linenr_T;
typedef struct win win_T;
typedef struct buf buf_T;
typedef struct exarg exarg_T;
typedef struct pos pos_T;
typedef struct bufref bufref_T;
typedef struct tabpage tabpage_T;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define NUL '\0'
#define MAXPATHL 1024

#define FEAT_EVAL 1
#define FEAT_BROWSE 1
#define FEAT_GUI 1
#define FEAT_SPELL 1
#define FEAT_PROP_POPUP 1
#define FEAT_DIFF 1
#define FEAT_KEYMAP 1
#define FEAT_AUTOCHDIR 1
#define FEAT_NETBEANS_INTG 1
#define FEAT_SYN_HL 1
#define FEAT_FOLDING 1
#define FEAT_TITLE 1
#define FEAT_QUICKFIX 1
#define FEAT_VIMINFO 1

#define ECMD_ADDBUF 1
#define ECMD_ALTBUF 2
#define ECMD_HIDE 4
#define ECMD_SET_HELP 8
#define ECMD_OLDBUF 16
#define ECMD_FORCEIT 32
#define ECMD_LASTL 64
#define ECMD_LAST 128

#define CCGD_AW 1
#define CCGD_MULTWIN 2
#define CCGD_FORCEIT 4
#define CCGD_EXCMD 8

#define BLN_LISTED 1
#define BLN_NOCURWIN 2
#define BLN_CURBUF 4

#define BCO_ENTER 1

#define DOBUF_UNLOAD 1

#define BFA_KEEP_UNDO 1

#define READ_KEEP_UNDO 1

#define DOCMD_VERBOSE 1
#define DOCMD_RANGEOK 2

#define SEA_DIALOG 1
#define SEA_QUIT 2

#define OPT_WINONLY 1

#define BL_SOL 1
#define BL_FIX 2
#define BL_WHITE 4

#define NOT_VALID 0

#define SHM_OVERALL 1
#define SHM_FILEINFO 2

#define KEYMAP_INIT 1

#define BF_NEVERLOADED 1
#define BF_CHECK_RO 2
#define BF_NO_SEA 4

#define CMOD_BROWSE 1
#define CMOD_KEEPALT 2

#define VV_SWAPCOMMAND 1

#define EVENT_BUFLEAVE 1
#define EVENT_BUFENTER 2
#define EVENT_BUFWINENTER 3

struct pos {
    linenr_T lnum;
    int col;
    int coladd;
};

struct bufref {
    buf_T *br_buf;
    int br_buf_free_count;
};

struct exarg {
    char_u *do_ecmd_cmd;
};

struct win {
    int w_alt_fnum;
    long w_p_so;
    int w_closing;
    int w_p_diff;
    int w_p_spell;
    int w_p_pvw;
    pos_T w_cursor;
    pos_T w_pcmark;
    linenr_T w_topline;
    int w_set_curswant;
    buf_T *w_buffer;
    struct synblock *w_s;
    int w_scbind_pos;
};

struct buf {
    int b_fnum;
    char_u *b_ffname;
    char_u *b_fname;
    int b_nwindows;
    int b_flags;
    int b_help;
    int b_locked;
    struct {
        void *ml_mfp;
        linenr_T ml_line_count;
    } b_ml;
    pos_T b_op_start;
    pos_T b_op_end;
    struct synblock *b_s;
    char_u *b_p_spl;
    long b_last_used;
    int b_kmap_state;
};

struct synblock {
    char_u *b_p_spl;
};

struct cmdmod {
    int cmod_flags;
};

struct tabpage {
    win_T *tp_firstwin;
};

extern buf_T *curbuf;
extern win_T *curwin;
extern int p_awa;
extern long p_so;
extern int p_verbose;
extern int p_im;
extern int p_acd;
extern int p_sol;
extern int p_ur;
extern int exiting;
extern int skip_redraw;
extern int exmode_active;
extern int swap_exists_action;
extern int keep_help_flag;
extern int did_filetype;
extern int need_start_insertmode;
extern int RedrawingDisabled;
extern int msg_scroll;
extern int msg_scrolled_ign;
extern struct cmdmod cmdmod;
extern bufref_T au_new_curbuf;
#ifdef FEAT_GUI
extern struct gui {
    int in_use;
} gui;
#endif

static inline size_t STRLEN(const char_u *s) { return strlen((const char *)s); }
static inline int vim_snprintf(char *str, size_t size, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int ret = vsnprintf(str, size, format, args);
    va_end(args);
    return ret;
}
static inline const char_u *_(const char *s) { return (const char_u *)s; }
static inline void vim_strncpy(char_u *to, const char_u *from, size_t len) {
    strncpy((char *)to, (const char *)from, len);
}

static inline void set_bufref(bufref_T *bufref, buf_T *buf) {}
static inline int bufref_valid(bufref_T *bufref) { return 0; }
static inline int otherfile(char_u *fname) { return 0; }
static inline int check_changed(buf_T *buf, int flags) { return 0; }
static inline void reset_VIsual() {}
static inline char_u *get_vim_var_str(int var) { return NULL; }
static inline void set_vim_var_string(int var, char_u *str, int len) {}
static inline char_u *alloc(int size) { return NULL; }
static inline void vim_free(char_u *p) {}
static inline int setaltfname(char_u *ffname, char_u *sfname, linenr_T lnum) { return 0; }
static inline buf_T *buflist_findnr(int fnum) { return NULL; }
static inline buf_T *buflist_new(char_u *ffname, char_u *sfname, linenr_T lnum, int flags) { return NULL; }
static inline void buflist_altfpos(win_T *win) {}
static inline int buf_check_timestamp(buf_T *buf, int force) { return 0; }
static inline int aborting() { return 0; }
static inline pos_T *buflist_findfpos(buf_T *buf) { return NULL; }
static inline char_u *vim_strsave(char_u *str) { return NULL; }
static inline void apply_autocmds(int event, char_u *fname, char_u *fname_io, int force, buf_T *buf) {}
static inline void delbuf_msg(char_u *name) {}
static inline void buf_copy_options(buf_T *buf, int flags) {}
static inline void u_sync(int force) {}
static inline int close_buffer(win_T *win, buf_T *buf, int action, int abort_if_error, int hide) { return 0; }
static inline void set_file_options(int set_options, exarg_T *eap) {}
static inline void set_forced_fenc(exarg_T *eap) {}
static inline void get_winopts(buf_T *buf) {}
static inline int check_fname() { return 0; }
static inline void prepare_help_buffer() {}
static inline void set_buflisted(int listed) {}
static inline void set_last_cursor(win_T *win) {}
static inline int u_savecommon(linenr_T start, linenr_T end, int flags, int forceit) { return 0; }
static inline void u_unchanged(buf_T *buf) {}
static inline void buf_freeall(buf_T *buf, int flags) {}
static inline void buf_clear_file(buf_T *buf) {}
static inline void check_arg_idx(win_T *win) {}
static inline void curwin_init() {}
static inline void foldUpdateAll(win_T *win) {}
static inline int open_buffer(int unused, exarg_T *eap, int flags) { return 0; }
static inline void handle_swap_exists(bufref_T *bufref) {}
static inline void do_modelines(int flags) {}
static inline void apply_autocmds_retval(int event, char_u *fname, char_u *fname_io, int force, buf_T *buf, int *retval) {}
static inline char_u *ml_get_curline() { return NULL; }
static inline char_u *skipwhite(char_u *p) { return p; }
static inline void changed_line_abv_curs() {}
static inline void maketitle() {}
static inline void popup_set_title(win_T *win) {}
static inline void diff_buf_add(buf_T *buf) {}
static inline void diff_invalidate(buf_T *buf) {}
static inline int did_set_spelllang(win_T *win) { return 0; }
static inline void check_cursor() {}
static inline void check_cursor_lnum() {}
static inline void check_cursor_col() {}
static inline void beginline(int flags) {}
static inline void check_lnums(int force) {}
static inline void check_for_delay(int force) {}
static inline void msg_start() {}
static inline void fileinfo(int fullname, int verbose, int notabs) {}
static inline long vim_time() { return 0; }
static inline void do_cmdline(char_u *cmdline, void *cookie, void *eap, int flags) {}
static inline int keymap_init() { return 0; }
static inline void update_topline() {}
static inline void redraw_curbuf_later(int flags) {}
static inline int mch_dirname(char_u *buf, int len) { return 0; }
static inline int vim_fnamecmp(char_u *f1, char_u *f2) { return 0; }
static inline void do_autochdir() {}
static inline void netbeans_file_opened(buf_T *buf) {}
static inline char_u *fix_fname(char_u *fname) { return NULL; }
static inline int mch_isdir(char_u *name) { return 0; }
static inline int au_has_group(char_u *name) { return 0; }
static inline char_u *do_browse(int flags, char_u *title, char_u *dflt, char_u *ext, char_u *initdir, char_u *filter, buf_T *buf) { return NULL; }
static inline void fname_case(char_u *name, int len) {}
static inline int should_abort(int ret) { return ret; }
static inline int shortmess(int flag) { return 0; }
static inline char_u *gettail_sep(char_u *fname) { return fname; }
static inline int buf_valid(buf_T *buf) { return 0; }
static inline int win_valid_any_tab(win_T *win) { return 0; }
static inline int WIN_IS_POPUP(win_T *win) { return 0; }
static inline int EQUAL_POS(pos_T p1, pos_T p2) { return 0; }
static inline void DO_AUTOCHDIR() {}
#define FOR_ALL_TAB_WINDOWS(tp, win) for (tp = NULL, win = NULL; win == NULL; tp = NULL)
#define ERROR_IF_TERM_POPUP_WINDOW 0