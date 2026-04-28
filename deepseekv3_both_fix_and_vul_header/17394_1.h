#include <string.h>
#include <ctype.h>

typedef struct {
    int endian;
} Header;

typedef struct lua_State lua_State;
typedef double lua_Number;

void defaultoptions(Header *h);
size_t optsize(lua_State *L, int opt, const char **fmt);
size_t gettoalign(size_t pos, Header *h, int opt, size_t size);
lua_Number getinteger(const char *data, int endian, int issigned, size_t size);
void correctbytes(char *b, size_t size, int endian);
void controloptions(lua_State *L, int opt, const char **fmt, Header *h);

const char *luaL_checkstring(lua_State *L, int narg);
const char *luaL_checklstring(lua_State *L, int narg, size_t *len);
long luaL_optinteger(lua_State *L, int narg, long def);
void luaL_argcheck(lua_State *L, int cond, int narg, const char *msg);
void luaL_checkstack(lua_State *L, int sz, const char *msg);
void lua_pushnumber(lua_State *L, lua_Number n);
int lua_isnumber(lua_State *L, int idx);
lua_Number lua_tonumber(lua_State *L, int idx);
void lua_pop(lua_State *L, int n);
void lua_pushlstring(lua_State *L, const char *s, size_t len);
void lua_pushinteger(lua_State *L, long n);
void luaL_error(lua_State *L, const char *fmt, ...);