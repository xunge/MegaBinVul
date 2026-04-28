#include <stddef.h>

typedef struct lua_State lua_State;

typedef struct mp_buf {
    /* Define the structure members as needed */
} mp_buf;

void lua_pushnil(lua_State *L);
int lua_next(lua_State *L, int index);
void lua_pop(lua_State *L, int n);
void lua_pushvalue(lua_State *L, int index);
void mp_encode_map(lua_State *L, mp_buf *buf, size_t len);
void mp_encode_lua_type(lua_State *L, mp_buf *buf, int level);