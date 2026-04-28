#include <stddef.h>

typedef struct lua_State lua_State;
typedef struct global_State global_State;

enum {
    GCSswpallgc,
    KGC_GEN
};

struct global_State {
    int gcstate;
    int gckind;
    unsigned int lastatomic;
    size_t GCestimate;
    void *allgc;
    void *finobj;
    void *tobefnz;
    void *survival;
    void *old;
    void *reallyold;
    void *finobjsur;
    void *finobjold;
    void *finobjrold;
};

void sweep2old(lua_State *L, void **list);
size_t gettotalbytes(global_State *g);
void finishgencycle(lua_State *L, global_State *g);