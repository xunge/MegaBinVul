#include <string.h>
#include <stdlib.h>

typedef unsigned char char_u;
typedef long linenr_T;
typedef int colnr_T;

struct block_def {
    int start_char_vcols;
    int end_char_vcols;
    int startspaces;
    int endspaces;
    int is_short;
    int is_MAX;
    colnr_T textcol;
    int textlen;
    colnr_T end_vcol;
};

struct oparg {
    struct {
        linenr_T lnum;
        colnr_T col;
    } start, end;
    colnr_T end_vcol;
};

typedef struct oparg oparg_T;

struct buf {
    struct {
        linenr_T lnum;
        colnr_T col;
    } b_op_end;
};

extern struct buf *curbuf;

#define STRLEN strlen
#define TRUE 1
#define FALSE 0
#define TAB '\t'

enum {
    INSERT,
    REPLACE
};
extern int State;

extern void block_prep(oparg_T *oap, struct block_def *bdp, linenr_T lnum, int prep);
extern char_u *ml_get(linenr_T lnum);
extern int has_mbyte;
extern int (*mb_head_off)(char_u *p, char_u *s);
extern void *alloc(size_t size);
extern void mch_memmove(void *dest, const void *src, size_t n);
extern void vim_memset(void *s, int c, size_t n);
extern void ml_replace(linenr_T lnum, char_u *newp, int copy);
extern void inserted_bytes(linenr_T lnum, colnr_T col, unsigned len);
extern void changed_lines(linenr_T lnum, long n, linenr_T lnum2, long n2);
#define STRMOVE(d, s) memmove(d, s, strlen(s) + 1)