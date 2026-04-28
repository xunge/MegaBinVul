#include <stddef.h>

#define LUA_API extern
#define LUA_TLCL 1
#define LUA_TCCL 2

typedef struct lua_State lua_State;
typedef struct TValue *StkId;

struct TValue {
    int tt_;
    void *value;
};

struct CClosure {
    int nupvalues;
    void *upvalue[1];
};

typedef struct CClosure CClosure;

#define ttype(o) ((o)->tt_)
#define clCvalue(o) ((CClosure *)((o)->value))
#define api_check(L, cond, msg) if (!(cond)) return NULL

StkId index2addr(lua_State *L, int idx);
void **getupvalref(lua_State *L, int fidx, int n, ...);