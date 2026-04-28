#include <limits.h>
#include <stddef.h>

typedef struct lua_State lua_State;

typedef struct mp_cur {
    const unsigned char *p;
    size_t left;
    int err;
} mp_cur;

enum {
    MP_CUR_ERROR_EOF = 1,
    MP_CUR_ERROR_BADFMT = 2
};

void mp_cur_init(mp_cur *c, const unsigned char *s, size_t len);
void mp_decode_to_lua_type(lua_State *L, mp_cur *c);
const char *luaL_checklstring(lua_State *L, int narg, size_t *len);
int luaL_error(lua_State *L, const char *fmt, ...);
void lua_pushinteger(lua_State *L, int n);
void lua_insert(lua_State *L, int idx);