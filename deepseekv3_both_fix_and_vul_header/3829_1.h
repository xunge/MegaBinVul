#include <assert.h>

typedef struct global_State {
    int gckind;
} global_State;

typedef struct lua_State {
    global_State *l_G;
} lua_State;

typedef struct GCObject GCObject;

#define G(L) ((L)->l_G)
#define lua_assert assert
#define isblack(o) (0)
#define iswhite(v) (0)
#define isdead(g, v) (0)
#define keepinvariant(g) (0)
#define reallymarkobject(g, v)
#define isold(o) (0)
#define setage(v, a)
#define issweepphase(g) (0)
#define makewhite(g, o)
#define KGC_INC 0
#define G_OLD0 0