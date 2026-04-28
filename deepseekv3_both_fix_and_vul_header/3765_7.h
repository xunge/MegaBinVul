#include <stddef.h>

typedef ptrdiff_t StkId;
typedef double lua_Number;
typedef int (*lua_CFunction)(void);

typedef struct lua_State lua_State;
typedef struct CallInfo CallInfo;
typedef struct Proto Proto;
typedef struct LClosure LClosure;
typedef struct TValue TValue;

struct lua_State {
    StkId stack;
    StkId top;
    unsigned int hookmask;
    ptrdiff_t oldpc;
};

struct CallInfo {
    StkId func;
    StkId top;
    CallInfo *previous;
    union {
        struct {
            ptrdiff_t savedpc;
            int nextraargs;
        } l;
    } u;
    unsigned short callstatus;
};

struct Proto {
    unsigned char is_vararg;
    int numparams;
};

struct LClosure {
    Proto *p;
};

struct TValue {
    unsigned int tt_;
    union {
        void *p;
        int b;
        lua_Number n;
        lua_CFunction f;
        LClosure *cl;
    } value_;
};

#define LUA_MASKRET (1 << 4)
#define LUA_HOOKRET 2
#define CIST_LUA (1 << 0)
#define savestack(L,o) ((ptrdiff_t)((o) - (L)->stack))
#define restorestack(L,o) ((L)->stack + (o))
#define isLuacode(ci) ((ci)->callstatus & CIST_LUA)
#define isLua(ci) ((ci)->callstatus & CIST_LUA)
#define ci_func(ci) (clLvalue(s2v((ci)->func)))
#define clLvalue(o) ((LClosure *)(o))
#define s2v(o) ((TValue *)(o))
#define cast(t, exp) ((t)(exp))

void luaD_hook(lua_State *L, int event, int line, int ftransfer, int nres);
ptrdiff_t pcRel(ptrdiff_t pc, Proto *p);