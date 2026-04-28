#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef long linenr_T;
typedef int int32_T;
typedef unsigned char char_u;

#define CMOD_BROWSE 0x01
#define CMOD_KEEPALT 0x02
#define VV_SWAPCOMMAND 0

typedef struct {
    linenr_T lnum;
    int col;
    int coladd;
} pos_T;

typedef struct {
    int b_fnum;
    char_u *b_ffname;
    char_u *b_fname;
    int b_nwindows;
    int b_flags;
    struct {
        void *ml_mfp;
        linenr_T ml_line_count;
    } b_ml;
    struct {
        char_u *b_p_spl;
    } b_s;
    long b_last_used;
    int b_kmap_state;
    pos_T b_last_cursor;
    pos_T b_op_start;
    pos_T b_op_end;
    int b_help;
    int b_locked;
} buf_T;

typedef struct {
    buf_T *br_buf;
} bufref_T;

typedef struct {
    pos_T w_cursor;
    pos_T w_pcmark;
    linenr_T w_topline;
    int w_p_so;
    int w_p_diff;
    int w_p_spell;
    buf_T *w_buffer;
    int w_alt_fnum;
    int w_closing;
    int w_set_curswant;
    int w_p_pvw;
    struct {
        char_u *b_p_spl;
    } *w_s;
    linenr_T w_scbind_pos;
} win_T;

typedef struct {
    int cmod_flags;
} cmdmod_T;

typedef struct {
    int in_use;
} gui_T;

typedef struct {
    char_u *do_ecmd_cmd;
} exarg_T;

typedef struct {
    win_T *w_buffer;
} tabpage_T;

extern buf_T *curbuf;
extern win_T *curwin;
extern cmdmod_T cmdmod;
extern gui_T gui;
extern int p_so;
extern int p_awa;
extern int p_verbose;
extern int p_im;
extern int p_sol;
extern int p_acd;
extern int p_ur;
extern int State;
extern int skip_redraw;
extern int exiting;
extern int exmode_active;
extern int swap_exists_action;
extern int keep_help_flag;
extern int did_filetype;
extern int need_start_insertmode;
extern int msg_scroll;
extern int msg_scrolled_ign;
extern int RedrawingDisabled;
extern int cmdwin_type;
extern bufref_T au_new_curbuf;

#define FALSE 0
#define TRUE 1
#define OK 1
#define FAIL 0
#define NUL '\0'
#define MAXPATHL 1024
#define ECMD_ADDBUF 0x01
#define ECMD_ALTBUF 0x02
#define ECMD_HIDE 0x04
#define ECMD_FORCEIT 0x08
#define ECMD_OLDBUF 0x10
#define ECMD_NOWINENTER 0x20
#define ECMD_SET_HELP 0x40
#define ECMD_LASTL (-2)
#define ECMD_LAST (-1)
#define CCGD_AW 0x01
#define CCGD_MULTWIN 0x02
#define CCGD_FORCEIT 0x04
#define CCGD_EXCMD 0x08
#define BLN_LISTED 0x01
#define BLN_NOCURWIN 0x02
#define BLN_CURBUF 0x04
#define BCO_ENTER 0x01
#define DOBUF_UNLOAD 0x01
#define BFA_KEEP_UNDO 0x01
#define READ_KEEP_UNDO 0x01
#define READ_NOWINENTER 0x02
#define DOCMD_VERBOSE 0x01
#define DOCMD_RANGEOK 0x02
#define UPD_NOT_VALID 0x01
#define KEYMAP_INIT 0x01
#define BF_NEVERLOADED 0x01
#define BF_NOTEDITED 0x02
#define BF_CHECK_RO 0x04
#define BF_NO_SEA 0x08
#define SHM_OVERALL 0x01
#define SHM_FILEINFO 0x02
#define SEA_DIALOG 0x01
#define SEA_QUIT 0x02
#define MODE_INSERT 0x01
#define OPT_WINONLY 0x01
#define BL_SOL 0x01
#define BL_FIX 0x02
#define BL_WHITE 0x04
#define EVENT_BUFLEAVE 0
#define EVENT_BUFENTER 1
#define EVENT_BUFWINENTER 2

