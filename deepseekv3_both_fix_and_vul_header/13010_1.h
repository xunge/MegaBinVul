#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char char_u;
typedef long linenr_T;
typedef int colnr_T;

typedef struct {
    linenr_T lnum;
    colnr_T col;
    int coladd;
} pos_T;

typedef struct {
    int motion_type;
    int line_count;
    pos_T start;
    pos_T end;
    int regname;
    int inclusive;
    int is_VIsual;
    int block_mode;
    colnr_T start_vcol;
    colnr_T end_vcol;
    int excl_tr_ws;
} oparg_T;

typedef struct {
    char_u **y_array;
    long y_size;
    int y_type;
    int y_width;
    long y_time_set;
} yankreg_T;

typedef struct block_def {
    char_u *textstart;
    long textlen;
    int startspaces;
    int endspaces;
} block_def;

typedef struct {
    int w_curswant;
} win_T;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define MAXCOL 0x7FFFFFFF
#define NUL '\0'
#define MCHAR 1
#define MLINE 2
#define MBLOCK 3
#define CPO_REGAPPEND 'r'
#define STAR_REGISTER 0
#define PLUS_REGISTER 1
#define CLIP_UNNAMED 1
#define CLIP_UNNAMED_PLUS 2
#define CMOD_LOCKMARKS 0x01

#define STRLEN(s) strlen((const char *)(s))
#define STRCPY(d, s) strcpy((char *)(d), (const char *)(s))
#define STRCAT(d, s) strcat((char *)(d), (const char *)(s))
#define ALLOC_MULT(type, count) ((type *)malloc(sizeof(type) * (count)))

extern yankreg_T *y_current;
extern int y_append;
extern char *p_sel;
extern int virtual_op;
extern char *p_cpo;
extern int p_report;
extern yankreg_T y_regs[];
extern struct {
    int available;
} clip_star, clip_plus;
extern int clip_unnamed;
extern int clip_unnamed_saved;
extern struct {
    int cmod_flags;
} cmdmod;
extern struct {
    pos_T b_op_start;
    pos_T b_op_end;
} *curbuf;
extern win_T *curwin;

extern int valid_yank_reg(int, int);
extern void beep_flush(void);
extern void get_yank_register(int, int);
extern void free_yank_all(void);
extern long vim_time(void);
extern char_u *ml_get(linenr_T);
extern char_u *vim_strsave(char_u *);
extern void getvcol(win_T *, pos_T *, colnr_T *, colnr_T *, colnr_T *);
extern int (*mb_head_off)(char_u *, char_u *);
extern char_u *alloc(size_t);
extern void vim_free(void *);
extern void block_prep(oparg_T *, block_def *, linenr_T, int);
extern int yank_copy_line(block_def *, long, int);
extern char_u *lalloc_clear(size_t, int);
extern void update_topline_redraw(void);
extern void smsg(const char *, ...);
extern void vim_snprintf(char *, size_t, const char *, ...);
extern char *NGETTEXT(const char *, const char *, unsigned long);
extern char *_(const char *);
extern void copy_yank_reg(yankreg_T *);
extern void clip_own_selection(void *);
extern void clip_gen_set_selection(void *);
extern int clip_isautosel_star(void);
extern int clip_isautosel_plus(void);
extern int has_textyankpost(void);
extern void yank_do_autocmd(oparg_T *, yankreg_T *);
extern char *vim_strchr(const char *, int);
extern void free_yank(long);