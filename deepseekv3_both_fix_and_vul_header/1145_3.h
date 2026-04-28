#include <stddef.h>
#include <string.h>

typedef long linenr_T;
typedef unsigned char char_u;
typedef int colnr_T;

#define FALSE 0
#define TRUE 1
#define FAIL 1
#define OK 0
#define MAXCOL 1000
#define TABSTOP_MAX 100
#define NOT_VALID 0
#define OPT_FREE 0
#define OPT_LOCAL 0
#define FEAT_VARTABS
#define NUL '\0'

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

#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define STRLEN(s) strlen((char *)(s))
#define chartabsize(p, v) 1
#define has_mbyte 0
#define mb_ptr2len(p) 1

int tabstop_set(char_u *arg, int **array);
int vim_isdigit(int c);
char_u *vim_strnsave(char_u *str, size_t len);
int getdigits(char_u **pp);
void emsg(const char *msg);
void semsg(const char *msg, char_u *arg);
char_u *ml_get(linenr_T lnum);
int u_save(linenr_T lnum1, linenr_T lnum2);
void *alloc(size_t size);
void mch_memmove(void *dest, const void *src, size_t n);
int ml_replace(linenr_T lnum, char_u *new_line, int copy);
void redraw_curbuf_later(int flags);
void changed_lines(linenr_T first, linenr_T last, linenr_T extra, long count);
void set_string_option_direct(char_u *name, int opt_flags, char_u *val, int opt_type, int opt_dir);
void vim_free(void *ptr);
void coladvance(colnr_T wcol);
void u_clearline(void);
void line_breakcheck(void);
int tabstop_count(int *array);
int tabstop_first(int *array);
int tabstop_eq(int *array1, int *array2);
void tabstop_fromto(long start, long end, int ts, int *vts, int *tabs, int *spaces);

const char *e_argument_must_be_positive;
const char *e_invalid_argument_str;
const char *e_interrupted;
const char *e_resulting_text_too_long;

#define _(x) x

int (*mb_ptr2len)(const char_u *p);