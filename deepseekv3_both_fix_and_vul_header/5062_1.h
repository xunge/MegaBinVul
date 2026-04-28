#include <stddef.h>

#define LUA_API

typedef struct lua_State lua_State;
typedef struct UpVal UpVal;
typedef struct LClosure LClosure;

struct UpVal {
  int refcount;
  union {
    struct {
      int touched;
    } open;
  } u;
};

extern UpVal** getupvalref(lua_State *L, int fidx, int n, ...);
extern int upisopen(UpVal *uv);
extern void luaC_upvdeccount(lua_State *L, UpVal *uv);
extern void luaC_upvalbarrier(lua_State *L, UpVal *uv);