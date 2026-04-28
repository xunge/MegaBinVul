#include <setjmp.h>
#include <string.h>

#define MAXSUB 10
#define MAXPROG 1000

typedef struct Reprog Reprog;
typedef struct Reinst Reinst;
typedef struct Renode Renode;

struct Reinst {
    int opcode;
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
    int n;
    int ng;
};

struct cstate {
    jmp_buf kaboom;
    const char *error;
    Renode *pstart;
    Renode *pend;
    Reprog *prog;
    const char *source;
    int ncclass;
    int nsub;
    int sub[MAXSUB];
    int lookahead;
};

enum {
    I_END,
    I_JUMP,
    I_SPLIT,
    I_ANYNL,
    I_LPAR,
    I_RPAR
};