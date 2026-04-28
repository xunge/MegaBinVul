#include <stddef.h>
#include <string.h>

typedef int linenr_T;
typedef int colnr_T;
typedef unsigned char char_u;
typedef int bool;

#define FALSE 0
#define TRUE 1
#define OK 1
#define FAIL 0
#define NUL '\0'
#define TAB '\t'
#define CAR '\r'
#define NL '\n'
#define MAXCOL 2147483647
#define REPLACE_CR_NCHAR 0x1000
#define REPLACE_NL_NCHAR 0x1001
#define ML_EMPTY 1
#define MLINE 1

typedef struct {
    linenr_T lnum;
    colnr_T col;
    int coladd;
} pos_T;

typedef struct {
    bool block_mode;
    bool empty;
    int motion_type;
    bool inclusive;
    pos_T start;
    pos_T end;
    colnr_T start_vcol;
    colnr_T end_vcol;
    pos_T start_vcol_pos;
    pos_T end_vcol_pos;
} oparg_T;

struct block_def {
    bool is_MAX;
    bool is_short;
    bool is_oneChar;
    int textlen;
    int textcol;
    int startspaces;
    int endspaces;
    int start_char_vcols;
    int end_char_vcols;
    colnr_T end_vcol;
    char_u *textstart;
};

struct window {
    pos_T w_cursor;
    colnr_T w_curswant;
};

struct buf_T {
    struct {
        int ml_flags;
    } b_ml;
    pos_T b_op_start;
    pos_T b_op_end;
};

struct cmdmod_T {
    int cmod_flags;
#define CMOD_LOCKMARKS 1
};

extern struct window *curwin;
extern struct buf_T *curbuf;
extern bool has_mbyte;
extern bool virtual_op;
extern struct cmdmod_T cmdmod;

#define LTOREQ_POS(a, b) ((a).lnum < (b).lnum || \
                         ((a).lnum == (b).lnum && (a).col <= (b).col))

int (*mb_char2cells)(int);
int (*mb_char2len)(int);
int (*mb_char2bytes)(int, char_u *);

void mb_adjust_opend(oparg_T *oap);
int u_save(linenr_T start, linenr_T end);
void block_prep(oparg_T *oap, struct block_def *bd, linenr_T lnum, bool prep);
char_u *ml_get_curline(void);
char_u *ml_get(linenr_T lnum);
char_u *ml_get_cursor(void);
void ml_replace(linenr_T lnum, char_u *newp, bool copy);
void ml_append(linenr_T lnum, char_u *newp, int flags, bool newfile);
void appended_lines_mark(linenr_T lnum, long count);
void *alloc(size_t size);
void vim_free(void *ptr);
void vim_memset(void *s, int c, size_t n);
void *mch_memmove(void *dest, const void *src, size_t n);
int gchar_cursor(void);
int mb_ptr2len(const char_u *p);
void replace_character(int c);
void PBYTE(pos_T pos, int c);
int getviscol(void);
int getviscol2(colnr_T col, int coladd);
void getvpos(pos_T *vpos, colnr_T col);
void coladvance_force(int col);
int inc_cursor(void);
int inc(pos_T *pos);
void dec(pos_T *pos);
void check_cursor(void);
void changed_lines(linenr_T lnum, colnr_T col, linenr_T end_lnum, long count);
#define STRLEN strlen
#define STRMOVE(dest, src) memmove((dest), (src), strlen(src) + 1)