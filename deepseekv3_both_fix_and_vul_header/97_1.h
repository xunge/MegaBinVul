#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define FAIL 1
#define OK 0
#define MAXLNUM 0x7fffffff
#define MAXCOL 0x7fffffff
#define NUL '\0'
#define TAB '\t'
#define NL '\n'

#define FORWARD 1
#define BACKWARD 0

#define MCHAR 0
#define MLINE 1
#define MBLOCK 2

#define PUT_FIXINDENT 0x01
#define PUT_CURSEND 0x02
#define PUT_LINE_SPLIT 0x04
#define PUT_LINE_FORWARD 0x08
#define PUT_LINE 0x10
#define PUT_BLOCK_INNER 0x20
#define PUT_CURSLINE 0x40
#define PUT_CURSEND 0x80

#define VE_ALL 0x01
#define CMOD_LOCKMARKS 0x01
#define BL_WHITE 0x01
#define BL_FIX 0x02

typedef unsigned char char_u;
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
    char_u **y_array;
} yankreg_T;

typedef struct block_def {
    int startspaces;
    int endspaces;
    colnr_T textcol;
} block_def;

typedef struct {
    pos_T vi_start;
    pos_T vi_end;
} visual_info_T;

typedef struct {
    pos_T b_op_start;
    pos_T b_op_end;
    visual_info_T b_visual;
    int b_p_ts;
    char_u *b_p_vts_array;
    struct {
        long ml_line_count;
    } b_ml;
} buf_T;

typedef struct {
    pos_T w_cursor;
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
extern int has_mbyte;
extern yankreg_T *y_current;

#define STRLEN(s) strlen((char *)(s))
#define STRCPY(d, s) strcpy((char *)(d), (char *)(s))
#define STRCAT(d, s) strcat((char *)(d), (char *)(s))
#define STRMOVE(d, s) memmove((d), (s), strlen((char *)(s)) + 1)
#define ALLOC_MULT(t, n) ((t *)malloc((n) * sizeof(t)))
#define MB_PTR_ADV(p) ((p) += has_mbyte ? (*mb_ptr2len)(p) : 1)

extern int hasFolding(linenr_T, linenr_T *, linenr_T *);
extern int get_ve_flags(void);
extern void adjust_clip_reg(int *);
extern int may_get_selection(int);
extern int get_indent(void);
extern void stuffcharReadbuff(int);
extern int stuff_inserted(int, long, int);
extern int gchar_cursor(void);
extern int get_spec_reg(int, char_u **, int *, int);
extern int u_save(linenr_T, linenr_T);
extern int u_save_cursor(void);
extern int ml_append(linenr_T, char_u *, colnr_T, int);
extern char_u *ml_get(linenr_T);
extern char_u *ml_get_cursor(void);
extern char_u *ml_get_curline(void);
extern void ml_replace(linenr_T, char_u *, int);
extern int lbr_chartabsize_adv(char_u *, char_u **, colnr_T);
extern int lbr_chartabsize(char_u *, char_u *, colnr_T);
extern int mb_ptr2len(char_u *);
extern int mb_head_off(char_u *, char_u *);
extern char_u *vim_strsave(char_u *);
extern char_u *vim_strnsave(char_u *, size_t);
extern char_u *vim_strchr(char_u *, int);
extern void changed_lines(linenr_T, long, linenr_T, long);
extern void changed_bytes(linenr_T, colnr_T);
extern void changed_cline_bef_curs(void);
extern void mark_adjust(linenr_T, linenr_T, long, long);
extern void beginline(int);
extern void adjust_cursor_eol(void);
extern void getvcol(win_T *, pos_T *, colnr_T *, colnr_T *, colnr_T *);
extern int getvpos(pos_T *, colnr_T);
extern void coladvance_force(colnr_T);
extern int getviscol(void);
extern int preprocs_left(void);
extern int set_indent(int, int);
extern void msgmore(long);
extern void emsg(char *);
extern void semsg(char *, char_u *);
extern char_u *transchar(int);
extern char_u *_(char *);
extern void get_yank_register(int, int);
extern char_u *alloc(size_t);
extern char_u *alloc_clear(size_t);
extern void vim_free(void *);
extern void vim_memset(void *, int, size_t);
extern void mch_memmove(void *, void *, size_t);
extern int tabstop_padding(int, int, char_u *);
extern int BUFEMPTY(void);

static const char e_nothing_in_register_str[] = "Nothing in register";
static const char e_resulting_text_too_long[] = "Resulting text too long";
static const char e_yank_register_changed_while_using_it[] = "Yank register changed while using it";