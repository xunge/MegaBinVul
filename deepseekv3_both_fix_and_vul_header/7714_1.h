#include <stdlib.h>

#define REG_MAXREC 1000
#define REG_MAXPROG 10000
#define REPINF 1000000

struct cstate;

typedef struct Renode {
    int type;
    int m;
    int n;
    struct Renode *x;
    struct Renode *y;
} Renode;

enum {
    P_CAT,
    P_ALT,
    P_REP,
    P_PAR,
    P_PLA,
    P_NLA
};

void die(struct cstate *g, const char *msg);