#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

#define MAXSUB 10

typedef struct Reprog Reprog;
typedef struct Renode Renode;
typedef struct Reinst Reinst;
typedef struct cstate cstate;

enum {
    I_END,
    I_JUMP,
    I_SPLIT,
    I_LPAR,
    I_RPAR,
    I_ANYNL
};

struct Reinst {
    int type;
    Reinst *x;
    Reinst *y;
};

struct Reprog {
    int flags;
    int nsub;
    Reinst *start;
    Reinst *end;
};

struct Renode {
    int type;
    Renode *x;
    Renode *y;
    int c;
    int ng;
    int m;
    int n;
};

struct cstate {
    Reprog *prog;
    Renode *pstart;
    Renode *pend;
    const char *source;
    const char *error;
    int ncclass;
    int nsub;
    int sub[MAXSUB];
    int lookahead;
    jmp_buf kaboom;
};

static void *default_alloc;