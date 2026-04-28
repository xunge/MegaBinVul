#include <stddef.h>

typedef struct GCObject {
    int tt;
    struct GCObject *gclist;
} GCObject;

typedef struct lua_State {
    struct GCObject *gclist;
} lua_State;

#define LUA_VTABLE 1
#define LUA_VUSERDATA 2
#define LUA_VTHREAD 3

#define G_TOUCHED1 1
#define G_TOUCHED2 2
#define G_OLD 3

static GCObject **getgclist(GCObject *o) { return &o->gclist; }
static int getage(GCObject *o) { return 0; }
static int isgray(GCObject *o) { return 0; }
static int iswhite(GCObject *o) { return 0; }
static int isblack(GCObject *o) { return 0; }
static int isold(GCObject *o) { return 0; }
static void gray2black(GCObject *o) {}
static void changeage(GCObject *o, int from, int to) {}
static lua_State *gco2th(GCObject *o) { return (lua_State*)o; }
static void lua_assert(int condition) {}