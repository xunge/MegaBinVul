#include <stddef.h>
#include <string.h>

typedef long linenr_T;
typedef unsigned char char_u;
typedef int colnr_T;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define NOT_VALID 0
#define FEAT_VARTABS
#define NUL '\0'
#define OPT_FREE 0
#define OPT_LOCAL 0

#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define STRLEN(s) strlen((char *)(s))

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

extern win_T *curwin;
extern buf_T *curbuf;
extern int got_int;
extern int has_mbyte;

int tabstop_set(char_u *arg, int **array);
int vim_isdigit(int c);
char_u *vim_strnsave(char_u *str, size_t len);
void emsg(const char *msg);
void semsg(const char *msg, char_u *arg);
char_u *ml_get(linenr_T lnum);
int u_save(linenr_T start, linenr_T end);
void *alloc(size_t size);
void mch_memmove(void *dest, const void *src, size_t n);
int ml_replace(linenr_T lnum, char_u *new_line, int copy);
int chartabsize(char_u *p, colnr_T col);
int (*mb_ptr2len)(char_u *p);
void line_breakcheck(void);
void redraw_curbuf_later(int type);
void changed_lines(linenr_T first, linenr_T last, linenr_T extra, long count);
void set_string_option_direct(char_u *name, int opt_idx, char_u *val, int opt_flags, int set_sid);
int tabstop_count(int *array);
int tabstop_first(int *array);
int tabstop_eq(int *array1, int *array2);
void tabstop_fromto(int start, int end, int ts, int *vts, int *tabs, int *spaces);
void coladvance(colnr_T wcol);
void u_clearline(void);
void vim_free(void *ptr);
int getdigits(char_u **pp);

extern const char *e_interrupted;
extern const char *e_argument_must_be_positive;
extern const char *e_invalid_argument_str;