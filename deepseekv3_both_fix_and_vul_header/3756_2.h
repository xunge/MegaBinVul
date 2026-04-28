#include <stddef.h>
#include <assert.h>

typedef struct TValue {
    int tt_;
    union {
        void *p;
        int b;
        double n;
        struct {
            int (*f)(void *L);
        } cf;
    } value_;
} TValue;

typedef TValue *StkId;

typedef struct CallInfo {
    StkId func;
    StkId top;
    int nresults;
    int callstatus;
    union {
        struct {
            unsigned int *savedpc;
        } l;
    } u;
} CallInfo;

typedef struct Proto {
    int numparams;
    int maxstacksize;
    unsigned int *code;
} Proto;

typedef struct CClosure {
    int (*f)(void *L);
} CClosure;

typedef struct LClosure {
    Proto *p;
} LClosure;

typedef union Closure {
    CClosure c;
    LClosure l;
} Closure;

typedef struct lua_State {
    StkId top;
    StkId stack_last;
    CallInfo *ci;
    unsigned char hookmask;
} lua_State;

typedef int (*lua_CFunction)(lua_State *L);

#define LUA_VCCL 1
#define LUA_VLCF 2
#define LUA_VLCL 3
#define LUA_MINSTACK 20
#define CIST_C 1
#define LUA_MASKCALL 1
#define LUA_HOOKCALL 0

#define ttypetag(o) ((o)->tt_)
#define s2v(o) (o)
#define clCvalue(o) (&((Closure *)((o)->value_.p))->c)
#define fvalue(o) ((o)->value_.cf.f)
#define clLvalue(o) (&((Closure *)((o)->value_.p))->l)
#define setnilvalue(o) ((o)->tt_ = 0)
#define cast_int(i) (i)
#define lua_assert(c) assert(c)

void luaD_hook(lua_State *L, int event, int line, int ar, int nparams);
void lua_unlock(lua_State *L);
void lua_lock(lua_State *L);
void api_checknelems(lua_State *L, int n);
void luaD_poscall(lua_State *L, CallInfo *ci, int n);
void luaV_execute(lua_State *L, CallInfo *ci);
void luaD_tryfuncTM(lua_State *L, StkId func);
CallInfo *next_ci(lua_State *L);
void checkstackp(lua_State *L, int n, StkId func);