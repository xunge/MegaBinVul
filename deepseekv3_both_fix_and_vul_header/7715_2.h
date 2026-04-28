#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

#define REG_MAXPROG 1000
#define REG_MAXSUB 10

typedef struct Reprog {
    int flags;
    int nsub;
    struct Reinst *start;
    struct Reinst *end;
} Reprog;

typedef struct Reinst {
    struct Reinst *x;
    struct Reinst *y;
    int op;
} Reinst;

typedef struct Renode {
    int type;
    struct Renode *x;
    struct Renode *y;
    int c;
    int n;
} Renode;

struct cstate {
    const char *source;
    const char *error;
    jmp_buf kaboom;
    Reprog *prog;
    Renode *pstart;
    Renode *pend;
    int ncclass;
    int nsub;
    int sub[REG_MAXSUB];
    int lookahead;
};

enum Inst {
    I_END,
    I_JUMP,
    I_SPLIT,
    I_ANYNL,
    I_LPAR,
    I_RPAR
};

#define EOF (-1)