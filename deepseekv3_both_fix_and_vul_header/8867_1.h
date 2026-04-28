#include <limits.h>

#define REPINF INT_MAX
#define MAXPROG 1000

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

static void die(struct cstate *g, const char *msg);