#include <stddef.h>

#define LUA_API extern

typedef struct lua_State lua_State;
typedef void (*lua_Hook)(lua_State *L);
typedef struct CallInfo CallInfo;

struct lua_State {
    lua_Hook hook;
    int basehookcount;
    unsigned char hookmask;
    CallInfo *ci;
    const void *oldpc;
};

struct CallInfo {
    union {
        struct {
            const void *savedpc;
        } l;
    } u;
};

#define cast_byte(x) ((unsigned char)(x))

static int isLua(CallInfo *ci) { return 0; }
static void resethookcount(lua_State *L) {}
static void settraps(CallInfo *ci) {}