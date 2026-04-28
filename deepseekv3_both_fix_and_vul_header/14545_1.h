#include <stddef.h>

typedef unsigned char char_u;
typedef long linenr_T;
typedef int colnr_T;

typedef struct {
    int col;
    int coladd;
    linenr_T lnum;
} pos_T;

typedef struct {
    pos_T start;
    pos_T end;
    int start_vcol;
    int end_vcol;
    int op_type;
    int block_mode;
} oparg_T;

typedef struct block_def {
    int textcol;
    int textlen;
    int start_vcol;
    int endspaces;
    int is_short;
    int is_MAX;
} block_def;

typedef struct {
    pos_T w_cursor;
    int w_curswant;
    int w_ve_flags;
    int w_set_curswant;
} win_T;

typedef struct {
    pos_T b_op_start_orig;
    pos_T b_op_start;
} buf_T;

extern win_T *curwin;
extern buf_T *curbuf;
extern pos_T Insstart;
extern int got_int;

#define MAXCOL 1000
#define FAIL 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define NUL '\0'
#define VE_ALL 0
#define INVERTED 0
#define OP_INSERT 0
#define OP_APPEND 1

#define LT_POS(a, b) ((a).lnum < (b).lnum || ((a).lnum == (b).lnum && (a).col < (b).col))
#define LINEEMPTY(lnum) (0)
#define STRLEN(s) strlen((const char *)(s))

void update_screen(int flags);
int u_save_cursor(void);
int getviscol(void);
void coladvance_force(int col);
void block_prep(oparg_T *oap, block_def *bd, linenr_T lnum, int prep);
int getwhitecols_curline(void);
int get_indent(void);
char_u *ml_get(linenr_T lnum);
char_u *ml_get_cursor(void);
void ins_char(int c);
int edit(int c, int startln, linenr_T count);
void check_cursor_col(void);
void inc_cursor(void);
int getviscol2(int col, int coladd);
char_u *vim_strnsave(const char_u *str, long len);
int u_save(linenr_T start, linenr_T end);
void block_insert(oparg_T *oap, char_u *str, int insert, block_def *bd);
void check_cursor(void);
void vim_free(void *ptr);
size_t strlen(const char *s);