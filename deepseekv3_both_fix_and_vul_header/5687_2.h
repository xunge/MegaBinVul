typedef struct lua_State {
  void *top;
} lua_State;

typedef struct Proto {
  int nups;
} Proto;

typedef struct Closure {
  struct {
    Proto *p;
    void **upvals;
  } l;
} Closure;

typedef struct ZIO {
  // minimal ZIO definition
} ZIO;

typedef struct Mbuffer {
  // minimal Mbuffer definition
} Mbuffer;

typedef struct Table {
  // minimal Table definition
} Table;

#define cast(t, exp) ((t)(exp))
#define LUA_SIGNATURE "\033Lua"

struct SParser {
  ZIO *z;
  Mbuffer buff;
  const char *name;
};

Table *gt(lua_State *L);
Table *hvalue(void *t);
int luaZ_lookahead(ZIO *z);
void luaC_checkGC(lua_State *L);
Proto *luaU_undump(lua_State *L, ZIO *z, Mbuffer *buff, const char *name);
Proto *luaY_parser(lua_State *L, ZIO *z, Mbuffer *buff, const char *name);
Closure *luaF_newLclosure(lua_State *L, int nups, Table *gt);
void *luaF_newupval(lua_State *L);
void setclvalue(lua_State *L, void *top, Closure *cl);
void incr_top(lua_State *L);