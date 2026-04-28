#include <stdarg.h>
#include <stdnoreturn.h>

#define l_noret noreturn

typedef struct lua_State lua_State;
typedef struct CallInfo CallInfo;
typedef struct Proto Proto;
typedef struct LClosure LClosure;

struct lua_State {
  CallInfo *ci;
  void *top;
};

struct CallInfo {
  LClosure *func;
};

struct LClosure {
  Proto *p;
};

struct Proto {
  const char *source;
};

l_noret void luaG_runerror(lua_State *L, const char *fmt, ...);
l_noret void luaG_errormsg(lua_State *L);
void luaC_checkGC(lua_State *L);
char *luaO_pushvfstring(lua_State *L, const char *fmt, va_list argp);
int isLua(CallInfo *ci);
void luaG_addinfo(lua_State *L, const char *msg, const char *src, int line);
void setobjs2s(lua_State *L, void *dest, void *src);
LClosure *ci_func(CallInfo *ci);
int getcurrentline(CallInfo *ci);