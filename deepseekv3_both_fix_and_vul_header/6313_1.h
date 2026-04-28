#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef long linenr_T;
typedef unsigned char char_u;
typedef int colnr_T;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define NOT_VALID 0
#define OPT_FREE 0
#define OPT_LOCAL 0
#define NUL '\0'

#define FEAT_VARTABS

typedef struct {
    char_u *arg;
    linenr_T line1;
    linenr_T line2;
    int forceit;
} exarg_T;

typedef struct {
    int w_p_list;
    colnr_T w_curswant;
} win_T;

typedef struct {
    int b_p_ts;
    int b_p_et;
    int *b_p_vts_array;
    struct {
        char_u *ml_line_ptr;
    } b_ml;
} buf_T;

extern buf_T *curbuf;
extern win_T *curwin;
extern int got_int;
extern int has_mbyte;

#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define STRLEN(s) strlen((const char *)(s))
#define mch_memmove memmove
#define _(s) s
#define e_interr "Interrupted"
#define e_positive "Positive number required"

int tabstop_set(char_u *arg, int **array);
int vim_isdigit(int c);
char_u *vim_strnsave(char_u *str, size_t len);
int getdigits(char_u **pp);
void emsg(char *msg);
int u_save(linenr_T start, linenr_T end);
char_u *alloc(size_t size);
int ml_replace(linenr_T lnum, char_u *line, int copy);
int chartabsize(char_u *p, colnr_T col);
int (*mb_ptr2len)(char_u *p);
void line_breakcheck(void);
void redraw_curbuf_later(int flags);
void changed_lines(linenr_T first, linenr_T last, linenr_T extra, long count);
void set_string_option_direct(char_u *name, int opt_flags, char_u *val, int opt_type, int opt_dir);
void coladvance(colnr_T wcol);
void u_clearline(void);
void vim_free(void *ptr);

char_u *ml_get(linenr_T lnum);

int tabstop_count(int *array);
int tabstop_first(int *array);
int tabstop_eq(int *array1, int *array2);
void tabstop_fromto(long start, long end, int ts, int *vts, int *tabs, int *spaces);