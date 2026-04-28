#include <limits.h>
#include <stddef.h>
#include <string.h>

typedef unsigned char char_u;
typedef long linenr_T;
typedef int colnr_T;

#define FAIL 1
#define FORWARD 1
#define BACKWARD 0
#define TRUE 1
#define FALSE 0
#define NUL '\0'
#define MAXCOL 1000
#define MAXLNUM 1000
#define MLINE 1
#define MCHAR 2
#define MBLOCK 3
#define VE_ALL 1
#define TAB '\t'
#define OK 1
#define BL_WHITE 1
#define BL_FIX 2

#define PUT_FIXINDENT 1
#define PUT_CURSEND 2
#define PUT_LINE_SPLIT 4
#define PUT_LINE_FORWARD 8
#define PUT_LINE 16
#define PUT_BLOCK_INNER 32
#define PUT_CURSLINE 64
#define CMOD_LOCKMARKS 1

#define _(x) x
#define e_nothing_in_register_str "Nothing in register"
#define e_resulting_text_too_long "Resulting text too long"
#define e_yank_register_changed_while_using_it "Yank register changed while using it"

struct block_def {
    int startspaces;
    int endspaces;
    colnr_T textcol;
};

typedef struct {
    int y_type;
    long y_width;
    long y_size;
    char_u **y_array;
} yankreg_T;

typedef struct {
    linenr_T lnum;
    colnr_T col;
    int coladd;
} pos_T;

typedef struct {
    pos_T b_op_start;
    pos_T b_op_end;
    struct {
        pos_T vi_start;
        pos_T vi_end;
    } b_visual;
    struct {
        long ml_line_count;
    } b_ml;
    int b_p_ts;
    char_u *b_p_vts_array;
} buf_T;

typedef struct {
    pos_T w_cursor;
    buf_T *b_visual;
    int w_p_diff;
    int w_set_curswant;
} win_T;

typedef struct {
    int cmod_flags;
} cmdmod_T;

extern buf_T *curbuf;
extern win_T *curwin;
extern cmdmod_T cmdmod;
extern int VIsual_active;
extern int VIsual_mode;
extern int restart_edit;
extern yankreg_T *y_current;

#define STRLEN(s) strlen((const char *)(s))
#define STRCPY(d, s) strcpy((char *)(d), (const char *)(s))
#define STRCAT(d, s) strcat((char *)(d), (const char *)(s))
#define STRMOVE(d, s) memmove((d), (s), strlen((const char *)(s)) + 1)
#define ALLOC_MULT(type, count) ((type *)malloc(sizeof(type) * (count)))
#define MB_PTR_ADV(p) (p += has_mbyte ? (*mb_ptr2len)(p) : 1)

typedef struct {
    int cts_vcol;
    char_u *cts_ptr;
    win_T *cts_win;
    linenr_T cts_lnum;
    colnr_T cts_col;
    char_u *cts_line;
    char_u *cts_linep;
} chartabsize_T;

int has_mbyte;
int (*mb_ptr2len)(char_u *p);
int (*mb_head_off)(char_u *base, char_u *p);

char_u *ml_get(linenr_T lnum);
char_u *ml_get_cursor();
char_u *ml_get_curline();
int ml_append(linenr_T lnum, char_u *line, colnr_T col, int newfile);
void ml_replace(linenr_T lnum, char_u *line, int has_props);
void changed_lines(linenr_T lnum, colnr_T col, linenr_T lnume, long xtra);
void adjust_clip_reg(int *regname);
int may_get_selection(int regname);
void stuffcharReadbuff(int c);
void stuff_inserted(int c, int count, int no_esc);
int gchar_cursor();
int get_indent();
int u_save(linenr_T start, linenr_T end);
int u_save_cursor();
int get_spec_reg(int regname, char_u **argp, int *allocated, int regname_to_upper);
void get_yank_register(int regname, int writing);
int get_ve_flags();
void coladvance_force(int pos);
int getviscol();
int lbr_chartabsize(chartabsize_T *cts);
int lbr_chartabsize_adv(chartabsize_T *cts);
void init_chartabsize_arg(chartabsize_T *cts, win_T *wp, linenr_T lnum, colnr_T col, char_u *line, char_u *linep);
void clear_chartabsize_arg(chartabsize_T *cts);
int getvpos(pos_T *pos, colnr_T vcol);
void getvcol(win_T *wp, pos_T *pos, colnr_T *startcol, colnr_T *cursor_col, colnr_T *endcol);
int hasFolding(linenr_T lnum, linenr_T *firstp, linenr_T *lastp);
int preprocs_left();
int set_indent(int indent, int flags);
void mark_adjust(linenr_T line1, linenr_T line2, long amount, linenr_T amount_after);
void beginline(int flags);
void adjust_cursor_eol();
void inserted_bytes(linenr_T lnum, colnr_T col, long len);
void changed_cline_bef_curs();
void msgmore(long n);
char_u *vim_strsave(char_u *string);
char_u *vim_strnsave(char_u *string, size_t len);
char_u *vim_strchr(char_u *string, int c);
char_u *alloc(size_t size);
void vim_free(void *ptr);
void mch_memmove(void *dest, const void *src, size_t len);
void vim_memset(void *s, int c, size_t len);
void emsg(char_u *s);
void semsg(char_u *s, char_u *arg);
int BUFEMPTY();
char_u *transchar(int c);
int tabstop_padding(int viscol, int ts, char_u *vts_array);