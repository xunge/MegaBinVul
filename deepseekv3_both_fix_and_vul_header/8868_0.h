#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

#define MAXSUB 10
#define MAXPROG 1000

typedef enum {
    I_END,
    I_JUMP,
    I_SPLIT,
    I_ANYNL,
    I_LPAR,
    I_RPAR
} Reinsttype;

typedef struct Reinst {
    Reinsttype type;
    struct Reinst *x;
    struct Reinst *y;
} Reinst;

typedef struct Reprog {
    int flags;
    int nsub;
    Reinst *start;
    Reinst *end;
} Reprog;

typedef struct Renode {
    int type;
    struct Renode *x;
    struct Renode *y;
    int c;
    int n;
} Renode;

typedef struct cstate {
    jmp_buf kaboom;
    const char *error;
    const char *source;
    Renode *pstart;
    Renode *pend;
    Reprog *prog;
    int ncclass;
    int nsub;
    int sub[MAXSUB];
    int lookahead;
} cstate;