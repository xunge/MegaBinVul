#include <stddef.h>
#include <string.h>

typedef unsigned char char_u;
typedef int event_T;
typedef int sctx_T;
typedef int funccal_entry_T;
typedef int proftime_T;
typedef int save_redo_T;

#define NUM_EVENTS 0
#define AUGROUP_ALL 0
#define FALSE 0
#define TRUE 1
#define OK 1
#define NUL '\0'
#define FEAT_EVAL 1
#define FEAT_PROFILE 1
#define FEAT_SYN_HL 1
#define BACKSLASH_IN_FILENAME 1
#define VMS 0
#define UNUSED
#define _(x) x
#define e_autocommand_nesting_too_deep "E123"
#define VV_CMDBANG 0
#define ETYPE_AUCMD 0
#define DOCMD_NOWAIT 0
#define DOCMD_VERBOSE 0
#define DOCMD_REPEAT 0

struct buf_T {
    int b_changed;
    char_u *b_ffname;
    char_u *b_sfname;
    int b_fnum;
    char_u *b_p_syn;
    char_u *b_p_ft;
    struct buf_T *b_next;
};

struct win_T {
    struct win_T *w_next;
};

struct AutoPat {
    struct AutoPat *next;
    int last;
};

struct AutoPatCmd_T {
    struct AutoPat *curpat;
    int group;
    char_u *fname;
    char_u *sfname;
    char_u *tail;
    event_T event;
    int arg_bufnr;
    struct AutoPatCmd_T *next;
};

struct exarg_T {
    int forceit;
};

typedef struct buf_T buf_T;
typedef struct exarg_T exarg_T;
typedef struct AutoPat AutoPat;
typedef struct AutoPatCmd_T AutoPatCmd_T;
typedef struct win_T win_T;

/* Event definitions */
#define EVENT_FILECHANGEDSHELL 0
#define EVENT_FILECHANGEDSHELLPOST 1
#define EVENT_WINENTER 2
#define EVENT_BUFENTER 3
#define EVENT_WINLEAVE 4
#define EVENT_BUFLEAVE 5
#define EVENT_COLORSCHEME 6
#define EVENT_COLORSCHEMEPRE 7
#define EVENT_OPTIONSET 8
#define EVENT_MODECHANGED 9
#define EVENT_SYNTAX 10
#define EVENT_FILETYPE 11
#define EVENT_CMDLINECHANGED 12
#define EVENT_CMDLINEENTER 13
#define EVENT_CMDLINELEAVE 14
#define EVENT_CMDWINENTER 15
#define EVENT_CMDWINLEAVE 16
#define EVENT_CMDUNDEFINED 17
#define EVENT_FUNCUNDEFINED 18
#define EVENT_REMOTEREPLY 19
#define EVENT_SPELLFILEMISSING 20
#define EVENT_QUICKFIXCMDPRE 21
#define EVENT_QUICKFIXCMDPOST 22
#define EVENT_DIRCHANGED 23
#define EVENT_DIRCHANGEDPRE 24
#define EVENT_USER 25
#define EVENT_WINCLOSED 26
#define EVENT_WINSCROLLED 27
#define EVENT_BUFREADPOST 28
#define EVENT_BUFWRITEPOST 29
#define EVENT_FILEAPPENDPOST 30
#define EVENT_VIMLEAVE 31
#define EVENT_VIMLEAVEPRE 32
#define EVENT_BUFWIPEOUT 33

static int autocmd_blocked;
static int autocmd_busy;
static int autocmd_nested;
static int autocmd_no_enter;
static int autocmd_no_leave;
static int KeyTyped;
static int did_emsg;
static int did_filetype;
static int keep_filetype;
static int au_did_filetype;
static int need_maketitle;
static int RedrawingDisabled;
static int do_profiling;
#define PROF_YES 1
static char_u *autocmd_fname;
static int autocmd_fname_full;
static int autocmd_bufnr;
static char_u *autocmd_match;
static buf_T *curbuf;
static AutoPat *first_autopat[NUM_EVENTS];
static buf_T *au_pending_free_buf;
static win_T *au_pending_free_win;
static AutoPatCmd_T *active_apc_list;
static sctx_T current_sctx;

static char_u *vim_strsave(char_u *s) { return NULL; }
static char_u *FullName_save(char_u *fname, int flag) { return NULL; }
static char_u *gettail(char_u *fname) { return NULL; }
static void forward_slash(char_u *fname) {}
static void vms_remove_version(char_u *fname) {}
static void save_search_patterns() {}
static void saveRedobuff(save_redo_T *save_redo) {}
static void restoreRedobuff(save_redo_T *save_redo) {}
static void restore_search_patterns() {}
static void check_lnums(int flag) {}
static void reset_lnums() {}
static void do_cmdline(char *cmdline, void *getnextac, void *patcmd, int flags) {}
static void save_funccal(funccal_entry_T *funccal_entry) {}
static void restore_funccal() {}
static void prof_child_enter(proftime_T *wait_time) {}
static void prof_child_exit(proftime_T *wait_time) {}
static void auto_next_pat(AutoPatCmd_T *patcmd, int flag) {}
static void au_cleanup() {}
static void aubuflocal_remove(buf_T *buf) {}
static long get_vim_var_nr(int var) { return 0; }
static void set_vim_var_nr(int var, long val) {}
static char_u *set_cmdarg(exarg_T *eap, char_u *save_cmdarg) { return NULL; }
static int ends_excmd(int c) { return 0; }
static int ins_compl_active() { return 0; }
static int event_ignored(event_T event) { return 0; }
static int aborting() { return 0; }
static void emsg(char *msg) {}
static void vim_free(void *ptr) {}
static void estack_push(int type, char *name, int lnum) {}
static void estack_pop() {}
static void *getnextac;  // Dummy declaration for getnextac

#define ESTACK_CHECK_DECLARATION
#define ESTACK_CHECK_SETUP
#define ESTACK_CHECK_NOW
#define CLEAR_FIELD(x) memset(&(x), 0, sizeof(x))
#define SOURCING_NAME NULL