#include <stddef.h>

typedef unsigned char lu_byte;
typedef unsigned int Instruction;

typedef struct Proto Proto;
typedef struct lua_State lua_State;
typedef struct CallInfo CallInfo;

struct Proto {
    int sizecode;
    const Proto *p;
};

typedef union {
    struct {
        Instruction *savedpc;
        int trap;
    } l;
} CallInfoUnion;

struct CallInfo {
    CallInfoUnion u;
    int callstatus;
    void *top;
    const Proto *p;
};

struct lua_State {
    CallInfo *ci;
    lu_byte hookmask;
    int hookcount;
    const Instruction *oldpc;
    int status;
    void *top;
};

#define LUA_MASKLINE  (1 << 0)
#define LUA_MASKCOUNT (1 << 1)
#define CIST_HOOKYIELD (1 << 0)
#define LUA_HOOKCOUNT  0
#define LUA_HOOKLINE   1
#define LUA_YIELD      1

static int pcRel(const Instruction *pc, const Proto *p) { return 0; }
static int invpcRel(int pc, const Proto *p) { return 0; }
static int changedline(const Proto *p, int oldpc, int newpc) { return 0; }
static int luaG_getfuncline(const Proto *p, int pc) { return 0; }
static void resethookcount(lua_State *L) {}
static void luaD_hook(lua_State *L, int event, int line, int f, int n) {}
static void luaD_throw(lua_State *L, int status) {}
static int isIT(Instruction inst) { return 0; }
static const Proto *ci_func(CallInfo *ci) { return ci->p; }