#define FEAT_EVAL
#define FEAT_BROWSE
#define FEAT_GUI
#define FEAT_SPELL
#define FEAT_PROP_POPUP
#define FEAT_DIFF
#define FEAT_VIMINFO
#define FEAT_KEYMAP
#define FEAT_AUTOCHDIR
#define FEAT_NETBEANS_INTG
#define FEAT_QUICKFIX
#define FEAT_SYN_HL
#define FEAT_FOLDING

#define ERROR_IF_TERM_POPUP_WINDOW 0
#define WIN_IS_POPUP(win) 0
#define FOR_ALL_TAB_WINDOWS(tp, win) 
#define DO_AUTOCHDIR

extern char_u *get_vim_var_str(int);
extern void set_vim_var_string(int, char_u *, int);
extern int au_has_group(char_u *);
extern int mch_isdir(char_u *);
extern char_u *do_browse(int, char_u *, char_u *, char_u *, char_u *, char_u *, buf_T *);
extern void fname_case(char_u *, int);
extern char_u *fix_fname(char_u *);
extern int otherfile(char_u *);
extern int setaltfname(char_u *, char_u *, linenr_T);
extern int check_changed(buf_T *, int);
extern void reset_VIsual(void);
extern int win_valid(win_T *);
extern int win_valid_any_tab(win_T *);
extern char_u *alloc(int);
extern void vim_snprintf(char *, int, const char *, ...);
extern void vim_free(void *);
extern buf_T *buflist_findnr(int);
extern buf_T *buflist_new(char_u *, char_u *, linenr_T, int);
extern void buflist_altfpos(win_T *);
extern pos_T *buflist_findfpos(buf_T *);
extern void set_bufref(bufref_T *, buf_T *);
extern int bufref_valid(bufref_T *);
extern int buf_valid(buf_T *);
extern int buf_check_timestamp(buf_T *, int);
extern void buf_copy_options(buf_T *, int);
extern int close_buffer(win_T *, buf_T *, int, int, int);
extern void get_winopts(buf_T *);
extern int parse_spelllang(win_T *);
extern void prepare_help_buffer(void);
extern void set_buflisted(int);
extern void set_last_cursor(win_T *);
extern int u_savecommon(linenr_T, linenr_T, int, int);
extern void u_unchanged(buf_T *);
extern void buf_freeall(buf_T *, int);
extern void buf_clear_file(buf_T *);
extern void curwin_init(void);
extern void foldUpdateAll(win_T *);
extern void do_modelines(int);
extern int apply_autocmds(int, char_u *, char_u *, int, buf_T *);
extern int apply_autocmds_retval(int, char_u *, char_u *, int, buf_T *, int *);
extern int open_buffer(int, exarg_T *, int);
extern void handle_swap_exists(bufref_T *);
extern void check_arg_idx(win_T *);
extern void changed_line_abv_curs(void);
extern void maketitle(void);
extern void popup_set_title(win_T *);
extern void diff_buf_add(buf_T *);
extern void diff_invalidate(buf_T *);
extern void check_cursor(void);
extern void check_cursor_lnum(void);
extern void check_cursor_col(void);
extern void beginline(int);
extern void check_lnums(int);
extern int check_fname(void);
extern void check_for_delay(int);
extern void msg_start(void);
extern void fileinfo(int, int, int);
extern int shortmess(int);
extern void do_cmdline(char_u *, void *, void *, int);
extern int keymap_init(void);
extern void update_topline(void);
extern void redraw_curbuf_later(int);
extern int mch_dirname(char_u *, int);
extern int vim_fnamecmp(char_u *, char_u *);
extern void do_autochdir(void);
extern void netbeans_file_opened(buf_T *);
extern char_u *ml_get_curline(void);
extern char_u *skipwhite(char_u *);
extern char_u *vim_strsave(char_u *);
extern char_u *vim_strncpy(char_u *, char_u *, int);
extern char_u *gettail_sep(char_u *);
extern long vim_time(void);
extern int should_abort(int);
extern int aborting(void);
extern void delbuf_msg(char_u *);
extern void set_file_options(int, exarg_T *);
extern void set_forced_fenc(exarg_T *);
extern int u_sync(int);
extern int EQUAL_POS(pos_T, pos_T);
extern char_u *_(const char *);
#define STRLEN strlen