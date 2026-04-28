#include <stddef.h>

typedef struct pos_T pos_T;
typedef struct xfmark_T xfmark_T;
typedef struct fmark_T fmark_T;
typedef struct win_T win_T;
typedef struct buf_T buf_T;

#define TRUE 1
#define FALSE 0
#define FAIL (-1)

struct pos_T {
    int lnum;
};

struct fmark_T {
    pos_T mark;
    int fnum;
};

struct xfmark_T {
    fmark_T fmark;
};

struct win_T {
    xfmark_T *w_jumplist;
    int w_jumplistlen;
    int w_jumplistidx;
    pos_T w_cursor;
};

struct buf_T {
    int b_fnum;
};

extern win_T *curwin;
extern buf_T *curbuf;

void cleanup_jumplist(win_T *win, int flag);
void setpcmark(void);
buf_T *buflist_findnr(int fnum);
int buflist_getfile(int fnum, int lnum, int forceit, int set_curr);
void fname2fnum(xfmark_T *jmp);