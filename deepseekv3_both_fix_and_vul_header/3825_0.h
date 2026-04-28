#include <stddef.h>

typedef struct lua_State lua_State;
typedef struct global_State global_State;
typedef struct GCObject GCObject;

enum {
    GCSpropagate,
    GCSswpallgc
};

struct global_State {
    int gcstate;
    GCObject *allgc;
    GCObject *reallyold;
    GCObject *finobj;
    GCObject *finobjrold;
    GCObject *survival;
    GCObject *old;
    GCObject *finobjsur;
    GCObject *finobjold;
    GCObject *tobefnz;
};

static void markold(global_State *g, GCObject *from, GCObject *to);
static void atomic(lua_State *L);
static GCObject **sweepgen(lua_State *L, global_State *g, GCObject **p, GCObject *limit);
static void finishgencycle(lua_State *L, global_State *g);