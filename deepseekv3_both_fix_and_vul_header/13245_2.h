#include <stddef.h>

#define LUA_MULTRET (-1)

typedef struct TValue {
    int tt_;
    void *p;
} TValue;

typedef struct lua_State {
    TValue *top;
    TValue *stack_last;
} lua_State;

typedef struct {
    void *savedpc;
} LClosureInfo;

typedef struct CallInfo {
    TValue *func;
    TValue *top;
    union {
        LClosureInfo l;
    } u;
    int callstatus;
} CallInfo;

typedef TValue *StkId;

typedef struct Proto {
    int maxstacksize;
    int numparams;
    void *code;
} Proto;

typedef union {
    struct {
        Proto *p;
    } l;
    void *p;
    int (*f)(lua_State *);
} LClosure;

typedef struct CClosure {
    int (*f)(lua_State *);
} CClosure;

typedef int (*lua_CFunction)(lua_State *L);

typedef enum {
    LUA_VNIL,
    LUA_VFALSE,
    LUA_VTRUE,
    LUA_VLIGHTUSERDATA,
    LUA_VNUMFLT,
    LUA_VNUMINT,
    LUA_VSHRSTR,
    LUA_VLNGSTR,
    LUA_VTABLE,
    LUA_VUSERDATA,
    LUA_VTHREAD,
    LUA_VLCF,
    LUA_VCCL,
    LUA_VLCL
} TType;

#define CIST_TAIL (1<<0)

#define s2v(o) (o)
#define ttypetag(o) (((TValue*)(o))->tt_)
#define clCvalue(o) ((CClosure *)((o)->p))
#define clLvalue(o) ((LClosure *)((o)->p))
#define fvalue(o) ((lua_CFunction)((o)->p))
#define setobjs2s(L,x,y) (*(x) = *(y))
#define setnilvalue(x) ((x)->tt_ = LUA_VNIL)
#define checkstackGC(L,n) (void)0
#define lua_assert(c) (void)0

int precallC(lua_State *L, StkId func, int nresults, lua_CFunction f);
StkId luaD_tryfuncTM(lua_State *L, StkId func);