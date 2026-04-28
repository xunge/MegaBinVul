#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char char_u;
typedef long linenr_T;
typedef int colnr_T;

typedef struct {
    void *regprog;
    char_u *startp[10];
    char_u *endp[10];
    int rm_ic;
} regmatch_T;

typedef struct {
    FILE *fp;
    char_u *name;
    linenr_T lnum;
    int matched;
} SearchedFile;

typedef struct buf {
    char_u *b_fname;
    char_u *b_ffname;
    char_u *b_p_inc;
    char_u *b_p_def;
    struct {
        long ml_line_count;
    } b_ml;
} buf_T;

typedef struct win {
    buf_T *w_buffer;
    struct {
        linenr_T lnum;
        colnr_T col;
    } w_cursor;
    int w_set_curswant;
} win_T;

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define LSIZE 1024
#define IOSIZE 1024
#define FORWARD 1
#define BACKWARD 2
#define OK 1
#define FAIL 0
#define FPC_SAME 1
#define FNAME_EXP 1
#define FNAME_INCL 2
#define FNAME_REL 4
#define ACTION_SHOW 1
#define ACTION_SHOW_ALL 2
#define ACTION_EXPAND 3
#define ACTION_SPLIT 4
#define CHECK_PATH 1
#define FIND_DEFINE 2
#define RE_MAGIC 1
#define CPO_JOINSP 'j'
#define HL_ATTR(x) 0
#define HLF_D 0
#define HLF_R 0
#define TAB '\t'

static buf_T *curbuf = NULL;
static win_T *curwin = NULL;
static win_T *firstwin = NULL;
static int g_do_tagpreview = 0;
static int need_mouse_correct = 0;
static int msg_hist_off = 0;
static int got_int = 0;
static char_u IObuff[IOSIZE];
static char_u *p_inc = "";
static char_u *p_def = "";
static int p_ic = 0;
static int p_scs = 0;
static int p_verbose = 0;
static int p_js = 0;
static char_u *p_cpo = "";

#define VIM_CLEAR(x) free(x)
#define ALLOC_MULT(type, size) malloc(size)
#define vim_free free
#define alloc malloc
#define lalloc_clear calloc
#define vim_regcomp(a,b) NULL
#define vim_regfree(x)
#define vim_regexec(a,b,c) 0
#define vim_isfilec(x) isalnum(x)
#define vim_iswordc(x) isalnum(x)
#define vim_iswordp(x) isalnum(*x)
#define vim_strchr strchr
#define vim_snprintf snprintf
#define vim_fgets fgets
#define mch_fopen fopen
#define STRLEN strlen
#define STRNCMP strncmp
#define MB_STRNICMP strncasecmp
#define STRNCPY strncpy
#define _(x) x
#define GETFILE_SUCCESS(x) (x)
#define getfile(a,b,c,d,e,f) 0
#define mb_ptr2len(x) 1

#define magic_isset() 0
#define ignorecase(x) 0
#define compl_status_sol() 0
#define compl_status_adding() 0
#define ins_compl_len() 0
#define ins_compl_add_infercase(a,b,c,d,e,f) 0
#define ins_compl_check_keys(a,b)
#define ins_compl_interrupted() 0
#define msg_putchar(x)
#define msg_puts(x)
#define msg_puts_title(x)
#define msg_outtrans_attr(x,y)
#define msg_home_replace(x)
#define msg_home_replace_hl(x)
#define msg_trunc_attr(x,y,z)
#define msg(x)
#define emsg(x)
#define smsg(...)
#define verbose_enter()
#define verbose_leave()
#define gotocmdline(x)
#define msg_end()
#define out_flush()
#define line_breakcheck()
#define win_split(a,b) 0
#define RESET_BINDING(x)
#define setpcmark()
#define check_cursor()
#define validate_cursor()
#define redraw_later(x)
#define win_enter(x,y)
#define prepare_tagpreview(a,b,c)
#define win_valid(x) 1
#define show_pat_in_path(a,b,c,d,e,f,g)
#define fullpathcmp(a,b,c,d) 0
#define find_file_name_in_path(a,b,c,d,e) NULL
#define file_name_in_line(a,b,c,d,e,f) NULL
#define find_word_start(x) x
#define find_word_end(x) x
#define skipwhite(x) x
#define get_leader_len(a,b,c,d) 0
#define ml_get(x) NULL

#define UNUSED