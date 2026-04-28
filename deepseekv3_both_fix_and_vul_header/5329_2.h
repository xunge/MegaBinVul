#include <stddef.h>

#define MAXSUB 10

typedef struct Resub {
    int nsub;
    struct {
        const char *sp;
        const char *ep;
    } sub[MAXSUB];
} Resub;

typedef struct Reprog {
    int nsub;
    int flags;
    void *start;
} Reprog;

extern int match(void *start, const char *sp, const char *orig, int flags, Resub *sub, ...);