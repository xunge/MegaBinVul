#include <limits.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef long linenr_T;
typedef int colnr_T;

typedef struct {
    linenr_T lnum;
    colnr_T col;
    int coladd;
} pos_T;

typedef struct {
    int y_type;
    long y_width;
    long y_size;
    unsigned char **y_array;
} yankreg_T;

typedef struct block_def {
    int startspaces;
    int endspaces;
    colnr_T textcol;
} block_def;

typedef struct {
    unsigned int cmod_flags;
} cmdmod_T;

typedef struct {
    pos_T b_op_start;
    pos_T b_op_end;
    int b_p_ts;
    int b_p_vts_array;
    struct {
        long ml_line_count;
    } b_ml;
    struct {
        pos_T vi_start;
        pos_T vi_end;
    } b_visual;
} buf_T;

typedef struct {
    pos_T w_cursor;
    int w_set_curswant;
} win_T;

typedef unsigned char char_u;

typedef struct {
    char_u *cts_ptr;
    int cts_vcol;
    win_T *cts_win;
    linenr_T cts_lnum;
    colnr_T cts_cur_textcol;
    char_u *cts_line;
    char_u *cts_line_head;
} chartabsize_T;

#define FAIL 1
#define OK 0
#define TRUE 1
#define FALSE 0
#define MAXLNUM 0
#define MAXCOL 0
#define NUL '\0'
#define TAB '\t'
#define FORWARD 1
#define BACKWARD 0
#define MCHAR 0
#define MLINE 1
#define MBLOCK 2
#define VE_ALL 0
#define BL_WHITE 0
#define BL_FIX 0

#define PUT_FIXINDENT 0x01
#define PUT_CURSEND 0x02
#define PUT_LINE_SPLIT 0x04
#define PUT_LINE_FORWARD 0x08
#define PUT_LINE 0x10
#define PUT_BLOCK_INNER 0x20
#define PUT_CURSLINE 0x40
#define CMOD_LOCKMARKS 0x01

#define FEAT_CLIPBOARD
#define FEAT_EVAL
#define FEAT_FOLDING
#define FEAT_VARTABS

#define STRLEN(s) strlen((const char *)(s))
#define STRCPY(d, s) strcpy((char *)(d), (const char *)(s))
#define STRCAT(d, s) strcat((char *)(d), (const char *)(s))
#define STRMOVE(d, s) memmove((d), (s), strlen((const char *)(s)) + 1)
#define ALLOC_MULT(type, count) ((type *)calloc((count), sizeof(type)))

extern buf_T *curbuf;
extern win_T *curwin;
extern int VIsual_active;
extern int VIsual_mode;
extern int restart_edit;
extern cmdmod_T cmdmod;
extern yankreg_T *y_current;

static int gchar_cursor(void) { return 0; }
static char_u *_(const char *s) { return (char_u *)s; }
static char_u *e_nothing_in_register_str = "";
static char_u *e_resulting_text_too_long = "";
static char_u *e_yank_register_changed_while_using_it = "";

static void MB_PTR_ADV(char_u *p) { p++; }
static int has_mbyte = 0;
static int (*mb_ptr2len)(char_u *) = 0;
static int (*mb_head_off)(char_u *, char_u *) = 0;

static unsigned int get_ve_flags(void) { return 0; }
static void adjust_clip_reg(int *regname) {}
static int may_get_selection(int regname) { return 0; }
static int get_indent(void) { return 0; }
static void stuffcharReadbuff(int c) {}
static int stuff_inserted(int c, long count, int flag) { return 0; }
static int get_spec_reg(int regname, char_u **str, int *allocated, int special) { return 0; }
static int u_save(linenr_T start, linenr_T end) { return 0; }
static char_u *vim_strchr(char_u *str, int c) { return NULL; }
static int u_save_cursor(void) { return 0; }
static char_u *ml_get_cursor(void) { return NULL; }
static char_u *vim_strsave(char_u *str) { return NULL; }
static int ml_append(linenr_T lnum, char_u *line, colnr_T len, int newfile) { return 0; }
static void vim_free(void *ptr) {}
static char_u *ml_get_curline(void) { return NULL; }
static char_u *vim_strnsave(char_u *str, int len) { return NULL; }
static int ml_replace(linenr_T lnum, char_u *line, int copy) { return 0; }
static void semsg(char_u *msg, char_u *arg) {}
static char_u *transchar(int c) { return NULL; }
static int hasFolding(linenr_T lnum, linenr_T *firstp, linenr_T *lastp) { return 0; }
static int BUFEMPTY(void) { return 0; }
static int getviscol(void) { return 0; }
static int tabstop_padding(int col, int ts, int *vts) { return 0; }
static void coladvance_force(int col) {}
static void getvcol(win_T *wp, pos_T *pos, colnr_T *start, colnr_T *cursor, colnr_T *end) {}
static void init_chartabsize_arg(chartabsize_T *cts, win_T *win, linenr_T lnum, colnr_T col, char_u *line, char_u *line_head) {}
static int lbr_chartabsize_adv(chartabsize_T *cts) { return 0; }
static void clear_chartabsize_arg(chartabsize_T *cts) {}
static int lbr_chartabsize(chartabsize_T *cts) { return 0; }
static void emsg(char_u *msg) {}
static char_u *alloc(size_t size) { return NULL; }
static void mch_memmove(void *dest, void *src, size_t n) {}
static void vim_memset(void *s, int c, size_t n) {}
static void changed_lines(linenr_T lnum, long nlines, linenr_T newlnum, long xtra) {}
static char_u *ml_get(linenr_T lnum) { return NULL; }
static int getvpos(pos_T *pos, colnr_T col) { return 0; }
static void inserted_bytes(linenr_T lnum, colnr_T col, int len_added) {}
static void changed_cline_bef_curs(void) {}
static int preprocs_left(void) { return 0; }
static int set_indent(int indent, int flags) { return 0; }
static void mark_adjust(linenr_T line1, linenr_T line2, long amount, long amount_after) {}
static void beginline(int flags) {}
static void msgmore(long n) {}
static void adjust_cursor_eol(void) {}