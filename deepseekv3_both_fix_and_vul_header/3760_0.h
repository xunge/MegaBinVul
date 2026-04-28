#include <stddef.h>

typedef struct lua_State lua_State;
typedef struct global_State global_State;
typedef struct GCObject GCObject;

#define GCSpropagate 0

struct global_State {
    int gcstate;
    GCObject *allgc;
    GCObject *survival;
    GCObject *reallyold;
    GCObject *finobj;
    GCObject *finobjrold;
    GCObject *finobjsur;
    GCObject *finobjold;
    GCObject *tobefnz;
    GCObject *old;
};

static void markold(global_State *g, GCObject *from, GCObject *to) {}
static void atomic(lua_State *L) {}
static GCObject **sweepgen(lua_State *L, global_State *g, GCObject **p, GCObject *limit) { return NULL; }
static void finishgencycle(lua_State *L, global_State *g) {}
#define lua_assert(cond) ((void)0)