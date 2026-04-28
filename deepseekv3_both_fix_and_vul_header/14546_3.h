#include <string.h>
#include <stdlib.h>

typedef unsigned char char_u;
typedef long linenr_T;
typedef int colnr_T;

#define TRUE 1
#define FALSE 0
#define INSERT 1
#define TAB '\t'

struct pos {
    linenr_T lnum;
    colnr_T col;
};

typedef struct oparg_T {
    struct pos start;
    struct pos end;
    colnr_T end_vcol;
} oparg_T;

struct block_def {
    int is_short;
    int start_char_vcols;
    int startspaces;
    colnr_T textcol;
    int end_char_vcols;
    int endspaces;
    int textlen;
    int is_MAX;
    colnr_T end_vcol;
};

struct buf {
    struct pos b_op_end;
};

extern struct buf *curbuf;
extern int State;
extern int has_mbyte;
extern int (*mb_head_off)(char_u *, char_u *);
extern int (*mb_off_next)(char_u *, char_u *);

char_u *ml_get(linenr_T lnum);
void block_prep(oparg_T *oap, struct block_def *bdp, linenr_T lnum, int b_insert);
void *alloc(size_t size);
void mch_memmove(void *dest, const void *src, size_t n);
void vim_memset(void *s, int c, size_t n);
void ml_replace(linenr_T lnum, char_u *newp, int b_insert);
void inserted_bytes(linenr_T lnum, colnr_T startcol, unsigned s_len);
void changed_lines(linenr_T lnum, long count, linenr_T newlnum, long xtra);
#define STRLEN strlen
#define STRMOVE(dest, src) memmove((dest), (src), strlen(src) + 1)